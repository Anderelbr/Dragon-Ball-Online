#pragma once
#include "stdafx.h"
#include "PacketCommon.h"

#pragma pack(1)

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(HoiPoiMix)

	bool NormalStart;
	bool SpecialStart;

	ubyte SpecialType;
	ubyte MixLevel;

	ushort MixExp;
	ushort Unknown;

	END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(ModelData)

	ubyte Race;
	ubyte Class;
	ubyte Gender;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(Localize)

	ubyte  Type;
	ubyte Unknown[27];

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(Marking)
	uint Code; /* TODO: just guessing */
END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AvatarAppearance)

	ubyte Face;
	ubyte Hair;
	ubyte HairColor;
	ubyte SkinColor;

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AvatarAttributes)

	ushort  BaseStr;
	ushort  LastStr;
	ushort  BaseCon;
	ushort  LastCon;
	ushort  BaseFoc;
	ushort  LastFoc;
	ushort  BaseDex;
	ushort  LastDex;
	ushort  BaseSol;
	ushort  LastSol;
	ushort  BaseEng;
	ushort  LastEng;

	uint	BaseMaxLP;
	uint	LastMaxLP;
	ushort  BaseMaxEP;
	ushort  LastMaxEP;
	uint	BaseMaxAP;
	uint	LastMaxAP;
	ushort  BaseMaxRP;
	ushort  LastMaxRP;

	ushort  BaseLpRegen;
	ushort  LastLpRegen;
	ushort  BaseLpSitdownRegen;
	ushort  LastLpSitdownRegen;
	ushort  BaseLpBattleRegen;
	ushort  LastLpBattleRegen;

	ushort  BaseEpRegen;
	ushort  LastEpRegen;
	ushort  BaseEpSitdownRegen;
	ushort  LastEpSitdownRegen;
	ushort  BaseEpBattleRegen;
	ushort  LastEpBattleRegen;

	ushort  BaseApRegen;
	ushort  LastApRegen;
	ushort  BaseApSitdownRegen;
	ushort  LastApSitdownRegen;
	ushort  BaseApBattleRegen;
	ushort  LastApBattleRegen;

	ushort  unknown_int16[4];//????

	ushort  BaseRpRegen;
	ushort  LastRpRegen;
	ushort  LastRpDimimutionRate;

	ushort  BasePhysicalOffence;
	ushort  LastPhysicalOffence;
	ushort  BasePhysicalDefence;
	ushort  LastPhysicalDefence;

	ushort  BaseEnergyOffence;
	ushort  LastEnergyOffence;
	ushort  BaseEnergyDefence;
	ushort  LastEnergyDefence;

	ushort  BaseAttackRate;
	ushort  LastAttackRate;
	ushort  BaseDodgeRate;
	ushort  LastDodgeRate;
	ushort  BaseBlockRate;
	ushort  LastBlockRate;

	ushort  BaseCurseSuccessRate;
	ushort  LastCurseSuccessRate;
	ushort  BaseCurseToleranceRate;
	ushort  LastCurseToleranceRate;

	ushort  unknown_rate1;// ??
	ushort  unknown_rate2;// ??

	ushort  BasePhysicalCriticalRate;
	ushort  LastPhysicalCriticalRate;
	ushort  BaseEnergyCriticalRate;
	ushort  LastEnergyCriticalRate;

	float unknown_float1[2];//??
	float unknown_float2[2];//??

	float BaseRunSpeed;
	float LastRunSpeed;

	float BaseAirSpeed;
	float LastAirSpeed;
	float BaseAirDashSpeed;
	float LastAirDashSpeed;
	float BaseAirDash2Speed;
	float LastAirDash2Speed;


	ushort  BaseAttackSpeedRate;
	ushort  LastAttackSpeedRate;
	float BaseAttackRange;
	float LastAttackRange;

	float CastingTimeChangePercent;
	float CoolTimeChangePercent;
	float KeepTimeChangePercent;
	float DotValueChangePercent;
	float DotTimeChangeAbsolute;
	float RequiredEpChangePercent;



	float HonestOffence;
	float HonestDefence;
	float StrangeOffence;
	float StrangeDefence;
	float WildOffence;
	float WildDefence;
	float EleganceOffence;
	float EleganceDefence;
	float FunnyOffence;
	float FunnyDefence;

	float unknown2;//??

	ushort  ParalyzeToleranceRate;
	ushort  TerrorToleranceRate;
	ushort  ConfuseToleranceRate;
	ushort  StoneToleranceRate;
	ushort  CandyToleranceRate;

	float ParalyzeKeepTimeDown;
	float TerrorKeepTimeDown;
	float ConfuseKeepTimeDown;
	float StoneKeepTimeDown;
	float CandyKeepTimeDown;
	float BleedingKeepTimeDown;
	float PoisonKeepTimeDown;
	float StomachacheKeepTimeDown;

	float CriticalBlockSuccessRate;

	ushort  GuardRate;
	ushort  unknown6;

	float SkillDamageBlockModeSuccessRate;
	float CurseBlockModeSuccessRate;
	float KnockdownBlockModeSuccessRate;
	float HtbBlockModeSuccessRate;

	float SitDownLpRegenBonusRate;
	float SitDownEpRegenBonusRate;

	float PhysicalCriticalDamageBonusRate;
	float EnergyCriticalDamageBonusRate;

	float ItemUpgradeBonusRate;
	float ItemUpgradeBreakBonusRate;

	float unknown3[14];//??
	ushort  unknown4[7];//??
	float unknown5[6];//??

END()

//-----------------------------------------------------------------------------------
//		Purpose:
//-----------------------------------------------------------------------------------

SAMPLE_PACKET(AvatarProfile) 

	ubyte		     MaxLevel;
	uint		     Tblidx;

	bool			 Adult;
	bool			 ChangeClass;

	uint			 CharID;
	wchar			 PlayerName[16 + 1];

	AvatarAppearance Appearance;
	AvatarAttributes Attributes;

	uint			 CurrentLP;
	ushort			 CurrentEP;
	ushort			 CurrentRP;

	ubyte			 Unknown;
	uint			 CurrentAP;

	ubyte			 Level;

	uint			 CurrentExp;
	uint			 MaxExpInLevel;

	uint			 Zenni;
	uint			 Tutorial;

	ubyte			 BindType;
	uint			 BindWorld;
	uint			 BindObjectTblidx;

	uint			 Reputation;
	uint			 MudosaPoints;
	uint			 SpPoints;

	Marking			 Markingg;
	HoiPoiMix		 HoiPoi;

	bool			 GameMaster;

	uint			 GuildID;
	Localize		 ProfileLocalize;

END()


#pragma pack()