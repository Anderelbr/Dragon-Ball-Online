#pragma once
#include "stdafx.h"
#include "NtlSfx.h"
#include "Packets.h"
#include "NtlPacketEncoder_RandKey.h"

//-----------------------------------------------------------------------------------
//		CClientSession
//-----------------------------------------------------------------------------------

class CGameServer;

class ClientSession : public CNtlSession{

	private:

		CNtlPacketEncoder_RandKey PacketEnconder;
	
	public:

		ClientSession(bool AliveCheck = false, bool OpcodeCheck = false) : CNtlSession(SESSION_CLIENT) {
			
			SetControlFlag(CONTROL_FLAG_USE_SEND_QUEUE);
	
			if (AliveCheck)  SetControlFlag(CONTROL_FLAG_CHECK_ALIVE);
			if (OpcodeCheck) SetControlFlag(CONTROL_FLAG_CHECK_OPCODE);
	
			SetPacketEncoder(&PacketEnconder);
	
		}
	
		~ClientSession();

		int  OnAccept();
		int  OnDispatch(CNtlPacket *Packet);
		void OnClose();

		//-----------------------------------------------------------------

		int  HandshakeRequest();
		void HandshakeResponse();

		void GameEnterResponse(CNtlPacket *sPacket);
		void SendAvatarItemInfo();
		void SendAvatarInfo();
		void SendAvatarInfoEnd();
		void SendNetMarbleMemberShipNFY();
		void SendServerContents();
		void SendWorldEnterRequest();
		void SendEnterWorldComplete();
		void SendSpawnPlayer();
		void SendSpawnOthersProxys(CNtlSession *Session);
		void SendUpdateAvatarState();
};

//-----------------------------------------------------------------------------------
//		CGameSessionFactory
//-----------------------------------------------------------------------------------

class CGameSessionFactory : public CNtlSessionFactory {

	public:

		CNtlSession *CreateSession(WORD SessionType) {
		CNtlSession *NewSession = NULL;

		switch (SessionType) {

			case SESSION_CLIENT: NewSession = new ClientSession(); break;
			default: break;

		}

		return NewSession;
	}
};


