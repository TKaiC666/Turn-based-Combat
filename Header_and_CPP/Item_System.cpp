#include"Item_System.h"


Item_System::Item_System(Game_System* input_game_system, Battle_System* input_battle_system)
{
	game_system = input_game_system;
	battle_system = input_battle_system;
	diamond_position.x = 8;
	diamond_position.y = 16;
	current_item_index = 0;
};
void Item_System::Reset()
{
	diamond_position.x = 8;
	diamond_position.y = 16;
	current_item_index = 0;
};
void Item_System::Draw()
{
	Character** character_slot = game_system->Get_Character_Slot();
	int current_active_unit_index = battle_system->Get_Current_Active_Unit_Index();
	Item** items = game_system->GetItems();

	battle_system->Draw_Units_and_Active();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);

	
	Draw_Utility::Draw_Border(6, 14, 56, 6);

	Gotoxy(10, 15);
	cout << "道具名稱";
	Gotoxy(40, 15);
	cout << "持有數量";
	Gotoxy(50, 15);
	cout << "使用目標";
	for (int i = 0; i < 3; i++)
	{
		Gotoxy(10, 15 + i + 1);
		cout << items[i]->GetName();
		Gotoxy(40, 15 + i + 1);
		cout << items[i]->GetAmount();
		Gotoxy(50, 15 + i + 1);
		if(SINGLE_TARGET==items[i]->GetTargetType()) cout<<"友方單體";
		else cout << "友方全體"; 
		Draw_Utility::Draw_Border(6, 21, 56, 3);
		Gotoxy(10, 22);
		cout << items[current_item_index]->GetDescription();
	}

	

	//畫黃色菱形
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(diamond_position.x, diamond_position.y + current_item_index);
	cout << "◆";
	
};

void Item_System::Update_Data(char key)
{
	Character** character_slot = game_system->Get_Character_Slot();
	int current_active_unit_index = battle_system->Get_Current_Active_Unit_Index();
	Item** items = game_system->GetItems();


	switch (key)
	{
	case's': case'S':
		current_item_index += current_item_index < 2 ? 1 : 0;
		break;
	case'w': case'W':
		current_item_index -= current_item_index > 0 ? 1 : 0;
		break;
	case'k': case'K':
		//如果道具剩餘的數量 > 0才能使用
		if (items[current_item_index]->GetAmount() > 0)
		{
			//轉交給道具指定目標系統
			battle_system->Set_Current_Item(items[current_item_index]);
			battle_system->Get_Item_Target_System()->Reset();
			battle_system->Change_Sub_System(battle_system->Get_Item_Target_System());
		}
		break;
	case'j': case'J':
		battle_system->Get_Command_System()->Reset();
		battle_system->Change_Sub_System(battle_system->Get_Command_System());
		break;
	case 'g':case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}
};

