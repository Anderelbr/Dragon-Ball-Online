#pragma once
#include "stdafx.h"
#include "PacketCommon.h"
#include "Opcodes.h"
#include "GamePackets.h"
#include "PCTables.h"


//-----------------------------------------------------------------------------------
//		Purpose	: 
//-----------------------------------------------------------------------------------

#pragma pack(1)

SAMPLE_PACKET(ServerConfig)

	ushort		ServerCount;
	
	nbyte		ServerIP[64];
	nbyte		ServerName[16 + 1];
	
	nbyte		ServerPort[10];
	ushort		MaxClients;
	
	nbyte		DBHost[22];
	
	nbyte		DBUsername[10];
	nbyte		DBPassword[10];
	
	nbyte		DBName[10];

END()

#pragma pack()