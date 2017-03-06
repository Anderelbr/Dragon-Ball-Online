//***********************************************************************************
//
//	File		:	NtlPacketEncoder.h
//
//	Begin		:	2007-01-27
//
//	Copyright	:	�� NTL-Inc Co., Ltd
//
//	Author		:	Hyun Woo, Koo   ( zeroera@ntl-inc.com )
//
//	Desc		:	
//
//***********************************************************************************

#pragma once


struct PACKETHEADER;
class CNtlPacket;
class CNtlPacketEncoder
{
public:

	CNtlPacketEncoder(void) {}

	virtual ~CNtlPacketEncoder(void) {}


public:

	virtual int				RxDecrypt(void * pvPacketHeader) { UNREFERENCED_PARAMETER( pvPacketHeader ); return NTL_SUCCESS; }

	virtual int				TxEncrypt(void * pvPacketHeader) { UNREFERENCED_PARAMETER( pvPacketHeader ); return NTL_SUCCESS; }

	virtual int				RxDecrypt(CNtlPacket& rPacket);

	virtual int				TxEncrypt(CNtlPacket& rPacket);

};
