#include "stdafx.h"
#include "CPlayer.h"

//--------------------------------------------------------------------------------------
//					CPlayer - CPlayer.cpp
//--------------------------------------------------------------------------------------

CPlayer::CPlayer(uint &CID) : Inventory(CID){

	CharID = CID;
	CreateProfile();
}

CPlayer::~CPlayer(){}

//------------------------------------------------------------------------------------

void CPlayer::CreateProfile() {

	App->GetDB()->Prepare("SELECT * FROM Characters WHERE CharID = ? LIMIT 1");
	App->GetDB()->SetInt(1, CharID);

	App->GetDB()->Execute();
	App->GetDB()->NextField();

	//-----------------------------------------------------------------------------------------------------------------------------

	PlayerTable NData;
	App->GetTables()->GetTable("SpawnPlayerData.rdf", NData, App->GetDB()->GetInt("Race"), App->GetDB()->GetInt("Class"), App->GetDB()->GetInt("Gender"));

	//-----------------------------------------------------------------------------------------------------------------------------
	
	memset(&ModelInfo, 0, sizeof ModelData);

	FIllProfile(NData);
	FillAttributes(NData);
	FillState(NData);

	Inventory.LoadPlayerItems();
}

//------------------------------------------------------------------------------------

void CPlayer::FIllProfile(PlayerTable &NData) {

	memset(&Profile, 0, sizeof AvatarProfile);
	mbstowcs_s(0, Profile.PlayerName, sizeof(Profile.PlayerName), App->GetDB()->GetString("CharName").c_str(), sizeof(Profile.PlayerName));

	Profile.Tblidx = NData.Tblidx;
	Profile.MaxLevel = 70;
		   
	Profile.CharID =			   App->GetDB()->GetInt("CharID");
	Profile.GuildID =			   INVALID_TBLIDX;
		   
	Profile.CurrentLP =			   App->GetDB()->GetInt("CurLP");
	Profile.CurrentEP =			   App->GetDB()->GetInt("CurEP");
	Profile.CurrentAP =			   App->GetDB()->GetInt("CurAP");
	Profile.CurrentExp =		   App->GetDB()->GetInt("Exp");
	Profile.CurrentRP =			   App->GetDB()->GetInt("CurRP");
	Profile.Zenni =				   App->GetDB()->GetInt("Zenni");
	Profile.MaxExpInLevel =		   App->GetDB()->GetInt("MaxExp");
	Profile.Adult =		 (bool)	   App->GetDB()->GetInt("Adult");
	Profile.GameMaster = (bool)	   App->GetDB()->GetInt("GameMaster");
	Profile.Tutorial =   (bool)	   App->GetDB()->GetInt("Tutorial");
	Profile.ChangeClass =(bool)	   App->GetDB()->GetInt("ChangeClass");
		   						   
	Profile.Level =				   App->GetDB()->GetInt("Level");
	Profile.MudosaPoints =		   App->GetDB()->GetInt("Mudosa");
	Profile.Reputation =		   App->GetDB()->GetInt("Reputation");
	Profile.SpPoints =			   App->GetDB()->GetInt("SpPoint"); //Unknow (no se que es aun)
		   						   
	Profile.Appearance.Face =	   App->GetDB()->GetInt("Face");
	Profile.Appearance.Hair =	   App->GetDB()->GetInt("Hair");
	Profile.Appearance.HairColor = App->GetDB()->GetInt("HairColor");
	Profile.Appearance.SkinColor = App->GetDB()->GetInt("SkinColor");

	Profile.BindType = 0;
	Profile.BindObjectTblidx = -1;
	Profile.Markingg.Code = 0; //Market Type
	Profile.HoiPoi.NormalStart = 1;
	Profile.HoiPoi.MixLevel = 1;

	Profile.ProfileLocalize.Type = 0x03;
	memcpy(Profile.ProfileLocalize.Unknown, "\x24\x00\x00\x00\x00\x00\x00\x00\x00\x00\xff\x00\x50\x00\x00\x00\x00\xff\xff\xff\xff\xff\x00\x00\x00\x00\x00", 27);

	ModelInfo.Race =   App->GetDB()->GetInt("Race");
	ModelInfo.Class =  App->GetDB()->GetInt("Class");
	ModelInfo.Gender = App->GetDB()->GetInt("Gender");

	//-----------------------------------------------------------------------------------------------------------------------------

	SetPlayerName(App->GetDB()->GetString("CharName"));
	SetWorldTable(App->GetDB()->GetInt("WorldTable"));
	SetWorldID(App->GetDB()->GetInt("WorldID"));
	SetMapInfoIDX(App->GetDB()->GetInt("MapInfoIndex"));
	SetPosition(Vector3(App->GetDB()->GetFloat("PosX"), App->GetDB()->GetFloat("PosY"), App->GetDB()->GetFloat("PosZ")));
	SetRotation(Vector3(App->GetDB()->GetFloat("RotX"), App->GetDB()->GetFloat("RotY"), App->GetDB()->GetFloat("RotZ")));
}

//------------------------------------------------------------------------------------

