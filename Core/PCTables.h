#pragma once
#include "stdafx.h"
#include "PacketCommon.h"

#pragma pack(1)



//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(Quickslot) 

	uint ID;

	ubyte Type;
	ubyte QuickSlot;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AvatarNewbie) 

	uint	Tblidx;

	ubyte	Race;
	ubyte	Class;

	uint	WorldID;
	uint	TutorialWorldID;

	Vector3 Spawnloc;
	Vector3 Spawndir;

	Vector3 Bindloc;
	Vector3 Bindir;

	uint	ItemsID[10];
	ubyte	ItemSlots[10];
	ubyte	IemStack[10];

	uint	MapInfoName;
	uint	SkillsID[7];

	Quickslot Quickslot[5];

	ubyte	PortalID;
	ubyte	Unknown1;
	ubyte	Unknown2;

	uint	ItemID1;
	ubyte	ItemPos1;
	ubyte	ItemStack1;

	ubyte	Unknown3;
	ubyte	Unknown4;

END()

#pragma pack()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AvatarTable) 

	uint BasicLP;
	ushort BasicEP;

	ushort BasicPhysicalDefense;
	ushort BasicEnergyDefense;

	ushort Strength;
	ushort Constitution;
	ushort Focus;
	ushort Dextery;
	ushort Soul;
	ushort Energy;

	float Scale;

	ushort AttackSpeedRate;
	ubyte AttackType;

	float AttackRange;

	ushort AttackRate;
	ushort DodgeRate;
	ushort BlockRate;
	ushort CurseSuccessRate;
	ushort CurseToleranceRate;

	float Radius;

	ushort BasicAggroPoint;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(PlayerTable)

	uint Tblidx;
	AvatarTable CharTable;

	ubyte Race;
	ubyte Gender;
	ubyte Class;

	ulong PreviousClassID;
	uint ClassBitFlag;

	nbyte ModelChild[32 + 1];
	nbyte ModelAdult[32 + 1];

	float ChildRunSpeedOrigin;
	float ChildRunSpeed;
	float AdultRunSpeedOrigin;
	float AdultRunSpeed;

	float Unknown1[12];

	ushort BasicLp;
	ushort BasicPhysicalOffence;
	ushort BasicEnergyOffence;

	uint Unknown2;

	ubyte LevelUpLP;
	ubyte LevelUpEP;
	ubyte LevelUpRP;

	ubyte LevelUpPhysicalOffence;
	ubyte LevelUpPhysicalDefence;
	ubyte LevelUpEnergyOffence;
	ubyte LevelUpEnergyDefence;

	float LevelUpStrength;
	float LevelUpConstitution;
	float LevelUpFocus;
	float LevelUpDextery;
	float LevelUpSoul;
	float LevelUpEnergy;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(SpawnTable)

	uint			Tblidx;
	uint			MobTblidx;

	Vector3		    SpawnPosition;
	Vector3		    SpawnRotation;

	ubyte			SpawnPosRange;
	ubyte			SpawnQuantity;
	ushort			SpawnCoolTime;
	ubyte			SpawnMoveType;

	ubyte			WanderRange;
	ubyte			MoveRange;
	ubyte			MoveDelayTime;

	uint			PathTableIndex;
	Vector3		    FollowDistance;

	uint			PlayScript;
	uint			PlayScriptScene;

	uint			AIScript;
	uint			AIScriptScene;

	ulong			PartyIndex;
	bool			PartyLeader;

	uint			SpawnGroupID;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(NPCData) 

	uint			Tblidx;

	uint			BasicLP;
	ushort			BasicEP;

	ushort			BasePhysicalDefense;
	ushort			BaseEnergyDefense;

	ubyte			Strength;
	ubyte			Constitution;
	ubyte			Focus;
	ubyte			Dextery;
	ubyte			Soul;
	ubyte			Energy;

	float			ModelSize;

	ushort			AttackSpeedRate;
	ubyte			AttackType;

	float			AttackRange;

	ushort			AttackRate;
	ushort			DodgeRate;

	ushort			BlockRate;
	ushort			CurseSuccessRate;

	ushort			CurseToleranceRate;

	float			Radius;
	ushort			BasicAggroPoint;

	bool			Validityable = true;

	uint			NameTblidx;

	wchar			NameText[40 + 1];
	nbyte			ModelName[32 + 1];

	ubyte			Level;
	ulong			AIBitFlag;

	ushort			LPRegeneration;
	ushort			EPRegeneration;

	ubyte			AttackAnimationQuantity;

	ubyte			BattleAttribute;
	ushort			BasicOffence;
	float			WalkSpeedOrigin;
	float			WalkSpeed;
	float			RunSpeedOrigin;
	float			RunSpeed;
	float			RadiusX;
	float			RadiusZ;
	ubyte			SightRange;
	ubyte			ScanRange;

	ushort			UseSkillTime[7];
	uint			useSkillTblidx[7];
	ubyte			UseSkillBasis[7];
	ushort			UseSkillLP[7];

	ubyte			VisibleSightRange;
	//std::string		strCamera_Bone_Name;
	byte			CameraBoneName[32 + 1];

	ushort			AttackCoolTime;
	float			FlyHeight;
	byte			NameText2[40 + 1];

	bool			SpawnAnimation;
	ulong			DialogGroup;

	nbyte			ILLust[32 + 1];
	ulong			AllianceIDX;
	ushort			AggroMaxCount;

	ubyte            NPCType;
	ubyte            NPCJob;

	ulong           FuncBitFlag;

	uint			DialogScriptIndex;
	uint            MerchantTblidx[6];

	uint			StatusTransformTblidx;
	uint			ContentsTblidx;

	ubyte			Ars[52];

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(MOBData)

	uint			Tblidx;

	uint			BasicLP;
	ushort			BasicEP;

	ushort			BasePhysicalDefense;
	ushort			BaseEnergyDefense;

	ubyte			Strength;
	ubyte			Constitution;
	ubyte			Focus;
	ubyte			Dextery;
	ubyte			Soul;
	ubyte			Energy;

	float			fScale;

	ushort			AttackSpeedRate;
	ubyte			AttackType;

	float			AttackRange;

	ushort			AttackRate;
	ushort			DodgeRate;

	ushort			BlockRate;
	ushort			CurseSuccessRate;

	ushort			CurseToleranceRate;

	float			Radius;
	ushort			BasicAggroPoint;

	bool			Validityable = true;

	uint			NameTblidx;

	wchar			NameText[40 + 1];
	byte			ModelName[32 + 1];

	ubyte			Level;
	ulong			AIBitFlag;

	ushort			LPRegeneration;
	ushort			EPRegeneration;

	ubyte			AttackAnimationQuantity;

	ubyte			BattleAttribute;
	ushort			BasicOffence;
	float			WalkSpeedOrigin;
	float			WalkSpeed;
	float			RunSpeedOrigin;
	float			RunSpeed;
	float			RadiusX;
	float			RadiusZ;
	ubyte			SightRange;
	ubyte			ScanRange;

	ushort			UseSkillTime[7];
	uint			useSkillTblidx[7];
	ubyte			UseSkillBasis[7];
	ushort			UseSkillLP[7];

	ubyte			VisibleSightRange;
	//std::string		strCamera_Bone_Name;
	nbyte			CameraBoneName[32 + 1];

	ushort			AttackCoolTime;
	float			FlyHeight;
	nbyte			NameText2[40 + 1];

	bool			SpawnAnimation;
	ulong			DialogGroup;

	nbyte			ILLust[32 + 1];
	ulong			AllianceIDX;
	ushort			AggroMaxCount;

	ulong		    MobGroup;
	ushort			MobKind;

	ulong			DropZenny;
	float			DropZennyRate;

	ushort			Exp;
	ubyte			Grade;

	ubyte			MobType;
	uint			DropItemTblidx;

	bool			Size;
	ushort			TMQPoint;

	uint			DropQustTblidx;
	uint			DropTypeTblidx;
	uint			DropEachTblidx;

	ubyte			DropTypeRateControl;
	ubyte			DropEachRateControl;

	ubyte			DropNItemRateControl;
	ubyte			DropSItemRateControl;
	ubyte			DropEItemRateControl;
	ubyte			DropLItemRateControl;

	bool			ShowName;

	ubyte			Property;
	ubyte			HitBlockRate;

	ushort			SightAngle;

END()