#include"Game_System.h"
#include"Item_Nep_Bull.h"
#include"Item_Healing_Field.h"
#include"Item_Uni_Curry.h"
Game_System::Game_System()
{
	credits = 10000;

	main_menu_system = new Main_Menu_System(this);
	character_selection_system = new Character_Selection_System(this);
	shop_system = new Shop_System(this);
	colosseum_system = new Colosseum_System(this);
	battle_system = new Battle_System(this);

	current_battle = NULL;

	current_system = main_menu_system;

	characters[0] = new Noire((Battle_System*)battle_system);
	characters[1] = new Uni((Battle_System*)battle_system);
	characters[2] = new IF((Battle_System*)battle_system);

	character_slot[0] = characters[0];
	character_slot[1] = characters[1];
	character_slot[2] = characters[2];
	character_slot[3] = NULL;
	character_slot[4] = NULL;
	character_slot[5] = NULL;

	items[0] = new Item_Nep_Bull();
	items[1] = new Item_Uni_Curry();
	items[2] = new Item_Healing_Field();

};

Character** Game_System::Get_Character_Slot()
{
	return character_slot;
};
void Game_System::Set_Current_Battle(Battle* target_battle)
{
	current_battle = target_battle;
};
Battle* Game_System::Get_Current_Battle()
{
	return current_battle;
};
int Game_System::GetCredits()
{
	return credits;
};
void Game_System::SetCredits(int target_credits)
{
	credits = target_credits;
};
void Game_System::Game_Run()
{
	while (true)
	{
		current_system->Run();
	}
};
Item** Game_System::GetItems()
{
	return items;
};
void Game_System::ChangeSystem(Interface_System* target_system)
{
	current_system = target_system;
};
Enemy** Game_System::Get_Enemy()
{
	return enemy;
};
Interface_System* Game_System::Get_Main_Menu_System()
{
	return main_menu_system;
};
Interface_System* Game_System::Get_Character_Selection_System()
{
	return character_selection_system;
};
Interface_System* Game_System::Get_Shop_System()
{
	return shop_system;
};
Interface_System* Game_System::Get_Colosseum_System()
{
	return colosseum_system;
};
Interface_System* Game_System::Get_Battle_System()
{
	return battle_system;
};
