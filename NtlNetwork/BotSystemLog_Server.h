#pragma once
//***********************************************************************************
//
//	File		:	BotSystemLog_Server.h
//
//	Begin		:	2008-03-18 ���� 11:03:20
//
//	Copyright	:	�� NTL-Inc Co. Ltd
//
//	strAuthor	:	Seung Goon. Chi   ( sgpro@ntl-inc.com )
//
//	strDesc		:	
//
//***********************************************************************************

//-- include ------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <fstream>
//-- define -------------------------------------------------------------------------
class CNtlNetBuffer;
//-----------------------------------------------------------------------------------

class CBotSystemLog_Server
{

public:
	typedef std::basic_string< TCHAR > tstring;

public:
	CBotSystemLog_Server();
	~CBotSystemLog_Server();

public:
	void Create( char* pszFileName );
	void Destroy( void );

public:
	void Write( TCHAR* ptszData, bool bIsAutoEnter = true );
	bool IsValid( void ) { return m_bIsValid; }
	void Flush( void );

public:
	void WriteBotSystemLog( void* pPacketBuf, int len, bool bIsIf, CNtlNetBuffer* pSendBuffer, __int64 nCharacterPCID );

private:
	std::ofstream* m_pOutFile;
	bool m_bIsValid;

};//end of class ( CBotSystemLog_Server )