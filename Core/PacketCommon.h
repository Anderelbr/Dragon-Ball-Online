#pragma once
#include "stdafx.h"


//-----------------------------------------------------------------------------------
//		Purpose	: Set / Get Packet Header
//-----------------------------------------------------------------------------------

struct PacketHeader{

	PacketHeader(ushort wGivenOpcode) : wOpcode(wGivenOpcode){};
	ushort wOpcode;
};

//-----------------------------------------------------------------------------------
//		Purpose	: Create an custom struct
//-----------------------------------------------------------------------------------

#define PACKET(wName,wOpcode)					\
struct wName : public PacketHeader {			\
												\
	wName() : PacketHeader(wOpcode){}			\
												
#define END() };

//-----------------------------------------------------------------------------------
//		Purpose	: Create an sample custom struct
//-----------------------------------------------------------------------------------

#define SAMPLE_PACKET(wNames)					\
struct wNames {									\
												
#define END() };

//-----------------------------------------------------------------------------------
//		Purpose	: Create an sample custom union
//-----------------------------------------------------------------------------------

#define UNION(wName) \
union wName {		 
#define END() };	 