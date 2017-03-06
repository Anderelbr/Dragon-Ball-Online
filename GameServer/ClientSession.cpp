#include "stdafx.h"
#include "ClientSession.h"


//-----------------------------------------------------------------------------------
//		Author : GameServer by @AnderBerriel
//-----------------------------------------------------------------------------------

ClientSession::~ClientSession(){}

//-----------------------------------------------------------------------------------
//		OnAccept
//-----------------------------------------------------------------------------------

int ClientSession::OnAccept() { return HandshakeRequest(); }

//-----------------------------------------------------------------------------------
//		OnDispatch
//-----------------------------------------------------------------------------------

int ClientSession::OnDispatch(CNtlPacket *Packet){

	PacketHeader *Header = (PacketHeader*)Packet->GetPacketData();

	if (Header->wOpcode > 16) {
		NTL_PRINT(PRINT_SYSTEM, "Packet Received: [Opcode: [%i]] [Size: [%i]]", Header->wOpcode, sizeof(Packet));
	}

	//------------------------------------------------------------------------------------------------

	switch (Header->wOpcode){

		case SYS_HANDSHAKE_RES : HandshakeResponse(); break;				  

			case UG_GAME_ENTER_REQ : {

				GameEnterResponse(Packet);
				SendAvatarInfo();
				SendAvatarItemInfo();
				SendAvatarInfoEnd();

			}break;

			//----------------------------------------------------------------------

			case UG_ENTER_WORLD : {

				SendNetMarbleMemberShipNFY();
				SendServerContents();
				SendWorldEnterRequest();
				SendEnterWorldComplete();
				
			}break;

			//----------------------------------------------------------------------

			case UG_CHAR_READY_TO_SPAWN : {
				
				//SendUpdateAvatarState();
				SendSpawnPlayer(); 

			}break;

		default: return CNtlSession::OnDispatch(Packet);
	}

	//------------------------------------------------------------------------------------------------

	return NTL_SUCCESS;
}

//-----------------------------------------------------------------------------------
//		OnClose
//-----------------------------------------------------------------------------------

void ClientSession::OnClose(){

}