void CPlayer::FillState(PlayerTable &NData) {

	memset(&State, 0, sizeof AvatarStateInfo);
	

	State.CharStateBase.CurPos = GetPosition();
	State.CharStateBase.CurRot = GetRotation();

	State.CharStateBase.ConditionFlag =			  0;
	State.CharStateBase.StateID =				  CHARSTATE_SPAWNING;
	State.CharStateDetail.Spawning.TeleportType = TELEPORT_TYPE_GAME_IN;
	State.CharStateBase.FightMode =				  false;
	State.CharStateBase.StateTime =				  0;
	State.CharStateBase.Unknown =				  0;

	State.CharStateBase.AspectStateInfo.AspectBase.AspectID =			 0xFF;
	State.CharStateBase.AspectStateInfo.AspectDetail.GreatNamek.Grade =  0xFF;
	State.CharStateBase.AspectStateInfo.AspectDetail.Kaioken.Grade =	 0xFF;
	State.CharStateBase.AspectStateInfo.AspectDetail.PureMajin.Grade =	 0xFF;
	State.CharStateBase.AspectStateInfo.AspectDetail.SuperSaiyan.Grade = 0xFF;
	State.CharStateBase.AspectStateInfo.AspectDetail.Vehicle.VehicleID = 0xFF;
}

//------------------------------------------------------------------------------------

