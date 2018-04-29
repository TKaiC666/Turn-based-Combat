#include"Item_Target_System.h"


Item_Target_System::Item_Target_System(Game_System* input_game_system, Battle_System* input_battle_system)
{
	game_system = input_game_system;
	battle_system = input_battle_system;
	arrow_pos[0].x = 10;
	arrow_pos[0].y = 26;
	arrow_pos[1].x = 34;
	arrow_pos[1].y = 26;
	arrow_pos[2].x = 58;
	arrow_pos[2].y = 26;
	arrow_position_index = 0;
};
void Item_Target_System::Reset()
{
	Character** character_slot = game_system->Get_Character_Slot();
	//把箭頭指向最左邊友軍的位置
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL)
		{
			if (character_slot[i]->Get_HP() > 0)
			{
				arrow_position_index = i;
				break;
			}
		}
	}
};
int Item_Target_System::Get_Left_Ally_Index()
{
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = arrow_position_index - 1; i >= 0; i--)
	{
		if (character_slot[i] != NULL)
		{
			if (character_slot[i]->Get_HP() > 0)
			{
				return i;
			}
		}
	}
	return arrow_position_index;
};
int Item_Target_System::Get_Right_Ally_Index()
{
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = arrow_position_index + 1; i <= 2; i++)
	{
		if (character_slot[i] != NULL)
		{
			if (character_slot[i]->Get_HP() > 0)
			{
				return i;
			}
		}
	}
	return arrow_position_index;
};
void Item_Target_System::Draw()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	system("CLS");

	battle_system->Draw_Units_and_Active();
	Character** character_slot = game_system->Get_Character_Slot();
	Item* current_item = battle_system->Get_Current_Item();
	Target_Type target_type = current_item->GetTargetType();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	
	if (SINGLE_TARGET == current_item->GetTargetType())
	{
		Gotoxy(arrow_pos[arrow_position_index].x, arrow_pos[arrow_position_index].y);
		cout << "◥◤";
	}
	if (ALL == target_type) {
		for (int i = 0; i < 3; i++) {
			if (0 >= character_slot[i]->Get_HP()) continue;
			Gotoxy(arrow_pos[i].x, arrow_pos[i].y);
			cout << "◥◤";
		}
	}

};
void Item_Target_System::Update_Data(char key)
{
	Character** character_slot = game_system->Get_Character_Slot();
	Item* current_item = battle_system->Get_Current_Item();
	Target_Type target_type = current_item->GetTargetType();

	switch (key)
	{
	case'a': case'A':
		arrow_position_index -= arrow_position_index > Get_Left_Ally_Index() ? 1 : 0;
		break;
	case'd': case'D':
		arrow_position_index += arrow_position_index < Get_Right_Ally_Index() ? 1 : 0;
		break;
	case'k': case'K':
		//補單體
		if (target_type == SINGLE_TARGET)
		{
			character_slot[arrow_position_index]->Heal_Percentage(current_item->Get_HP_Recover_Percent());
			character_slot[arrow_position_index]->Recover_SP_Percentage(current_item->Get_SP_Recover_Percent());
		}
		//補全體
		else if (target_type == ALL)
		{
			for (int i = 0; i < 3; i++)
			{
				if (character_slot[i] != NULL)
				{
					if (character_slot[i]->Get_HP() > 0)
					{
						character_slot[i]->Heal_Percentage(current_item->Get_HP_Recover_Percent());
						character_slot[i]->Recover_SP_Percentage(current_item->Get_SP_Recover_Percent());
					}
				}
			}
		}
		//扣掉1個物品數量
		current_item->SetAmount(current_item->GetAmount() - 1);

		//目前單位的行動結束 交棒給往下一個單位
		battle_system->Add_Current_Active_Unit_Index();
		//如果是友軍的回合 則顯示可用指令供玩家選擇
		if (battle_system->Is_Ally_Turn())
		{
			battle_system->Get_Command_System()->Reset();
			battle_system->Change_Sub_System(battle_system->Get_Command_System());
		}
		//若是敵方回合 讓AI_System處理敵人的邏輯
		else
		{
			battle_system->Change_Sub_System(battle_system->Get_AI_System());
		}
		break;
	case'j': case'J':
		battle_system->Get_Item_System()->Reset();
		battle_system->Change_Sub_System(battle_system->Get_Item_System());
		break;
	case'g': case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}


};
