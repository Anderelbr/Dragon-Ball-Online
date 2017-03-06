#pragma once

//-----------------------------------------------------------------------------------
//		Purpose	: 
//-----------------------------------------------------------------------------------

enum ObjectType {

	OBJTYPE_PC,
	OBJTYPE_NPC,
	OBJTYPE_MOB,
	OBJTYPE_SUMMON_PET,
	OBJTYPE_ITEM_PET,
	OBJTYPE_DROPMONEY,
	OBJTYPE_DROPITEM,
	OBJTYPE_TOBJECT,
	OBJTYPE_DYNAMIC,
	OBJTYPE_ITEM,

	MAX_OBJTYPE,
	MAX_SPAWNOBJTYPE = OBJTYPE_DYNAMIC,
	INVALID_OBJTYPE = 0xFF,

	OBJTYPE_FIRST = OBJTYPE_PC,
	OBJTYPE_LAST = MAX_OBJTYPE - 1,
};
