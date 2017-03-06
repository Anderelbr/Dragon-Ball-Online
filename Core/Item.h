#pragma once
#include "stdafx.h"
#include "PacketCommon.h"

#pragma pack(1)

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(ItemEffect) 

	ushort	Type;
	ulong	Value;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(ItemExtraEffect) 

	ushort	Type;
	ulong	Value;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(ItemProfile)

	uint			Handle;
	uint			Tblidx;

	ubyte			Place;
	ubyte			Slot;

	ubyte			StackCount;
	ubyte			Rank;

	ubyte			CurDur;
	bool			NeedToIdentify;

	ubyte			Grade;
	ubyte			BattleAttribute;

	ubyte			RestrictType;
	wchar			Maker[16 + 1]; //Producer Name

	uint			OptionTblidx[2];

	ItemEffect		ItemsEffect[6];
	ItemExtraEffect ItemsExtraEffect[2];

	ubyte			DurationType;

	Time			UseStartTime; //Time of init on inventory
	Time			UseEndTime; //Time limit on inventory

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(ItemBrief) 

	uint			ItemID;
	ubyte			Rank;
	ubyte           Grade;
	ubyte			BattleAttribute;

END()

#pragma pack()