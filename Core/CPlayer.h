#pragma once
#include "stdafx.h"
#include "NtlSfx.h"
#include "Packets.h"
#include "PlayerInventory.h"


//--------------------------------------------------------------------------------------
//					CPlayer - CPlayer.h
//--------------------------------------------------------------------------------------

class CPlayer {

	public:

		CPlayer(uint &CID);
		~CPlayer();

		//------------------------------------------------------------------------------------
		//---------------------------------------------------------
		//					SAVE METHODS
		//---------------------------------------------------------

		void			  SetPlayerName(std::string Pname)  { this->PlayerName = Pname; }
		void			  SetPosition(Vector3 Pos)			{ this->Position = Pos; }
		void			  SetRotation(Vector3 Rot)			{ this->Rotation = Rot; }	   
		void			  SetWorldTable(uint Wt)			{ this->WorldTable = Wt; }
		void			  SetWorldID(uint Wi)				{ this->WorldID = Wi; }
		void			  SetMapInfoIDX(uint Midx)			{ this->MapInfoIDX = Midx; }

		//------------------------------------------------------------------------------------
		//---------------------------------------------------------
		//					GET METHODS
		//---------------------------------------------------------

		std::string		  &GetPlayerName() { return this->PlayerName; }  
		uint			  &GetWorldTable() { return this->WorldTable; }
		uint			  &GetWorldID()    { return this->WorldID; }
		uint			  &GetMapInfoIDX() { return this->MapInfoIDX; }
		Vector3			  &GetPosition()   { return this->Position; }
		Vector3			  &GetRotation()   { return this->Rotation; }
		AvatarProfile     &GetProfile()	   { return this->Profile; }
		AvatarStateInfo   &GetState()	   { return this->State; }
		AvatarAttributes  &GetAttributes() { return this->Attributes; }
		ModelData         &GetModelData()  { return this->ModelInfo; }
		PlayerInventory   &GetInventory()  { return this->Inventory; }

	private:
					
		PlayerInventory  Inventory;

		std::string		 PlayerName;
		uint			 CharID;
						 
		uint			 WorldTable;
		uint			 WorldID;
		uint			 MapInfoIDX;
						 
		Vector3			 Position;
		Vector3			 Rotation;

		/* Principal Deps */
		
		AvatarProfile		Profile;
		AvatarStateInfo     State;
		AvatarAttributes    Attributes;
		ModelData			ModelInfo;

		//------------------------------------------------------------------------------------
		//---------------------------------------------------------
		//					METHODS
		//---------------------------------------------------------

		void		  CreateProfile();
		void		  FIllProfile(PlayerTable &NData);
		void		  FillState(PlayerTable &NData);
		void		  FillAttributes(PlayerTable &NData);

};

