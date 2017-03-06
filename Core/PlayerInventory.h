#pragma once
#include "stdafx.h"
#include "NtlSfx.h"
#include "Packets.h"

//--------------------------------------------------------------------------------------
//					PlayerInventory - PlayerInventory.h
//--------------------------------------------------------------------------------------

class PlayerInventory{

	private:

		uint CharID;
		uint ItemsCount;
		uint EquipedItemsCount;

		ItemProfile Items[128];
		ItemBrief   EquipmentItems[17];

	public:

		PlayerInventory(uint &CID);
		~PlayerInventory();

		//-----------------------------------------------------------------------------------

		void		 LoadPlayerItems();

		uint		 &GetItemsCount()		 { return this->ItemsCount; }
		uint         &GetEquipedItemsCount() { return this->EquipedItemsCount; }
		ItemProfile *GetPlayerItems()		 { return this->Items; }
		ItemBrief   *GetEquipedItems()		 { return this->EquipmentItems; }
};

