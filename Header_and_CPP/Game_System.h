#pragma once
#include"Interface_System.h"
#include"Main_Menu_System.h"
#include"Character_Selection_System.h"
#include"Shop_System.h"
#include"Battle_System.h"
#include"Colosseum_System.h"
#include"Character.h"
#include"Item.h"
#include"Battle.h"
#include"Enemy.h"
#include"Noire.h"
#include"Uni.h"
#include"IF.h"

class Game_System
{
private:
	//新增程式碼


	Character* characters[3];
	Character* character_slot[6];

	Enemy* enemy[3];
	Battle* current_battle;

	int credits;//擁有金錢
	Item* items[3];
	
	Interface_System* main_menu_system;
	Interface_System* character_selection_system;
	Interface_System* shop_system;
	Interface_System* colosseum_system;
	Interface_System* battle_system;
	Interface_System* current_system;
public:
	Game_System();

	void Game_Run();

	Item** GetItems();
	int GetCredits();
	void SetCredits(int target_credits);
	//state pattern

	//透過這個方法來改變目前的系統  例如從主選單系統變到商店系統
	void ChangeSystem(Interface_System* target_system);

	void Set_Current_Battle(Battle* target_battle);

	Character** Get_Character_Slot();

	Enemy** Get_Enemy();

	Battle* Get_Current_Battle();
	Interface_System* Get_Main_Menu_System();
	Interface_System* Get_Character_Selection_System();
	Interface_System* Get_Shop_System();
	Interface_System* Get_Colosseum_System();
	Interface_System* Get_Battle_System();
	
	

};