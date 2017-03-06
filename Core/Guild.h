#pragma once
#include "stdafx.h"
#include "PacketCommon.h"

#pragma pack(1)

//---------------------------------------------------------------------------------- -
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(GuildMark)

bool IsIntialized() {

	if (INVALID_BYTE == MarkMain && INVALID_BYTE == MarkMainColor && INVALID_BYTE == MarkInLine && INVALID_BYTE == MarkOutLine && INVALID_BYTE == MarkOutColor)
		return false;
	else
		return true;

}

	ubyte					MarkMain;
	ubyte					MarkMainColor;
	ubyte					MarkInLine;
	ubyte					MarkInColor;
	ubyte					MarkOutLine;
	ubyte					MarkOutColor;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DojoBrief)

	uint	   GuildID;
	uint	   DojoTIDX;
	
	ubyte	   DojoLevel;
	GuildMark  Mark;

END()

#pragma pack()