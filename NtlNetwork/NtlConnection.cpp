//***********************************************************************************
//
//	File		:	NtlConnection.cpp
//
//	Begin		:	2005-12-19
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	Network Connection Class
//
//***********************************************************************************

#include "stdafx.h"
#include "NtlConnection.h"

#include "NtlNetwork.h"
#include "NtlAcceptor.h"
#include "NtlConnector.h"

#include "NtlLog.h"	
#include "NtlError.h"
#include "NtlThread.h"
#include "NtlPacketEncoder_TW.h"
#include "NtlPacketCommon.h"


//-----------------------------------------------------------------------------------
// TODO List
//-----------------------------------------------------------------------------------
// @ PushPacket�ÿ� SendBuffer�� Linear Size�� �˻��ϱ� ������ ���� ȸ���ÿ� �� ������
// �������� �� �� ���� �ִ�. ȯ��ť ����� ����Ͽ� ���� �� ��
// 
// @ PostRecv�� PostSend�ÿ� ����� ���� ���ۿ� �׿��ִ� ũ�⸸ŭ ���� Post�� �ϰ� �Ǵµ�
// �̴� kernel resource�� ���� �Һ��ϰ� �ȴ�. �ѹ��� �ۼ����� ũ�⸦ ���س��� ����ϵ��� ����.
// ���Ǻ��� ������ ���� �ϱ� ���ؼ��� session�� virtual �Լ��� �δ°͵� ����� �� ��
//-----------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
class CFunctionHelper
{
public:
	CFunctionHelper(const char * lpszFunctionName, void * pointer)
		:m_lpszFunctionName(lpszFunctionName), m_pointer(pointer)
	{ 
		//NTL_PRINT( PRINT_SYSTEM, "Session[%X]\t%s\tBegin\t%s", m_pointer, m_lpszFunctionName, CNtlThread::GetCurrentThread()->GetName() );
	}

	~CFunctionHelper()
	{
		//NTL_PRINT( PRINT_SYSTEM, "Session[%X]\t%s\tEnd\t%s", m_pointer, m_lpszFunctionName, CNtlThread::GetCurrentThread()->GetName() );
	}

public:

	const char * m_lpszFunctionName;

	void * m_pointer;
};

