#pragma once
#include "stdafx.h"
#include "PacketCommon.h"
#include "Skills.h"

#pragma pack(1)

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(CharAspectBase)
	ubyte AspectID;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(PrivateShopData)

	bool IsOwnerEmpty;
	ubyte ShopState;
	wchar PrivateShopName[32 + 1];

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AspectSuperSaiyan)
	ubyte Grade;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AspectPureMajin)
	ubyte Grade;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AspectGreatNamek)
	ubyte Grade;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AspectKaioken)
	ubyte Grade;
	ubyte Repeat;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AspectSpinningAttack)
	ubyte Grade;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AspectVehicle)

	//HANDLEID handle;
	uint VehicleID;
	bool IsEngineOn;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

UNION(CharAspectDetail)

	AspectSuperSaiyan SuperSaiyan;
	AspectPureMajin PureMajin;
	AspectGreatNamek GreatNamek;
	AspectKaioken Kaioken;
	AspectSpinningAttack SpinningAtack;
	AspectVehicle Vehicle;

	ubyte Unknown[10];

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AspectInfo)
	CharAspectBase AspectBase;
	CharAspectDetail AspectDetail;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(StateBase)

	ubyte StateID; /* enum dbo_char_state */

	uint StateTime;
	uint ConditionFlag;

	uint Unknown;

	AspectInfo AspectStateInfo;
	bool FightMode : 1;

	Vector3 CurPos;
	Vector3 CurRot;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateSpawing)
	ubyte TeleportType;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateDeSpawing)
	ubyte TeleportType;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateStanding)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------
SAMPLE_PACKET(DboCharStateSitting)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateFainting)
	ubyte Reason;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateCamping)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateLeaving)
	ubyte LeavingType;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateMoving)
	uint			TimeStamp;
	ubyte			MoveFlag;
	ubyte			MoveDirection;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateDestMove)
	uint			TimeStamp;
	ubyte			MoveFlag;
	bool			HaveSecondDestLoc;
	sVector3		SecondDestLoc;
	ubyte			DestLocCount;
	sVector3		DestLoc[10];
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateFollowing)
	uint			TimeStamp;
	ubyte			MoveFlag;
	uint			Target;
	float			Distance;
	ubyte			MovementReason;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateFalling)
	ubyte MoveDirection;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateDashPassive)
	uint			TimeStamp;
	ubyte			MoveDirection;
	sVector3		DestLoc;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateTeleporting)
	ubyte Type; /* enum dbo_char_state_teleporting_type */
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateSliding)
	sVector3 Shift;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateknockDown)
	sVector3 Shift;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateFocusing)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateCasting)
	uint			SkillID;
	uint			Target;
	uint			CastingTime;
	uint			CastingTimeRemaining;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateSkillAffecting)
	uint			SkillID;
	uint			Target;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateKeepingEffect)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateCastingItem) 
	uint			ItemTblidx;
	uint			Target;
	uint			CastingTime;
	uint			CastingTimeRemaining;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateStunned)
	ubyte			StunType;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateSleeping)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateParalyzed)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateHTB)
	uint				HTBID;
	uint				Target;
	ubyte				StepCount;
	ubyte				CurStep;
	ubyte				ResultCount;
	SkillHTBResult	HTBSkillResult[10];
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateSandbag)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateCharging)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateBlocking)END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStatePrivateShop)
	PrivateShopData		SummaryPrivateShopData;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateDirectPlay) 
	ubyte				DirectPlayType;
	uint				DirectTblidx;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateOperating)
	uint				TargetObject;
	uint				OperateTime;
	uint				DirectTblidx;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateRideon)
	uint	Target;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(DboCharStateTurning)
	uint				DirectTblidx;
	sVector3				DestDir;
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

UNION(StateDetail)

	DboCharStateSpawing Spawning;
	DboCharStateDeSpawing Despawning;
	DboCharStateStanding Standing;
	DboCharStateSitting Sitting;
	DboCharStateFainting Fainting;
	DboCharStateCamping Camping;
	DboCharStateLeaving Leaving;

	DboCharStateMoving Moving;
	DboCharStateDestMove Destmove;
	DboCharStateFollowing Follwing;
	DboCharStateFalling Falling;
	DboCharStateDashPassive DashPassive;
	DboCharStateTeleporting Teleporting;
	DboCharStateSliding Sliding;
	DboCharStateknockDown KnockDown;

	DboCharStateFocusing Focusing;
	DboCharStateCasting Casting;
	DboCharStateSkillAffecting SkillAffecting;
	DboCharStateKeepingEffect KeepingEffect;
	DboCharStateCastingItem CastingItem;

	DboCharStateStunned Stunned;
	DboCharStateSleeping Sleeping;
	DboCharStateParalyzed Paralyzed;

	DboCharStateHTB HTB;
	DboCharStateSandbag Sandbag;
	DboCharStateCharging Charging;

	DboCharStatePrivateShop PrivateShop;
	DboCharStateDirectPlay DirectPlay;
	DboCharStateOperating Operating;
	DboCharStateRideon Rideon;
	DboCharStateTurning Turning;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AvatarStateInfo)
	StateBase CharStateBase;
	StateDetail CharStateDetail;
END()

#pragma pack()