void CPlayer::FillAttributes(PlayerTable &NData) {

	memset(&Attributes, 0, sizeof AvatarAttributes);

	Attributes.BaseStr =				   App->GetDB()->GetInt("BaseStr");
	Attributes.LastStr =				   App->GetDB()->GetInt("LastStr");
	Attributes.BaseCon =				   App->GetDB()->GetInt("BaseCon");
	Attributes.LastCon =				   App->GetDB()->GetInt("LastCon");
	Attributes.BaseFoc =				   App->GetDB()->GetInt("BaseFoc");
	Attributes.LastFoc =				   App->GetDB()->GetInt("LastFoc");
	Attributes.BaseDex =				   App->GetDB()->GetInt("BaseDex");
	Attributes.LastDex =				   App->GetDB()->GetInt("LastDex");
	Attributes.BaseSol =				   App->GetDB()->GetInt("BaseSol");
	Attributes.LastSol =				   App->GetDB()->GetInt("LastSol");
	Attributes.BaseEng =				   App->GetDB()->GetInt("BaseEng");
	Attributes.LastEng =				   App->GetDB()->GetInt("LastEng");
	 
	Attributes.BaseMaxLP =			       App->GetDB()->GetInt("BaseMaxLP");
	Attributes.LastMaxLP =			       App->GetDB()->GetInt("LastMaxLP");
	Attributes.BaseMaxEP =			       App->GetDB()->GetInt("BaseMaxEP");
	Attributes.LastMaxEP =			       App->GetDB()->GetInt("LastMaxEP");
	Attributes.BaseMaxRP =			       App->GetDB()->GetInt("BaseMaxRP");
	Attributes.LastMaxRP =			       App->GetDB()->GetInt("LastMaxRP");

	Attributes.BaseLpRegen = 1;
	Attributes.LastLpRegen = 1;
	Attributes.BaseLpSitdownRegen = 1;
	Attributes.LastLpSitdownRegen = 1;
	Attributes.BaseLpBattleRegen = 1;
	Attributes.LastLpBattleRegen = 1;

	Attributes.BaseEpRegen = 1;
	Attributes.LastEpRegen = 1;
	Attributes.BaseEpSitdownRegen = 1;
	Attributes.LastEpSitdownRegen = 1;
	Attributes.BaseEpBattleRegen = 1;
	Attributes.LastEpBattleRegen = 1;

	Attributes.BaseRpRegen = 1;
	Attributes.LastRpRegen = 1;
	Attributes.LastRpDimimutionRate = 1;

	Attributes.BasePhysicalOffence =		App->GetDB()->GetInt("BasePhysicalOffence");
	Attributes.LastPhysicalOffence =		App->GetDB()->GetInt("LastPhysicalOffence");
	Attributes.BasePhysicalDefence =		App->GetDB()->GetInt("BasePhysicalDefence");
	Attributes.LastPhysicalDefence =		App->GetDB()->GetInt("LastPhysicalDefence");
	 
	Attributes.BaseEnergyOffence =		    App->GetDB()->GetInt("BaseEnergyOffence");
	Attributes.LastEnergyOffence =		    App->GetDB()->GetInt("LastEnergyOffence");
	Attributes.BaseEnergyDefence =		    App->GetDB()->GetInt("BaseEnergyDefence");
	Attributes.LastEnergyDefence =		    App->GetDB()->GetInt("LastEnergyDefence");
	
	Attributes.BaseAttackRate =				App->GetDB()->GetInt("BaseAttackRate");
	Attributes.LastAttackRate =				App->GetDB()->GetInt("LastAttackRate");
	Attributes.BaseDodgeRate =				App->GetDB()->GetInt("BaseDodgeRate");
	Attributes.LastDodgeRate =				App->GetDB()->GetInt("LastDodgeRate");
	Attributes.BaseBlockRate =				App->GetDB()->GetInt("BaseBlockRate");
	Attributes.LastBlockRate =				App->GetDB()->GetInt("LastBlockRate");

	Attributes.BaseCurseSuccessRate = 1;
	Attributes.LastCurseSuccessRate = 1;
	Attributes.BaseCurseToleranceRate = 1;
	Attributes.LastCurseToleranceRate = 1;

	Attributes.BasePhysicalCriticalRate =	App->GetDB()->GetInt("BasePhysicalCriticalRate");
	Attributes.LastPhysicalCriticalRate =	App->GetDB()->GetInt("LastPhysicalCriticalRate");
	Attributes.BaseEnergyCriticalRate =		App->GetDB()->GetInt("BaseEnergyCriticalRate");
	Attributes.LastEnergyCriticalRate =		App->GetDB()->GetInt("LastEnergyCriticalRate");
	Attributes.LastRunSpeed =				App->GetDB()->GetFloat("LastRunSpeed");

	Attributes.BaseAttackSpeedRate =		App->GetDB()->GetInt("BaseAttackSpeedRate");
	Attributes.LastAttackSpeedRate =		App->GetDB()->GetInt("LastAttackSpeedRate");
	Attributes.LastAttackRange = (float)	App->GetDB()->GetInt("LastAttackRange");
	Attributes.BaseAttackRange = (float)	App->GetDB()->GetInt("BaseAttackRange");

	Attributes.CastingTimeChangePercent = 1.0f;
	Attributes.CoolTimeChangePercent = 1.0f;
	Attributes.KeepTimeChangePercent = 1.0f;
	Attributes.DotValueChangePercent = 1.0f;
	Attributes.DotTimeChangeAbsolute = 1.0f;
	Attributes.RequiredEpChangePercent = 1.0f;

	Attributes.HonestOffence = 1.0f;
	Attributes.HonestDefence = 1.0f;
	Attributes.StrangeOffence = 1.0f;
	Attributes.StrangeDefence = 1.0f;
	Attributes.WildOffence = 1.0f;
	Attributes.WildDefence = 1.0f;
	Attributes.EleganceOffence = 1.0f;
	Attributes.EleganceDefence = 1.0f;
	Attributes.FunnyOffence = 1.0f;
	Attributes.FunnyDefence = 1.0f;

	Attributes.ParalyzeToleranceRate = 1;
	Attributes.TerrorToleranceRate = 1;
	Attributes.ConfuseToleranceRate = 1;
	Attributes.StoneToleranceRate = 1;
	Attributes.CandyToleranceRate = 1;

	Attributes.ParalyzeKeepTimeDown = 1.0f;
	Attributes.TerrorKeepTimeDown = 1.0f;
	Attributes.ConfuseKeepTimeDown = 1.0f;
	Attributes.StoneKeepTimeDown = 1.0f;
	Attributes.CandyKeepTimeDown = 1.0f;
	Attributes.BleedingKeepTimeDown = 1.0f;
	Attributes.PoisonKeepTimeDown = 1.0f;
	Attributes.StomachacheKeepTimeDown = 1.0f;
	Attributes.CriticalBlockSuccessRate = 1.0f;
	Attributes.GuardRate = 1;

	Attributes.SkillDamageBlockModeSuccessRate = 1.0f;
	Attributes.CurseBlockModeSuccessRate = 1.0f;
	Attributes.KnockdownBlockModeSuccessRate = 1.0f;
	Attributes.HtbBlockModeSuccessRate = 1.0f;
	Attributes.SitDownLpRegenBonusRate = 1.0f;
	Attributes.SitDownEpRegenBonusRate = 1.0f;
	Attributes.PhysicalCriticalDamageBonusRate = 1.0f;
	Attributes.EnergyCriticalDamageBonusRate = 1.0f;

	Attributes.ItemUpgradeBonusRate = 1.0f;
	Attributes.ItemUpgradeBreakBonusRate = 1.0f;
	Attributes.BaseAirDash2Speed = 50.0f;//Dash Fly2 TW
	Attributes.LastAirDash2Speed = 50.0f;//Dash Fly2 TW
	Attributes.BaseAirDashSpeed = 30.0f;//Dash Fly TW
	Attributes.LastAirDashSpeed = 30.0f;//Dash Fly TW
	Attributes.BaseRunSpeed = 30;//Base Run TW
	Attributes.LastAirSpeed = 15;//LastAir Speed TW
	Attributes.LastMaxAP = 450;//Max AP
	Attributes.BaseMaxAP = 450;//Base Max Ap
	Attributes.BaseApBattleRegen = 5;//Regen In Battle AP TW
	Attributes.LastApBattleRegen = 5;//LAst Regen in Battle Ap TW
	Attributes.BaseApRegen = 5;//Base Ap Regen TW
	Attributes.LastApRegen = 5;//Base While Sitting Regen AP TW
	Attributes.BaseApSitdownRegen = 5;//AP Regen TW
	Attributes.LastApSitdownRegen = 5;//AP Regen TW
}

//------------------------------------------------------------------------------------


