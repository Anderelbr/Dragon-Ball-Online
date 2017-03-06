#include "stdafx.h"
#include "PlayerInventory.h"

//--------------------------------------------------------------------------------------
//					PlayerInventory - PlayerInventory.cpp
//--------------------------------------------------------------------------------------

PlayerInventory::PlayerInventory(uint &CID){

	this->CharID = CID;

	memset(&Items, 0, sizeof(Items));
	memset(&EquipmentItems, 0, sizeof(EquipmentItems));
}

PlayerInventory::~PlayerInventory(){}

//------------------------------------------------------------------------------------
//    LoadPlayerItems
//------------------------------------------------------------------------------------

void PlayerInventory::LoadPlayerItems () {

	App->GetDB()->Prepare("SELECT * FROM Items WHERE OwnerID = ? ORDER BY Place ASC");
	App->GetDB()->SetInt(1, CharID);

	App->GetDB()->Execute();
	App->GetDB()->NextField();
	
	this->ItemsCount = App->GetDB()->RowsCount();

	FOR(17) {
		EquipmentItems[i].ItemID = INVALID_TBLIDX;
	}

	if (ItemsCount > 0) {

		FOR(ItemsCount) {

			this->Items[i].Handle =			 App->GetDB()->GetInt("ItemID");
			this->Items[i].Tblidx =			 App->GetDB()->GetInt("Tblidx");
			this->Items[i].Place =			 App->GetDB()->GetInt("Place");
			this->Items[i].Slot =			 App->GetDB()->GetInt("Slot");
			this->Items[i].StackCount =		 App->GetDB()->GetInt("Count");
			this->Items[i].Rank =			 App->GetDB()->GetInt("Rank");
			this->Items[i].CurDur =			 App->GetDB()->GetInt("Durability");
			this->Items[i].Grade =			 App->GetDB()->GetInt("Grade");
			this->Items[i].BattleAttribute = App->GetDB()->GetInt("BattleAttribute");

			if (this->Items[i].Place == 7) {

				this->EquipmentItems[this->Items[i].Slot].ItemID =			this->Items[i].Tblidx;
				this->EquipmentItems[this->Items[i].Slot].Rank =			this->Items[i].Rank;
				this->EquipmentItems[this->Items[i].Slot].Grade =			this->Items[i].Grade;
				this->EquipmentItems[this->Items[i].Slot].BattleAttribute = this->Items[i].BattleAttribute;

				EquipedItemsCount++;
			}	
			
			App->GetDB()->NextField();
		}
	}
}