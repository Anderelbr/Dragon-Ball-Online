#pragma once
#include "stdafx.h"
#include "Item.h"
#include "Guild.h"
#include "Avatar.h"
#include "AvatarState.h"

#pragma pack (1)

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(TimeQuestStage)

	ubyte					byStageNumber;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(TimeQuestState)

	ubyte					byGameState;
	TimeQuestStage		sTimeQuestStage;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(TimeQuestInfo)

	uint					timeQuestTblidx;
	ubyte					byStartHour;
	ubyte					byStartMin;
	ubyte					byTimeQuestMode;
	ubyte					byDifficulty;
	bool					bCountDown;
	ubyte					dwLimitTime;
	ubyte					dwBonusTime;
	ubyte					dwDayRecord;
	
	TimeQuestState			sTimeQuestState;

END()



//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(AvatarItemInfo, GU_AVATAR_ITEM_INFO)

	ubyte		BeginCount;
	ubyte		ItemCount;

	ItemProfile Items[128];

END()


//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(GameRule)

	ubyte RuleType;
	nbyte Unknow[11];

	UNION() 
		TimeQuestInfo TimeQuestState;
	END()

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(WorldInfo)

	uint	  WorldID;
	uint	  WorldTblidx;

	uint	  TriggerObjOffset;
	GameRule RuleInfo;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(NPCBrief, GU_OBJECT_CREATE)

	uint		     Handle;
	ubyte			 OBJType;
	
	uint			 Tblidx;
	
	uint			 CurLP;
	ushort			 CurEP;
	
	uint			 MaxLP;
	ushort             MaxEP;
	
	ubyte			 Unknown[34];
	ubyte			 ModelSize;
	
	ubyte			 Unknown2[2];
	ubyte			 Level;
	
	ubyte			 Unknown3[3];
	
	ubyte			 BurnEffect;
	ubyte			 PoisonEffect;
	
	ubyte			 Unknown4[6];
	ubyte			 AspectID;
	
	ubyte			 Unknown5[10];
	
	Vector3			 Position;
	Vector3			 Rotation;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(MOBrief, GU_OBJECT_CREATE)

	uint             Handle;
	ubyte			 OBJType;
	
	uint			 Tblidx;
	
	uint			 CurLP;
	ushort			 CurEP;
	
	uint			 MaxLP;
	ushort           MaxEP;
	
	float			 Unknown;
	ubyte			 Unknown1[22];
	
	uint			 MovePatternTblidx;
	uint             Unknown2;
	
	ubyte			 ModelSize;
	ubyte			 Level;
	ubyte		     Unknown3;
	
	ubyte			 StateID;
	uint			 Unknown4;
	
	ubyte			 BurnEffect;
	ubyte			 PoisonEffect;
	
	ubyte			 Unknown5[6];
	ubyte			 AspectID;
	
	ubyte			 Unknown6[10];
	
	Vector3			 Position;
	Vector3			 Rotation;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(GameEnterReq, UG_GAME_ENTER_REQ)

	uint	AccountID;
	uint	CharID;

	ubyte	AuthKey[16];
	bool	Tutorial;

END()


//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(GameEnterRes, GU_GAME_ENTER_RES)

	ushort	ResultCode;
	nbyte    ChatServerIP[64+1];

	ushort  ChatPort;
	Time    TimeEnter;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(AvatarInfoEnd, GU_AVATAR_INFO_END)
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(NetMarbleMemberipNfy, GU_NETMARBLEMEMBERIP_NFY)
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(AvatarCharInfo, GU_AVATAR_CHAR_INFO)

	uint		    PlayerID;
	AvatarProfile   AvatarProf;

	ushort		    AvatarStateSize;
	AvatarStateInfo AvatarState;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(AvatarWorldInfo, GU_AVATAR_WORLD_INFO)
	
	Vector3	   Position;
	Vector3	   Rotation;

	WorldInfo WorldInfo;
	nbyte     DojoCount;

	DojoBrief Dojo[7];

END()

PACKET(EnterToWorldComplete, GU_ENTER_WORLD_COMPLETE)
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(PlayerBrief, GU_OBJECT_CREATE)

	uint			 Handle;
	ubyte			 Type; 
	uint			 CharID;
	uint			 Tblidx;
					 
	bool			 IsAdult;
					 
	wchar			 PlayerName[16 + 1];
	wchar			 GuildName[16 + 1];

	AvatarAppearance Appearance;

	uint			 MaxLP;
	uint			 CurLP;
	ushort			 MaxEP;
	ushort			 CurEP;
	uint			 MaxAP;
	uint			 CurAP;

	ubyte			 Level;
	ubyte			 Unknown[32];
	ItemBrief        Items[17];
	ubyte			 Unknown2[28];

	uint			 PetID; 
	ubyte			 ModelSize;

	uint			 Unknown3;
	ubyte			 StateID;
	ubyte			 Unknown4;

	ubyte			 Unknown5[12];
	
	ubyte			 AspectID;
	ubyte			 Unknown6[9];

	bool			 IsFighting;

	Vector3			 Position; 
	Vector3			 Rotation;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

PACKET(UpdateAvatarState, GU_UPDATE_CHAR_STATE)

	uint			 Handle;
	AvatarStateInfo  AvatarState;

END()

#pragma pack ()