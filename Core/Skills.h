#pragma once
#include "stdafx.h"
#include "PacketCommon.h"

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

enum SystemEffectResultType{

	DBO_SYSTEM_EFFECT_RESULT_TYPE_GENERAL = 0,
	DBO_SYSTEM_EFFECT_RESULT_TYPE_DH_HOT,
	DBO_SYSTEM_EFFECT_RESULT_TYPE_DD_DOT,
	DBO_SYSTEM_EFFECT_RESULT_TYPE_LP_EP_STEAL,

	DBO_SYSTEM_EFFECT_RESULT_TYPE_COUNT,

	DBO_SYSTEM_EFFECT_RESULT_TYPE_UNKNOWN = 0xFFui8,

	DBO_SYSTEM_EFFECT_RESULT_TYPE_FIRST = DBO_SYSTEM_EFFECT_RESULT_TYPE_GENERAL,
	DBO_SYSTEM_EFFECT_RESULT_TYPE_LAST = DBO_SYSTEM_EFFECT_RESULT_TYPE_COUNT - 1
};

#pragma pack(1)

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(SystemEffectResult)

	SystemEffectResultType		ResultType;

	UNION()

		float							ResultValue;

		SAMPLE_PACKET()
			float						DH_HOT_fHealAmount;
		END()

		SAMPLE_PACKET()

			float						DD_DOT_fDamage;
			float						DD_DOT_fAbsorbedDamage;
			float						DD_DOT_fReflectedDamage;
		
		END()

		// ACTIVE_LP_STEAL, ACTIVE_EP_STEAL, ACTIVE_LP_STEAL_OVER_TIME, ACTIVE_EP_STEAL_OVER_TIME
		SAMPLE_PACKET()
		
			float						LP_EP_STEAL_fLpDamage;
			float						LP_EP_STEAL_fEpDamage;
			float						LP_EP_STEAL_fAbsorbedDamage;
			float						LP_EP_STEAL_fReflectedDamage;
			float						LP_EP_STEAL_fLpGained;
			float						LP_EP_STEAL_fEpGained;

		END()

	END()

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(SkillResult)

	uint					Target;
	ubyte					AttackResult;		//Battle Attack Result
	SystemEffectResult		EffectResult1;
	SystemEffectResult		EffectResult2;
	ubyte					BlockedAction;		//GuardType
	sVector3				Shift;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(SkillHTBResult) 

	ubyte			Step;
	SkillResult	    SkillResult;

END()

#pragma pack()