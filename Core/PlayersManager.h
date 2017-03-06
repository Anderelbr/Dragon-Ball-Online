#pragma once
#include "stdafx.h"

class CPlayer;
class PlayersManager;

typedef std::map<UINT, CPlayer*> PlayersList;
typedef std::shared_ptr<PlayersManager> PlayerManager;

//------------------------------------------------------------------------------------
//---------------------------------------------------------
//					PlayersManager
//---------------------------------------------------------

class PlayersManager {
	
	protected:

		PlayersList Players;

	public:

		PlayersManager() {}
		~PlayersManager() {}

		//------------------------------------------------------------------------------------
		//---------------------------------------------------------
		//					Save Player
		//---------------------------------------------------------

		unsigned int AddPlayer(CPlayer *NPlayer, unsigned int &CharID) {

			unsigned int PlayerID = GetPlayersCount() + (10 + CharID);
			Players.insert(std::make_pair(PlayerID, NPlayer));

			return PlayerID;
		}

		//------------------------------------------------------------------------------------
		//---------------------------------------------------------
		//					Remove Player
		//---------------------------------------------------------

		void RemovePlayer(int PlayerID) {

			if (Players.size() > 0){
				FREE(Players.find(PlayerID)->second);
				Players.erase(PlayerID);
			}
		}

		//------------------------------------------------------------------------------------

		CPlayer *GetPlayer(int PlayerID) { return Players.find(PlayerID)->second; }
		unsigned int	 GetPlayersCount() { return Players.size(); }
};

