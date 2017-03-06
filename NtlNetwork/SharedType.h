//***********************************************************************************
//	File		:	NtlSharedType.h
//***********************************************************************************

#pragma once
// OBJECT HANDLE
typedef	unsigned int HOBJECT;
const HOBJECT INVALID_HOBJECT = 0xFFFFFFFF;
const HOBJECT MAX_HOBJECT = 0x0FFFFFFF;

// ACCOUNT ID
typedef unsigned int ACCOUNTID;
const ACCOUNTID INVALID_ACCOUNTID = 0xFFFFFFFF;

// GM ACCOUNT ID
typedef unsigned int GMACCOUNTID;
const GMACCOUNTID INVALID_GMACCOUNTID = 0xFFFFFFFF;

// GM GROUP ID
typedef unsigned int GMGROUPID;
const GMGROUPID INVALID_GMGROUPID = 0xFFFFFFFF;

// CHARACTER ID
typedef unsigned int CHARACTERID;
const CHARACTERID INVALID_CHARACTERID = 0xFFFFFFFF;

// ITEM ID
typedef unsigned int ITEMID;
const ITEMID INVALID_ITEMID = 0xFFFFFFFF;

// WORLD ID
typedef unsigned int WORLDID;
const WORLDID INVALID_WORLDID = 0xFFFFFFFF;

// ZONE ID
typedef unsigned int ZONEID;
const ZONEID INVALID_ZONEID = 0xFFFFFFFF;

// TABLE INDEX
typedef unsigned int TBLIDX;
const TBLIDX INVALID_TBLIDX =  0xFFFFFFFF;

// SLOT ID
typedef unsigned char SLOTID;
const SLOTID INVALID_SLOTID = 0xFF;

// PARTY ID
typedef unsigned int PARTYID;
const PARTYID INVALID_PARTYID = 0xFFFFFFFF;

// GUILD ID
typedef unsigned int GUILDID;
const GUILDID INVALID_GUILDID = 0xFFFFFFFF;

// RAID GROUP ID
typedef unsigned int GROUPID;
const GROUPID INVALID_GROUPID = 0xFFFFFFFF;

// ROOM ID
typedef unsigned int ROOMID;
const ROOMID INVALID_ROOMID = 0xFFFFFFFF;

// ANIMATION ID
typedef WORD ANIMATIONID;
const ANIMATIONID INVALID_ANIMATIONID = 0xFFFF; //�� �� ����� �ٲٸ� �ȵ�(by HoDong 2006. 8. 8��)

// GAME SERVER FARM ID
typedef BYTE SERVERFARMID;
const SERVERFARMID INVALID_SERVERFARMID = 0xFF;

// GAME SERVER CHANNEL ID
typedef BYTE SERVERCHANNELID;
const SERVERCHANNELID INVALID_SERVERCHANNELID = 0xFF;

// SERVER INDEX
typedef BYTE SERVERINDEX;
const SERVERINDEX INVALID_SERVERINDEX = 0xFF;
const SERVERINDEX DEFAULT_SERVERINDEX = 0;

// MAIL ID
typedef unsigned int MAILID;
const MAILID INVALID_MAILID = 0xFFFFFFFF;
//
const unsigned char INVALID_BYTE		= 0xffui8;
const unsigned short INVALID_WORD		= 0xffffui16;
const unsigned int INVALID_UINT			= 0xffffffff;
const unsigned int INVALID_DWORD		= 0xffffffffui32;
const float INVALID_FLOAT				= 3.402823466e+38F;

// Private Shop Wait Time
typedef __int64		PSHOP_WAITTIME;

// Portal/MAIL ID
typedef BYTE PORTALID;
const PORTALID INVALID_PORTALID = 0xFF;

// spwan group id
typedef unsigned int SPAWNGROUPID;
const SPAWNGROUPID INVALID_SPAWNGROUPID = 0xFFFFFFFF;

// Alliance ID
typedef unsigned int ALLIANCEID;
const ALLIANCEID INVALID_ALLIANCEID = 0xFFFFFFFF;

// Tenkaichi Budokai
typedef DWORD BUDOKAITIME;
const BUDOKAITIME INVALID_BUDOKAITIME = 0xFFFFFFFF;

// Dojo
typedef __int64		DOJOTIME;
const DOJOTIME INVALID_DOJOTIME = 0x8FFFFFFFFFFFFFFF;

// Team Type [eMATCH_TEAM_TYPE]
typedef	WORD		TEAMTYPE;
const TEAMTYPE INVALID_TEAMTYPE = 0xFFFF;

// JoinId [Tenkaichi Budokai]
typedef	WORD		JOINID;
const JOINID INVALID_JOINID = 0xFFFF;

// Buff Link ID
typedef BYTE		BUFFLINKID;
const BUFFLINKID INVALID_BUFFLINKID = 0xFF;

// Wait index
typedef	DWORD		WAITINDEX;
const WAITINDEX INVALID_WAITINDEX = 0xFFFFFFFF;

// Time
typedef time_t		DBOTIME;
const DBOTIME INVALID_DBOTIME = 0;

// Localize Type
typedef BYTE		LOCALIZETYPE;
const LOCALIZETYPE INVALID_LOCALIZETYPE = INVALID_BYTE;

// NetP
typedef DWORD		NETP;
const NETP			INVALID_NETP = INVALID_DWORD;

typedef long RwFixed;
typedef int  RwInt32;
typedef unsigned int RwUInt32;
typedef short RwInt16;
typedef unsigned short RwUInt16;
typedef unsigned char RwUInt8;
typedef signed char RwInt8;
typedef float RwReal;
typedef bool RwBool;

const int SECOND = 1000;
const int MINUTE = 60 * SECOND;
const int HOUR = 60 * MINUTE;
const int DAY = 24 * HOUR;

typedef struct RwV2d RwV2d;
struct RwV2d
{
    RwReal x;
    RwReal y;
};
typedef struct RwV3d RwV3d;
struct RwV3d
{
    RwReal x;
    RwReal y;
    RwReal z;
};

extern void RwV3dSub(RwV3d * out, const RwV3d * ina, const RwV3d * inb);











