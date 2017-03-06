#pragma once
#include "stdafx.h"

//-----------------------------------------------------------------------------------
//		CSessionData
//-----------------------------------------------------------------------------------

class CSessionData {

	private:

		unsigned int PlayerID;
		unsigned int AccountID;
		unsigned int CharID;

		unsigned int ServerID;

	public:

		CSessionData() {}
		CSessionData(unsigned int PID, unsigned int AID, unsigned int CID, unsigned int SID) : PlayerID(PID), AccountID(AID), CharID(CID), ServerID(SID) {}
		~CSessionData() {}

		unsigned int &GetPlayerID()  { return PlayerID; }
		unsigned int &GetAccountID() { return AccountID; }
		unsigned int &GetServerID()  { return ServerID; }
		unsigned int &GetCharID()    { return CharID; }

		void SetValues(unsigned int &PID, unsigned int &AID, unsigned int &CID, unsigned int SID = 0){
			PlayerID = PID;
			AccountID = AID;;
			CharID = CID;;
			ServerID = SID;
		}

		void SetPlayerID(unsigned int &PID)  { PlayerID = PID; }
		void SetAccountID(unsigned int &ACID){ AccountID = ACID; }
		void SetServerID(unsigned int &SID)  { ServerID = SID; }
		void SetCharID(unsigned int &CID)    { CharID = CID; }
		
};
