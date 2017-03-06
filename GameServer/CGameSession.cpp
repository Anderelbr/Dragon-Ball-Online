#include "stdafx.h"
#include "ClientSession.h"
#include "CPlayer.h"

//-----------------------------------------------------------------------------------
//		Author : GameServer by @AnderBerriel
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//		HandshakeRequest
//-----------------------------------------------------------------------------------

int ClientSession::HandshakeRequest(){

	ubyte Buff[] = { 0x03, 0x00, 0xac, 0x86, 0xf5, 0x74 };
	CNtlPacket Packet(6);

	Packet.SetPacket(Buff, 6);
	Packet.GetPacketHeader()->bEncrypt = true;

	int res = App->Send(this->GetHandle(), &Packet);
	if (res != NULL) return res;
	
	NTL_PRINT(PRINT_SYSTEM, "New Client");
	return res;
}

//-----------------------------------------------------------------------------------
//		HandshakeResponse
//-----------------------------------------------------------------------------------

void ClientSession::HandshakeResponse(){

	CNtlPacket Packet(0x22);
	ubyte Buffer[] = { 0x10, 0x00, 0x84, 0xfb, 0x48, 0xf4, 0x8e, 0x5a, 0xb6, 0x67, 0xe2, 0x3d, 0x6e, 0x14, 0xb4, 0xa3, 0xc3, 0x24, 0x9e,
	0x5f, 0xe3, 0xd1, 0xd5, 0x88, 0x10, 0x0d, 0x68, 0x4f, 0x3b, 0xa5, 0xed, 0x37, 0xed, 0x4a };

	Packet.SetPacket(Buffer, 0x22);
	Packet.GetPacketHeader()->bEncrypt = false;

	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		GameEnterResponse
//-----------------------------------------------------------------------------------

void ClientSession::GameEnterResponse(CNtlPacket *sPacket){

	printf("--------------------------\n   GAME LOGIN REQUEST  \n--------------------------\n\n");

	GameEnterReq *req = (GameEnterReq*)sPacket->GetPacketData();

	CPlayer *NewPlayer = new CPlayer(req->CharID);
	uint     PlayerID = App->GetPlayerManager()->AddPlayer(NewPlayer, req->CharID);

	GetSessionData().SetValues(PlayerID, req->AccountID, req->CharID, 0);

	//----------------------------------------------------------------------

	App->GetDB()->Prepare("UPDATE Characters SET IsOnline = ?, Tutorial = ? WHERE CharID = ? AND AccountID = ?");

	App->GetDB()->SetInt(1, 1);
	App->GetDB()->SetInt(2, (req->Tutorial == true ? 0 : 1));
	App->GetDB()->SetInt(3, req->CharID);
	App->GetDB()->SetInt(4, req->AccountID);

	App->GetDB()->Execute();

	//----------------------------------------------------------------------

	CNtlPacket    Packet(sizeof GameEnterRes);
	GameEnterRes *res = (GameEnterRes*)Packet.GetPacketData();

	res->wOpcode =    GU_GAME_ENTER_RES;
	res->ResultCode = GAME_SUCCESS;
	res->ChatPort =   20400;
	//res->TimeEnter =  time(NULL);

	strcpy_s((char*)res->ChatServerIP, sizeof res->ChatServerIP, "127.0.0.1");

	//----------------------------------------------------------------------

	Packet.SetPacketLen(sizeof GameEnterRes);
	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendAvatarInfo
//-----------------------------------------------------------------------------------

void ClientSession::SendAvatarInfo(){
	
	CPlayer *Player = (CPlayer*)App->GetPlayerManager()->GetPlayer(GetSessionData().GetPlayerID());

	CNtlPacket Packet(sizeof AvatarCharInfo);
	AvatarCharInfo *res = (AvatarCharInfo*)Packet.GetPacketData();

	//----------------------------------------------------------------------

	res->wOpcode = GU_AVATAR_CHAR_INFO;

	memcpy(&res->AvatarProf, &Player->GetProfile(), sizeof AvatarProfile);
	memcpy(&res->AvatarState, &Player->GetState(), sizeof AvatarStateInfo);
	memcpy(&res->AvatarProf.Attributes, &Player->GetAttributes(), sizeof AvatarAttributes);

	res->PlayerID = GetSessionData().GetPlayerID();
	//res->AvatarStateSize = sizeof AvatarStateInfo;

	//----------------------------------------------------------------------

	Packet.SetPacketLen(sizeof AvatarCharInfo);
	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendAvatarItemInfo
//-----------------------------------------------------------------------------------

void ClientSession::SendAvatarItemInfo(){

	CPlayer *Player = (CPlayer*)App->GetPlayerManager()->GetPlayer(GetSessionData().GetPlayerID());

	//----------------------------------------------------------------------

	CNtlPacket Packet(sizeof AvatarItemInfo);
	AvatarItemInfo *res = (AvatarItemInfo*)Packet.GetPacketData();

	res->wOpcode = GU_AVATAR_ITEM_INFO;
	res->BeginCount = 0;
	res->ItemCount = Player->GetInventory().GetItemsCount();

	ItemProfile *PlayerItems = (ItemProfile*)Player->GetInventory().GetPlayerItems();

	//----------------------------------------------------------------------

	FOR(res->ItemCount){

		res->Items[i].Handle =			PlayerItems[i].Handle + GetSessionData().GetPlayerID();
		res->Items[i].Tblidx =			PlayerItems[i].Tblidx;
		res->Items[i].Place =			PlayerItems[i].Place;
		res->Items[i].Slot =			PlayerItems[i].Slot;
		res->Items[i].StackCount =		PlayerItems[i].StackCount;
		res->Items[i].Rank =			PlayerItems[i].Rank;
		res->Items[i].CurDur =			PlayerItems[i].CurDur;
		res->Items[i].Grade =			PlayerItems[i].Grade;
		res->Items[i].BattleAttribute = PlayerItems[i].BattleAttribute;

	}

	//----------------------------------------------------------------------

	Packet.SetPacketLen(sizeof(unsigned int)+(2 * sizeof(char)) + (res->ItemCount * sizeof(ItemProfile)));
	App->Send(this->GetHandle(), &Packet);
}


//-----------------------------------------------------------------------------------
//		SendAvatarInfoEnd
//-----------------------------------------------------------------------------------

void ClientSession::SendAvatarInfoEnd(){

	CNtlPacket Packet(sizeof AvatarInfoEnd);
	AvatarInfoEnd *res = (AvatarInfoEnd*)Packet.GetPacketData();

	//----------------------------------------------------------------------

	res->wOpcode = GU_AVATAR_INFO_END;

	Packet.SetPacketLen(sizeof AvatarInfoEnd);
	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendNetMarbleMemberShipNFY
//-----------------------------------------------------------------------------------

void ClientSession::SendNetMarbleMemberShipNFY(){

	CNtlPacket Packet(sizeof NetMarbleMemberipNfy);
	NetMarbleMemberipNfy *res = (NetMarbleMemberipNfy*)Packet.GetPacketData();

	res->wOpcode = GU_NETMARBLEMEMBERIP_NFY;

	//----------------------------------------------------------------------

	Packet.SetPacketLen(sizeof NetMarbleMemberipNfy);
	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendServerContents
//-----------------------------------------------------------------------------------

void ClientSession::SendServerContents(){

	ubyte Buff[] = { 0xe4, 0x15, 0x00, 0x00, 0x40, 0xb1, 0xff, 0x12, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x90, 0x00, 0x06, 0xda, 0x08, 0x00, 0x00, 0xd7, 0x08, 0x00, 0x00, 0xdb, 0x08, 0x00, 0x00, 0xd8, 0x08, 0x00, 0x00, 0xdc, 0x08, 0x00, 0x00, 0xd9, 0x08, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00 };
	CNtlPacket Packet(270);

	Packet.SetPacket(Buff, sizeof Buff);
	Packet.SetPacketLen((sizeof Buff - 2));

	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendWorldEnterRequest
//-----------------------------------------------------------------------------------

void ClientSession::SendWorldEnterRequest(){

	printf("--------------------------\n  WORLD ENTER REQUEST  \n--------------------------\n\n");

	CPlayer *Player = (CPlayer*)App->GetPlayerManager()->GetPlayer(GetSessionData().GetPlayerID());

	CNtlPacket Packet(sizeof AvatarWorldInfo);
	AvatarWorldInfo *res = (AvatarWorldInfo*)Packet.GetPacketData();

	res->DojoCount = 0;
	res->wOpcode = GU_AVATAR_WORLD_INFO;

	//----------------------------------------------------------------------

	for (int i = 0; i < 7; i++){

		res->Dojo[i].DojoTIDX = INVALID_TBLIDX;
		res->Dojo[i].GuildID =  INVALID_TBLIDX;
	}

	//----------------------------------------------------------------------

	res->WorldInfo.WorldID = Player->GetWorldID();
	res->WorldInfo.WorldTblidx = Player->GetWorldTable();

	res->WorldInfo.TriggerObjOffset = 133000;
	res->WorldInfo.RuleInfo.RuleType = GAMERULE_NORMAL;

	res->Position = Player->GetPosition();
	res->Rotation = Player->GetRotation();

	//----------------------------------------------------------------------

	Packet.SetPacketLen(sizeof AvatarWorldInfo);
	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendEnterWorldComplete
//-----------------------------------------------------------------------------------

void ClientSession::SendEnterWorldComplete(){

	printf("--------------------------\n  ENTER TO WORLD FINISHED  \n--------------------------\n\n");

	CNtlPacket Packet(sizeof EnterToWorldComplete);
	EnterToWorldComplete *res = (EnterToWorldComplete*)Packet.GetPacketData();

	res->wOpcode = GU_ENTER_WORLD_COMPLETE;

	Packet.SetPacketLen(sizeof EnterToWorldComplete);
	App->Send(this->GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendEnterWorldComplete
//-----------------------------------------------------------------------------------

void ClientSession::SendSpawnPlayer(){
	
	printf("--------------------------\n  SEND SPAWN PLAYER  \n--------------------------\n\n");

	CPlayer *MyPlayer = (CPlayer*)App->GetPlayerManager()->GetPlayer(GetSessionData().GetPlayerID());

	//----------------------------------------------------------------------
	
	CNtlPacket Packet(sizeof PlayerBrief);
	PlayerBrief *res = (PlayerBrief*)Packet.GetPacketData();
	PlayerTable NData;

	App->GetTables()->GetTable("SpawnPlayerData.rdf", NData, MyPlayer->GetModelData().Race, MyPlayer->GetModelData().Class, MyPlayer->GetModelData().Gender);

	//----------------------------------------------------------------------

	mbstowcs_s(0, (wchar*)res->PlayerName, 34, (nbyte*)MyPlayer->GetPlayerName().c_str(), 34);
	
	//memset(&res->Unknown, INVALID_BYTE, 32);
	//memset(&res->Unknown2, INVALID_BYTE, 28);
	//memset(&res->Unknown5, INVALID_BYTE, 2);

	//memset(&res->Unknown6, INVALID_BYTE, 9);
	memcpy(&res->Appearance, &MyPlayer->GetProfile().Appearance, sizeof AvatarAppearance);
	memcpy(&res->Items,		  MyPlayer->GetInventory().GetEquipedItems(), sizeof res->Items);

	res->wOpcode =	  GU_OBJECT_CREATE;
	res->Handle =     GetSessionData().GetPlayerID();
	res->Type =       OBJTYPE_PC;
	res->Tblidx =	  NData.Tblidx;
	res->CharID =	  GetSessionData().GetCharID();
	res->CurLP =	  MyPlayer->GetProfile().CurrentLP;
	res->CurEP =	  MyPlayer->GetProfile().CurrentEP;
	res->MaxAP =      MyPlayer->GetProfile().CurrentAP;
	res->MaxLP =	  MyPlayer->GetAttributes().BaseMaxLP;
	res->MaxEP =	  MyPlayer->GetAttributes().BaseMaxEP;
	res->MaxAP =	  MyPlayer->GetAttributes().BaseMaxAP;
	res->Level =	  MyPlayer->GetProfile().Level;
	res->IsAdult =	  MyPlayer->GetProfile().Adult;
	res->IsFighting = MyPlayer->GetState().CharStateBase.FightMode;
	res->Position =   MyPlayer->GetPosition();
	res->Rotation =   MyPlayer->GetRotation();
	res->StateID =    CHARSTATE_SPAWNING;
	res->AspectID =   255;
	res->PetID =	  INVALID_TBLIDX;
	res->ModelSize =  10;
	
	Packet.SetPacketLen(sizeof PlayerBrief);

	for (int i = 0; i < App->GetNetwork()->GetSessionList()->GetCurCount(); i++){

		CNtlSession *Session = App->GetNetwork()->GetSessionList()->Find(i);

		CPlayer *Player = (CPlayer*)App->GetPlayerManager()->GetPlayer(Session->GetSessionData().GetPlayerID());
		float    Distance = Vector3::Distance(MyPlayer->GetPosition(), Player->GetPosition());

		if (Session->GetHandle() != this->GetHandle()) {

			//SendSpawnOthersProxys(Session);

			if (Distance < 300)
				App->Send(Session->GetHandle(), &Packet);
		}
	}
}

//-----------------------------------------------------------------------------------
//		SendSpawnOthersProxys
//-----------------------------------------------------------------------------------

void ClientSession::SendSpawnOthersProxys(CNtlSession *Session){

	CPlayer *ProxyPlayer = (CPlayer*)App->GetPlayerManager()->GetPlayer(Session->GetSessionData().GetPlayerID());

	CNtlPacket Packet(sizeof PlayerBrief);
	PlayerBrief *res = (PlayerBrief*)Packet.GetPacketData();
	PlayerTable NData;

	App->GetTables()->GetTable("SpawnPlayerData.rdf", NData, ProxyPlayer->GetModelData().Race, ProxyPlayer->GetModelData().Class, ProxyPlayer->GetModelData().Gender);

	//----------------------------------------------------------------------

	mbstowcs_s(0, (wchar*)res->PlayerName, sizeof res->PlayerName, (nbyte*)ProxyPlayer->GetPlayerName().c_str(), sizeof res->PlayerName);

	memcpy(&res->Appearance, &ProxyPlayer->GetProfile().Appearance, sizeof AvatarAppearance);
	memset(&res->Unknown,   INVALID_BYTE, 179);
	//memset(&res->GuildName, INVALID_BYTE, 32);

	res->wOpcode =		GU_OBJECT_CREATE;
	res->Handle =		Session->GetSessionData().GetPlayerID();
	res->Type =			OBJTYPE_PC;
	res->Tblidx =		NData.Tblidx;
	res->CharID =		Session->GetSessionData().GetCharID();
	res->CurLP =		ProxyPlayer->GetProfile().CurrentLP;
	res->CurEP =		ProxyPlayer->GetProfile().CurrentEP;
	res->MaxAP =		ProxyPlayer->GetProfile().CurrentAP;
	res->MaxLP =		ProxyPlayer->GetAttributes().BaseMaxLP;
	res->MaxEP =		ProxyPlayer->GetAttributes().BaseMaxEP;
	res->MaxAP =		ProxyPlayer->GetAttributes().BaseMaxAP;
	res->Level =		ProxyPlayer->GetProfile().Level;
	res->IsAdult =		ProxyPlayer->GetProfile().Adult;
	res->IsFighting =	ProxyPlayer->GetState().CharStateBase.FightMode;
	res->Position =		ProxyPlayer->GetPosition();
	res->Rotation =		ProxyPlayer->GetRotation();
	res->StateID =		CHARSTATE_SPAWNING;
	res->AspectID =		INVALID_BYTE;
	res->PetID =		INVALID_TBLIDX;
	res->ModelSize =	10;

	Packet.SetPacketLen(sizeof PlayerBrief);
	App->Send(GetHandle(), &Packet);
}

//-----------------------------------------------------------------------------------
//		SendUpdateAvatarState
//-----------------------------------------------------------------------------------

void ClientSession::SendUpdateAvatarState(){
	
	printf("--------------------------\n  UPDATE AVATAR STATE  \n--------------------------\n\n");

	CPlayer *Player = (CPlayer*)App->GetPlayerManager()->GetPlayer(this->GetSessionData().GetPlayerID());

	CNtlPacket Packet(sizeof UpdateAvatarState);
	UpdateAvatarState *res = (UpdateAvatarState*)Packet.GetPacketData();

	memcpy(&res->AvatarState, &Player->GetState(), sizeof AvatarStateInfo);

	res->wOpcode = GU_UPDATE_CHAR_STATE;
	res->Handle =  this->GetSessionData().GetPlayerID();
	res->AvatarState.CharStateBase.StateID = CHARSTATE_STANDING;

	Packet.SetPacketLen(sizeof UpdateAvatarState);
	App->Send(this->GetHandle(), &Packet);
}