#define FUNCTION_BEGIN() CFunctionHelper __functionHelper(__FUNCTION__, this)
//-----------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------------
const DWORD CONNECTION_KEEP_ALIVE_TIME			= 5 * 1000; // ���� �ɼ� KEEP ALIVE �� ���
const DWORD CONNECTION_KEEP_ALIVE_INTERVAL		= 1 * 1000; // ���� �ɼ� KEEP ALIVE �� ���
//-----------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------
// connection STATUS string
//-----------------------------------------------------------------------------------
char * s_connection_status_string[CNtlConnection::MAX_STATUS] = 
{
	"STATUS_INIT",
	"STATUS_CREATE",
	"STATUS_ACCEPT",
	"STATUS_CONNECT",
	"STATUS_ACTIVE",
	"STATUS_CLOSE",
	"STATUS_SHUTDOWN",
	"STATUS_DESTROY",
};


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
const char * CNtlConnection::GetStatusString()
{
	if( m_status >= MAX_STATUS )
		return "Unknown STATUS";

	return s_connection_status_string[ m_status ];
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
CNtlConnection::CNtlConnection()
{
	FUNCTION_BEGIN();

	Init();
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
CNtlConnection::~CNtlConnection()
{
	FUNCTION_BEGIN();

	Destroy();
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
void CNtlConnection::Init()
{
	FUNCTION_BEGIN();

	m_status = STATUS_INIT;

	m_pNetworkRef	= NULL;
	m_pAcceptorRef	= NULL;
	m_pConnectorRef	= NULL;
	m_dwIoPostCount = 0;

	m_recvBuffer.Clear();
	m_sendBuffer.Clear();
	m_recvContext.Clear();
	m_sendContext.Clear();
	m_recvContext.param = this;
	m_sendContext.param = this;
	m_pPacketEncoder = NULL;

	m_dwControlFlag = 0;
	m_dwAliveTime = 0;

	m_bSending = false;
	m_bDisconnect = false;
	m_bConnected = false;

	m_dwConnectTime = 0;
	m_dwBytesRecvSize = 0;
	m_dwBytesSendSize = 0;
	m_dwBytesRecvSizeMax = 0;
	m_dwBytesSendSizeMax = 0;
	m_dwPacketRecvCount = 0;
	m_dwPacketSendCount = 0;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Acceptor TH, Connector TH
//-----------------------------------------------------------------------------------
int CNtlConnection::Create(CNtlNetwork * pNetwork)
{
	FUNCTION_BEGIN();


	if( IsStatus( STATUS_CREATE ) )
	{
		NTL_LOG_ASSERT("true == IsStatus( STATUS_CREATE )");
		return NTL_ERR_NET_CONNECTION_STATUS_WRONG;
	}


	if( NULL == pNetwork )
	{
		NTL_LOG_ASSERT("NULL == pNetwork");
		return NTL_ERR_SYS_INPUT_PARAMETER_WRONG;
	}


	if( NULL != m_pNetworkRef )
	{
		NTL_LOG_ASSERT("NULL != m_pNetworkRef, m_pNetworkRef = %016x", m_pNetworkRef);
		return NTL_ERR_SYS_OBJECT_ALREADY_CREATED;
	}


	if( false == m_recvBuffer.Create( GetMaxRecvPacketCount(), GetMaxRecvPacketSize() ) )
	{
		return NTL_ERR_SYS_MEMORY_ALLOC_FAIL;
	}


	if( false == m_sendBuffer.Create( GetMaxSendPacketCount(), GetMaxRecvPacketSize() ) )
	{
		return NTL_ERR_SYS_MEMORY_ALLOC_FAIL;
	}


	int rc = m_socket.Create( CNtlSocket::eSOCKET_TCP );
	if( NTL_SUCCESS != rc )
	{
		return rc;
	}


	rc = m_socket.SetKeepAlive( CONNECTION_KEEP_ALIVE_TIME, CONNECTION_KEEP_ALIVE_INTERVAL );
	if( NTL_SUCCESS != rc )
	{
		return rc;
	}


	rc = m_socket.SetLinger( true, 0 );
	if( NTL_SUCCESS != rc )
	{
		return rc;
	}

#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
	m_pPacketEncoder = NULL;
#else
	m_pPacketEncoder = GetPacketEncoder();
#endif


	m_pNetworkRef = pNetwork;


	SetStatus( STATUS_CREATE );

	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Dispatcher TH, Application TH, Acceptor TH, Connector TH, 
//-----------------------------------------------------------------------------------
void CNtlConnection::Destroy()
{
	FUNCTION_BEGIN();

	if( false == ExchangeStatus( STATUS_DESTROY, false, STATUS_DESTROY ) )
	{
		NTL_LOG_ASSERT( "Status( STATUS_DESTROY )" );
		return;
	}


	m_socket.Shutdown( SD_BOTH );

	m_socket.Close();


	if( m_pAcceptorRef )
	{
		m_pAcceptorRef->OnDisconnected( m_bConnected );
	}

	if( m_pConnectorRef )
	{
		m_pConnectorRef->OnDisconnected( m_bConnected );
	}
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH, Application TH ( PostRecv/PostSend/IOCP transfered 0 )
//-----------------------------------------------------------------------------------
void CNtlConnection::Close(bool bForce)
{
	UNREFERENCED_PARAMETER( bForce ); 

	FUNCTION_BEGIN();

	if( false == ExchangeStatus( STATUS_CLOSE, false, STATUS_CLOSE ) )
	{
		return;
	}

	// �� �����δ� ���� �Ұ��ϴ�. Processor�� ���� �޸𸮿��� �Ҹ��
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Application TH, Monitor TH
//-----------------------------------------------------------------------------------
int CNtlConnection::Disconnect(bool bGraceful)
{
	FUNCTION_BEGIN();

	if( bGraceful )
	{
		m_socket.Shutdown( SD_SEND );
	}
	else
	{
		m_socket.Shutdown( SD_BOTH );
		m_socket.Close();
	}

	m_bDisconnect = true;


	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Application TH, Monitor TH
//-----------------------------------------------------------------------------------
int CNtlConnection::Shutdown()
{
	FUNCTION_BEGIN();


	SetStatus( STATUS_SHUTDOWN );


	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( IOCP )
//-----------------------------------------------------------------------------------
int CNtlConnection::CompleteIO(sIOCONTEXT * pIOContext, DWORD dwParam)
{
	switch( pIOContext->iomode )
	{
	case IOMODE_ACCEPT:
		return CompleteAccept( dwParam );

	case IOMODE_CONNECT:
		return CompleteConnect( dwParam );

	case IOMODE_RECV:
		return CompleteRecv( dwParam );

	case IOMODE_SEND:
		return CompleteSend( dwParam );

	default:
		return NTL_ERR_NET_INVALID_COMPLETE_IO_MODE;
	}
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( CompleteRecv, CompleteAccept )
//-----------------------------------------------------------------------------------
int CNtlConnection::PostRecv()
{
	FUNCTION_BEGIN();

	if( false == IsStatus( STATUS_ACTIVE ) )
	{
		Disconnect( false );
		return NTL_SUCCESS;
		//return NTL_ERR_NET_CONNECTION_STATUS_WRONG;
	}


	DWORD dwFlags = 0;
	DWORD dwTransferedBytes	= 0;

	m_recvContext.Reset();
	m_recvContext.iomode = IOMODE_RECV;
	m_recvContext.wsabuf.buf = (char*) m_recvBuffer.GetQueuePushPtr();
	m_recvContext.wsabuf.len = m_recvBuffer.GetPushAvailableSize();


	//  [1/20/2007 zeroera] : ���� : recv buffer overflow �̰��� �ɸ��� ������ ���� ����� ������ ���� ��������� Fake Packet�� ������ Ŭ���̾�Ʈ�� ����Ͽ� ������ ��ó�� �� ��
	if( m_recvBuffer.GetPushAvailableSize() <= 0 )
	{
		Disconnect( false );

		NTL_LOGDL( LOG_NETWORK, "Session[%X] m_recvBuffer.GetPushAvailableSize() <= 0, m_recvBuffer.GetPushAvailableSize() = %d", this, m_recvBuffer.GetPushAvailableSize() );
		return NTL_ERR_NET_SESSION_RECV_BUFFER_OVERFLOW;
	}



	IncreasePostIoCount();

	int rc = m_socket.RecvEx(	&m_recvContext.wsabuf,
		1,
		&dwTransferedBytes,
		&dwFlags,
		&m_recvContext);

	if( NTL_SUCCESS != rc )
	{
		DecreasePostIoCount();

		NTL_LOGDL( LOG_NETWORK, "Session[%X] RecvEx Function Failed (%d)%s", this, rc, NtlGetErrorMessage( rc ) );
		return rc;
	}

	//NTL_PRINT( PRINT_SYSTEM, "Session[%X]\tPostRecv Complete Success recvBufferSize[%d]", this, m_recvBuffer.GetCurSize() );


	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by App TH, Worker TH ( CompleteSend, PushPacket )
//-----------------------------------------------------------------------------------
int CNtlConnection::PostSend()
{
	FUNCTION_BEGIN();

	if( false == IsStatus( STATUS_ACTIVE ) )
	{
		Disconnect( false );
		return NTL_SUCCESS;
		//return NTL_ERR_NET_CONNECTION_STATUS_WRONG;
	}


	DWORD dwFlags		= 0;
	DWORD dwSendBytes	= 0;

	m_sendContext.Reset();
	m_sendContext.iomode = IOMODE_SEND;
	m_sendContext.wsabuf.buf = (char*) m_sendBuffer.GetQueuePopPtr();

#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
	bool bIsIf = false;
#endif

	if( m_sendBuffer.GetPopPos() + m_sendBuffer.GetCurSize() >= m_sendBuffer.GetQueueSize() )
	{

#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
		bIsIf = true;
#endif

		//  [9/13/2007 zeroera] : ���� : ���� ������ ���� ������ �κ�
		m_sendContext.wsabuf.len = m_sendBuffer.GetQueueSize() - m_sendBuffer.GetPopPos();

		//if( m_sendBuffer.GetQueueSize() <= m_sendBuffer.GetPopPos() )
		//{
		//	NTL_LOG_ASSERT("m_sendBuffer.GetQueueSize() <= m_sendBuffer.GetPopPos(), m_sendBuffer.GetQueueSize() = %d, m_sendBuffer.GetPopPos() = %d", m_sendBuffer.GetQueueSize(), m_sendBuffer.GetPopPos());
		//	Disconnect( false );
		//	return NTL_SUCCESS;
		//}
	}
	else
	{
		m_sendContext.wsabuf.len = m_sendBuffer.GetCurSize();

		//if( m_sendBuffer.GetCurSize() <= 0 )
		//{
		//	NTL_LOG_ASSERT("m_sendBuffer.GetCurSize() <= 0, m_sendBuffer.GetCurSize() = %d", m_sendBuffer.GetCurSize());
		//	Disconnect( false );
		//	return NTL_SUCCESS;
		//}
	}


	IncreasePostIoCount();

	int rc = m_socket.SendEx(	&m_sendContext.wsabuf,
							 1,
							 &dwSendBytes,
							 dwFlags,
							 &m_sendContext);

	if( NTL_SUCCESS != rc )
	{
		DecreasePostIoCount();

		NTL_LOGDL( LOG_NETWORK, "Session[%X] SendEx Function Failed: (%d)%s", this, rc, NtlGetErrorMessage( rc ) );
		return rc;
	}

#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
	m_cConsolLog.WriteBotSystemLog( reinterpret_cast< void * >( m_sendContext.wsabuf.buf )
		, m_sendContext.wsabuf.len
		, bIsIf 
		, &m_sendBuffer
		, m_nCharacterPCID);
#endif//__SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__

	//NTL_PRINT( PRINT_SYSTEM, "Session[%X]\tPostSend Complete SendBufferSize[%d]", this, m_sendBuffer.GetCurSize() );

	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Acceptor TH ( Run )
//-----------------------------------------------------------------------------------
int CNtlConnection::PostAccept(CNtlAcceptor* pAcceptor)
{
	FUNCTION_BEGIN();

	if( NULL == pAcceptor )
	{
		return NTL_ERR_SYS_INPUT_PARAMETER_WRONG;
	}


	SetStatus( STATUS_ACCEPT );


	m_pAcceptorRef = pAcceptor;


	DWORD dwBytes = 0;

	m_recvContext.Reset();
	m_recvContext.iomode = IOMODE_ACCEPT;
	m_recvContext.wsabuf.buf = (char*) m_recvBuffer.GetQueuePushPtr();
	m_recvContext.wsabuf.len = 0;

	IncreasePostIoCount();
	m_pAcceptorRef->IncreaseCurAcceptingCount();


	int rc = pAcceptor->GetListenSocket().AcceptEx(	m_socket,
		m_recvContext.wsabuf.buf,
		0,
		sizeof(SOCKADDR_IN) + 16,
		sizeof(SOCKADDR_IN) + 16,
		&dwBytes,
		&m_recvContext );

	if( NTL_SUCCESS != rc )
	{
		DecreasePostIoCount();
		m_pAcceptorRef->DecreaseCurAcceptingCount();

		NTL_LOGDL( LOG_NETWORK, "Session[%X] AcceptEx Function Failed: (%d)%s", this, rc, NtlGetErrorMessage( rc ) );
		return rc;
	}


	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Connector TH ( Run )
//-----------------------------------------------------------------------------------
int CNtlConnection::PostConnect(CNtlConnector* pConnector)
{
	FUNCTION_BEGIN();


	if( NULL == pConnector )
	{
		return NTL_ERR_SYS_INPUT_PARAMETER_WRONG;
	}


	SetStatus( STATUS_CONNECT );


	m_pConnectorRef = pConnector;


#if !defined( __USE_CONNECTEX__ )
	int rc = m_socket.Connect( pConnector->GetConnectAddr() );
	if( NTL_SUCCESS != rc )
	{
		//NTL_LOGDL( LOG_NETWORK, "Session[%X] Connect Function Failed: (%d)%s", this, rc, NtlGetErrorMessage( rc ) );
		return rc;
	}

#else

	DWORD dwBytes = 0;

	m_recvContext.Reset();
	m_recvContext.iomode = IOMODE_CONNECT;
	m_recvContext.wsabuf.buf	= (char*) m_sendBuffer.GetQueuePushPtr();
	m_recvContext.wsabuf.len	= 0;
	IncreasePostIoCount();

	int rc = m_socket.ConnectEx(	pConnector->GetConnectAddr(),
		sizeof(struct sockaddr_in),
		m_recvContext.wsabuf.buf,
		0,
		&dwBytes,
		&m_sendContext );

	if( NTL_SUCCESS != rc )
	{
		DecreasePostIoCount();
		return rc;
	}

#endif

	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( IOCP )
//-----------------------------------------------------------------------------------
int CNtlConnection::CompleteRecv(DWORD dwTransferedBytes)
{
	FUNCTION_BEGIN();


	// Remote close
	if( 0 == dwTransferedBytes )
	{
		return NTL_ERR_NET_SESSION_CLOSED;
	}


	IncreaseBytesRecv( dwTransferedBytes );


	if( false == m_recvBuffer.IncreasePushPos( dwTransferedBytes ) ) //-> ����ȭ�ʿ�
	{
		NTL_LOGDL( LOG_NETWORK, "Session[%X] Recv Buffer OverFlow : BufferCur[%d] BufferMax[%d] TransferedBytes[%u]", this, m_recvBuffer.GetCurSize(), m_recvBuffer.GetQueueSize(), dwTransferedBytes );
		return NTL_ERR_NET_SESSION_RECV_BUFFER_OVERFLOW;
	}

	int rc = NTL_SUCCESS;
	WORD wPacketLength = 0;

#if 0
	while( MakeSureCompletedPacket( &m_recvBuffer, &wPacketLength, m_pPacketEncoder ) )
	{
		if( true != IsValidPacket( m_recvBuffer.GetQueueWorkPtr(), wPacketLength ) )
		{
			NTL_LOG_ASSERT("true != IsValidPacket()");
		}

		CNtlPacket packet;

		packet.Attach( m_recvBuffer.GetQueueWorkPtr(), wPacketLength );

		m_recvBuffer.IncreaseWorkPos( packet.GetUsedSize() );

		if( m_pPacketEncoder )
		{
			rc = m_pPacketEncoder->RxDecrypt( packet );
			if( NTL_SUCCESS != rc )
			{
				return rc;
			}
		}

		//  [9/10/2007 zeroera] : ���� : sequence���� 0 ~ 255
		BYTE byValidSequence = (BYTE) ( m_dwPacketRecvCount & PACKET_MAX_SEQUENCE );
		if( false == HasValidSequence( packet.GetPacketHeader(), byValidSequence ) )
		{
			return NTL_ERR_NET_PACKET_SEQUENCE_FAIL;
		}


		IncreasePacketRecv();

		//NTL_PRINT(PRINT_SYSTEM, "Session[%X]\tCompleteRecv Complete recvBufferSize[%d], TotalRecvBytes[%u]", this, m_recvBuffer.GetCurSize(), m_dwTotalRecvSize );

		m_pNetworkRef->PostNetEventMessage( (WPARAM)NETEVENT_RECV, (LPARAM)this );	
	}
	
#else

	CNtlPacket packet;
	do 
	{
		rc = MakeSureCompletedPacket( &m_recvBuffer, &wPacketLength, m_pPacketEncoder );
		if( NTL_SUCCESS != rc )
		{
			if( NTL_ERR_NET_PACKET_PENDING_HEADER == rc || NTL_ERR_NET_PACKET_PENDING_DATA == rc )
			{
				break;
			}
			
			NTL_LOGDL( LOG_NETWORK, "Session[%X] MakeSureCompletedPacket Error[%d:%s]", this, rc, NtlGetErrorMessage(rc) );
			return rc;
		}

		if( true != IsValidPacket( m_recvBuffer.GetQueueWorkPtr(), wPacketLength ) )
		{
			NTL_LOG_ASSERT("true != IsValidPacket()");
		}

		packet.AttachData( m_recvBuffer.GetQueueWorkPtr(), wPacketLength );

		m_recvBuffer.IncreaseWorkPos( packet.GetUsedSize() );

		#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
		#else
			if( m_pPacketEncoder )
			{
				rc = m_pPacketEncoder->RxDecrypt( packet );
				if( NTL_SUCCESS != rc )
				{
					NTL_LOGDL( LOG_NETWORK, "Session[%X] RxDecrypt Error[%d:%s]", this, rc, NtlGetErrorMessage(rc) );
					return rc;
				}
			}
		#endif

		//  [9/10/2007 zeroera] : ���� : sequence���� 0 ~ 255
		BYTE byValidSequence = (BYTE) ( m_dwPacketRecvCount & PACKET_MAX_SEQUENCE );
		if( false == HasValidSequence( packet.GetPacketHeader(), byValidSequence ) )
		{
			NTL_LOGDL( LOG_NETWORK, "Session[%X] Sequence Error[%d:%s] PacketSEQ[%u] CurrentSEQ[%u]", this, rc, NtlGetErrorMessage(rc), GetSequence( m_recvBuffer.GetQueueWorkPtr() ), byValidSequence );
			return NTL_ERR_NET_PACKET_SEQUENCE_FAIL;
		}


		IncreasePacketRecv();

		//NTL_PRINT(PRINT_SYSTEM, "Session[%X]\tCompleteRecv Complete recvBufferSize[%d], TotalRecvBytes[%u]", this, m_recvBuffer.GetCurSize(), m_dwTotalRecvSize );

		m_pNetworkRef->PostNetEventMessage( (WPARAM)NETEVENT_RECV, (LPARAM)this );	


	} while( NTL_SUCCESS == rc );

#endif


	rc = PostRecv();
	if( NTL_SUCCESS != rc )
	{
		return rc;
	}

	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( IOCP )
//-----------------------------------------------------------------------------------
int CNtlConnection::CompleteSend(DWORD dwTransferedBytes)
{
	UNREFERENCED_PARAMETER( dwTransferedBytes );

	FUNCTION_BEGIN();


	IncreaseBytesSend( dwTransferedBytes );


	m_mutexSend.Lock();

	m_sendBuffer.IncreasePopPos( dwTransferedBytes );


	int rc = 0;
	if( IsSetControlFlag( CONTROL_FLAG_USE_SEND_QUEUE ) )
	{
		CNtlPacket * pSendPacket = m_sendQueue.PeekPacket();
		while( pSendPacket )
		{
			if( m_sendBuffer.GetPushAvailableSize() <= pSendPacket->GetUsedSize() )
			{
				break;
			}

			BYTE bySequence = (BYTE) ( m_dwPacketSendCount & PACKET_MAX_SEQUENCE );
			SetSequence( pSendPacket->GetPacketHeader(), bySequence );

			#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
			#else
		/*	if( m_pPacketEncoder )
			{
				rc = m_pPacketEncoder->TxEncrypt( *pSendPacket );
				if( NTL_SUCCESS != rc )
				{
					m_mutexSend.Unlock();

					NTL_LOGDL( LOG_NETWORK, "Session[%X] TxEncrypt Error[%d:%s]", this, rc, NtlGetErrorMessage(rc) );
					return NTL_ERR_NET_PACKET_ENCRYPT_FAIL;
				}
			}*/
			#endif

			memcpy( m_sendBuffer.GetQueuePushPtr(), pSendPacket->GetPacketBuffer(), pSendPacket->GetUsedSize() );
			m_sendBuffer.IncreasePushPos( pSendPacket->GetUsedSize() );
			IncreasePacketSend();

			m_sendQueue.PopPacket();
			SAFE_DELETE( pSendPacket );

			pSendPacket = m_sendQueue.PeekPacket();
		}
	}


	if( m_sendBuffer.GetCurSize() )
	{
		rc = PostSend();
		if( NTL_SUCCESS != rc )
		{
			m_bSending = false;
			m_mutexSend.Unlock();
			//  [1/20/2007 zeroera] : ���� : Send�� ���� Close ����� ����. TH1�� Recv �߿� TH2 �� Send �Ͽ� Close�ϰ� �Ǹ� ������ �߻� �� ������ ����
			//return rc;
			Disconnect( false );

			NTL_LOGDL( LOG_NETWORK, "Session[%X] PostSend Error[%d:%s]", this, rc, NtlGetErrorMessage(rc) );
			return NTL_SUCCESS;
		}
	}
	else
	{
		m_bSending = false;
	}


	m_mutexSend.Unlock();

	//NTL_PRINT(PRINT_SYSTEM, "Session[%X]\tCompleteSend Complete SendBufferSize[%d] TotalSendBytes[%u]", this, m_sendBuffer.GetCurSize(), m_dwTotalSendSize );

	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( IOCP )
//-----------------------------------------------------------------------------------
int CNtlConnection::CompleteAccept(DWORD dwTransferedBytes)
{
	FUNCTION_BEGIN();

	UNREFERENCED_PARAMETER( dwTransferedBytes );

	SOCKADDR_IN * pLocalAddr = NULL;
	SOCKADDR_IN * pRemoteAddr = NULL;
	int nLocalAddrLen = 0;
	int nRemoteAddrLen = 0;

	m_socket.GetAcceptExSockaddrs(	m_recvContext.wsabuf.buf,
									0,
									sizeof(SOCKADDR_IN) + 16,
									sizeof(SOCKADDR_IN) + 16,
									(SOCKADDR**) &pLocalAddr,
									&nLocalAddrLen,
									(SOCKADDR**) &pRemoteAddr,
									&nRemoteAddrLen);

	SetAddress( pLocalAddr, pRemoteAddr );
	ZeroMemory( m_recvContext.wsabuf.buf, sizeof(SOCKADDR_IN) + 16 + sizeof(SOCKADDR_IN) + 16 );
	m_bConnected = true;

	int rc = m_pNetworkRef->Associate( this, true );
	if( NTL_SUCCESS != rc )
	{
		NTL_LOGDL( LOG_NETWORK, "Session[%X] Associate Error[%d:%s]", this, rc, NtlGetErrorMessage(rc) );
		return rc;
	}


	SetStatus( STATUS_ACTIVE );
	m_dwConnectTime = GetTickCount();


	m_pAcceptorRef->OnAccepted();


	m_pNetworkRef->PostNetEventMessage( (WPARAM)NETEVENT_ACCEPT, (LPARAM)this );


	rc = PostRecv();
	if( NTL_SUCCESS != rc )
	{
		return rc;
	}


	//NTL_PRINT(PRINT_SYSTEM, "Session[%X]\tCompleteAccept Called Local[%s:%u] Remote[%s:%u]", pSession, GetLocalIP(), GetLocalPort(), GetRemoteIP(), GetRemotePort());


	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( IOCP )
//-----------------------------------------------------------------------------------
int CNtlConnection::CompleteConnect(DWORD dwTransferedBytes)
{
	FUNCTION_BEGIN();

	UNREFERENCED_PARAMETER( dwTransferedBytes );

	m_socket.GetPeerAddr( m_remoteAddr );
	m_socket.GetLocalAddr( m_localAddr );
	m_bConnected = true;

	int rc = m_pNetworkRef->Associate( this, true );
	if( NTL_SUCCESS != rc )
	{
		NTL_LOGDL( LOG_NETWORK, "Session[%X] CompleteConnect Error[%d:%s]", this, rc, NtlGetErrorMessage(rc) );
		return rc;
	}


	SetStatus( STATUS_ACTIVE );
	m_dwConnectTime = GetTickCount();


	m_pConnectorRef->OnConnected();


	m_pNetworkRef->PostNetEventMessage( (WPARAM)NETEVENT_CONNECT, (LPARAM)this );	


	rc = PostRecv();
	if( NTL_SUCCESS != rc )
	{
		return rc;
	}



	//NTL_PRINT(PRINT_SYSTEM, "Session[%X]\tCompleteConnect Called Local[%s:%u] Remote[%s:%u]", pSession, GetLocalIP(), GetLocalPort(),	GetRemoteIP(), GetRemotePort() );


	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( CompleteAccept )
//-----------------------------------------------------------------------------------
void CNtlConnection::SetAddress(SOCKADDR_IN * pLocalAddr, SOCKADDR_IN * pRemoteAddr)
{
	FUNCTION_BEGIN();


	m_localAddr	= *pLocalAddr;
	m_remoteAddr = *pRemoteAddr;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Worker TH ( CompleteRecv )
//-----------------------------------------------------------------------------------
bool CNtlConnection::PopPacket(CNtlPacket * pPacket)
{
	FUNCTION_BEGIN();

	if( NULL == pPacket )
	{
		NTL_LOG_ASSERT("NULL == pPacket");
		return false;
	}

#if 0
	WORD wPacketLength = 0;
	if( false == MakeSureCompletedPacket( &m_recvBuffer, &wPacketLength ) )
	{
		return false;
	}
	
	pPacket->Attach( m_recvBuffer.GetQueueWorkPtr(), wPacketLength );


	if( false == pPacket->IsValidPacket() )
	{
		return false;
	}


	m_recvBuffer.IncreaseWorkPos( pPacket->GetUsedSize() );

#else

	int nPacketLen = GetPacketLen( m_recvBuffer.GetQueuePopPtr() );

	pPacket->AttachData( m_recvBuffer.GetQueuePopPtr(), (WORD) (GetHeaderSize() + nPacketLen) );

	if( false == pPacket->IsValidPacket() )
	{
		return false;
	}


#endif


	return true;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool CNtlConnection::IsValidPacket(void * pvPacketHeader, WORD wPacketLength)
{
	if (GetHeaderSize() > wPacketLength)
	{
		return false;
	}

	CNtlPacket packet;
	packet.AttachData((BYTE*)pvPacketHeader, wPacketLength);

	return packet.IsValidPacket();
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
BYTE CNtlConnection::GetSequence(void * pvPacketHeader)
{
	PACKETHEADER* pPacketHeader = (PACKETHEADER*)pvPacketHeader;

	//return pPacketHeader->bySequence;
	return 0;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by App TH, Worker TH ( Send )
//-----------------------------------------------------------------------------------
int CNtlConnection::PushPacket(CNtlPacket * pPacket)
{
	FUNCTION_BEGIN();


	if( false == IsStatus( STATUS_ACTIVE ) )
	{
		return NTL_ERR_NET_CONNECTION_STATUS_WRONG;
	}


	if( false == pPacket->IsValidPacket() )
	{
		return NTL_ERR_NET_PACKET_INVALID;
	}

	m_mutexSend.Lock(); // ������ ������ ����ȭ�� ������ [5/30/2008 SGpro]

	if( pPacket->GetPacketLen() > GetMaxSendPacketSize() )
	{
		m_mutexSend.Unlock();
		return NTL_ERR_NET_PACKET_EXCEED_ALLOWED_SIZE;
	}

	///Needed for Packet names. 

	/*sNTLPACKETHEADER * pHeader = (sNTLPACKETHEADER *)pPacket->GetPacketData();
	printf("~~~ opcode %i sent ~~~ \n", pHeader->wOpCode);
	printf("~~~ opcode length %d \n", pPacket->GetPacketLen());
	printf("~~~ opcode size %i ~~~ \n", pPacket->GetPacketDataSize());
	printf("~~~ opcode Headersize %i ~~~ \n", pPacket->GetHeaderSize());*/

	if( m_sendBuffer.GetPushAvailableSize() <= pPacket->GetUsedSize() )
	{
		if( false == IsSetControlFlag( CONTROL_FLAG_USE_SEND_QUEUE ) )
		{
			m_mutexSend.Unlock();
			return NTL_ERR_NET_SESSION_SEND_BUFFER_OVERFLOW;
		}
		else 
		{
			CNtlPacket * pQueuedPacket = new CNtlPacket( *pPacket );
			if( NULL == pQueuedPacket )
			{
				m_mutexSend.Unlock();
				return NTL_ERR_SYS_MEMORY_ALLOC_FAIL;
			}

			if( false == m_sendQueue.PushPacket( pQueuedPacket ) )
			{
				SAFE_DELETE( pQueuedPacket );

				m_mutexSend.Unlock();
				return NTL_ERR_NET_SESSION_SEND_BUFFER_OVERFLOW;
			}

			m_mutexSend.Unlock();
			return NTL_SUCCESS;
		}
	}

	//m_mutexSend.Lock(); //���⿡ �θ� ����ȭ�� ������ [5/30/2008 SGpro]

	memcpy( m_sendBuffer.GetQueuePushPtr(), pPacket->GetPacketBuffer(), pPacket->GetUsedSize() );

	//  [9/10/2007 zeroera] : ���� : ȿ������ ���� ��Ŷ ���ۿ� �ִ� ����Ÿ�� ������ ��ȣȭ �Ѵ�
	CNtlPacket sendPacket( m_sendBuffer.GetQueuePushPtr() );
	BYTE bySequence = (BYTE) ( m_dwPacketSendCount & PACKET_MAX_SEQUENCE );
	SetSequence( sendPacket.GetPacketHeader(), bySequence );

	int rc = NTL_SUCCESS;

#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
#else
	if( m_pPacketEncoder )
	{
		rc = m_pPacketEncoder->TxEncrypt( sendPacket );
		if( NTL_SUCCESS != rc )
		{
			m_mutexSend.Unlock();
			return NTL_ERR_NET_PACKET_ENCRYPT_FAIL;
		}
	}
#endif

	m_sendBuffer.IncreasePushPos( pPacket->GetUsedSize() );
	IncreasePacketSend();


	if( false == m_bSending )
	{
		rc = PostSend();
		if( NTL_SUCCESS != rc )
		{
			m_mutexSend.Unlock();
			return rc;
		}

		m_bSending = true;
	}

	m_mutexSend.Unlock();


	return NTL_SUCCESS;
}

//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by App TH, Worker TH ( Send )
//-----------------------------------------------------------------------------------
int CNtlConnection::PushHandshakePacket(CNtlPacket * pPacket)
{
	FUNCTION_BEGIN();
	CNtlPacketEncoder_TW encoder;

	if (false == IsStatus(STATUS_ACTIVE))
	{
		return NTL_ERR_NET_CONNECTION_STATUS_WRONG;
	}

	if (false == pPacket->IsValidPacket())
	{
		return NTL_ERR_NET_PACKET_INVALID;
	}

	m_mutexSend.Lock(); // ������ ������ ����ȭ�� ������ [5/30/2008 SGpro]

	if (pPacket->GetPacketLen() > GetMaxSendPacketSize())
	{
		m_mutexSend.Unlock();
		return NTL_ERR_NET_PACKET_EXCEED_ALLOWED_SIZE;
	}

	if (m_sendBuffer.GetPushAvailableSize() <= pPacket->GetUsedSize())
	{
		if (false == IsSetControlFlag(CONTROL_FLAG_USE_SEND_QUEUE))
		{
			m_mutexSend.Unlock();
			return NTL_ERR_NET_SESSION_SEND_BUFFER_OVERFLOW;
		}
		else
		{
			CNtlPacket * pQueuedPacket = new CNtlPacket(*pPacket);
			if (NULL == pQueuedPacket)
			{
				m_mutexSend.Unlock();
				return NTL_ERR_SYS_MEMORY_ALLOC_FAIL;
			}

			if (false == m_sendQueue.PushPacket(pQueuedPacket))
			{
				SAFE_DELETE(pQueuedPacket);

				m_mutexSend.Unlock();
				return NTL_ERR_NET_SESSION_SEND_BUFFER_OVERFLOW;
			}

			m_mutexSend.Unlock();
			return NTL_SUCCESS;
		}
	}

	//m_mutexSend.Lock(); //���⿡ �θ� ����ȭ�� ������ [5/30/2008 SGpro]

	memcpy(m_sendBuffer.GetQueuePushPtr(), pPacket->GetPacketBuffer(), pPacket->GetUsedSize());

	//  [9/10/2007 zeroera] : ���� : ȿ������ ���� ��Ŷ ���ۿ� �ִ� ����Ÿ�� ������ ��ȣȭ �Ѵ�
	CNtlPacket sendPacket(m_sendBuffer.GetQueuePushPtr());
	BYTE bySequence = (BYTE)(m_dwPacketSendCount & PACKET_MAX_SEQUENCE);
	//SetSequence(sendPacket.GetPacketHeader(), bySequence);

	int rc = NTL_SUCCESS;

#if __SGPRO_BOTSYSTEM_SENDANDRECVTESTCODE__
#else
	/*if (m_pPacketEncoder)
	{
		rc = m_pPacketEncoder->TxEncrypt(sendPacket);
		if (NTL_SUCCESS != rc)
		{
			m_mutexSend.Unlock();
			return NTL_ERR_NET_PACKET_ENCRYPT_FAIL;
		}
	}*/
#endif

	m_sendBuffer.IncreasePushPos(pPacket->GetUsedSize());
	IncreasePacketSend();


	if (false == m_bSending)
	{
		rc = PostSend();
		if (NTL_SUCCESS != rc)
		{
			m_mutexSend.Unlock();
			return rc;
		}

		m_bSending = true;
	}

	m_mutexSend.Unlock();


	return NTL_SUCCESS;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
// Called by Monitor TH ( Valid Check )
//-----------------------------------------------------------------------------------
bool CNtlConnection::ValidCheck(DWORD dwTickDiff)
{
	if( IsSetControlFlag( CONTROL_FLAG_CHECK_ALIVE ) )
	{
		m_dwAliveTime += dwTickDiff;

		if( m_dwAliveTime >= GetAliveCheckTime() )
		{
			return false;
		}
	}

	return true;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool CNtlConnection::IsShutdownable()
{
	if( IsStatus( STATUS_CLOSE ) )
	{
		if( 0 == InterlockedCompareExchange( (LONG*)&m_dwIoPostCount, 0, 0 )  )
		{
			return true;
		}
	}

	return false;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool CNtlConnection::GetAddressInfo(CNtlString * pString, WORD * pPort, bool bRemote /* = true */)
{
	if( bRemote )
	{
		pString->GetString().assign( GetRemoteAddr().GetDottedAddr() );
		*pPort = GetRemoteAddr().GetPort();
	}
	else
	{
		pString->GetString().assign( GetLocalAddr().GetDottedAddr() );
		*pPort = GetLocalAddr().GetPort();
	}

	return true;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
int CNtlConnection::GetPacketLen(BYTE* pHeaderPointer)
{	
	PACKETHEADER* pHeader = (PACKETHEADER*)pHeaderPointer;
	return pHeader->wPacketLen;	
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
void CNtlConnection::SetSequence(void* pvPacketHeader, BYTE bySequence)
{
	PACKETHEADER* pPacketHeader = (PACKETHEADER*)pvPacketHeader;

	//pPacketHeader->bySequence = bySequence;
}


//-----------------------------------------------------------------------------------
//		Purpose	:
//		Return	:
//-----------------------------------------------------------------------------------
bool CNtlConnection::HasValidSequence(void* pvPacketHeader, BYTE bySequence)
{
	PACKETHEADER* pPacketHeader = (PACKETHEADER*)pvPacketHeader;

	//if (bySequence == pPacketHeader->bySequence)
	//{
		return true;
	//}
	//else
	//{
	//	return false;
	//}
}




