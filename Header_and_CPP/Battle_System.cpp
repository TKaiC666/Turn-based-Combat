#include"Battle_System.h"

//戰鬥系統，在選完1個競技場戰鬥後會進入的系統
//玩家可以使用提供的指令來戰鬥
Battle_System::Battle_System(Game_System* input_game_system)
{
	game_system = input_game_system;
	initialized = false;
	current_active_unit_index = 0;
	for (int i = 0; i < 3; i++)
	{
		draw_active_position[i].x = 8 + 24 * i;
		draw_active_position[i].y = 27;
	}
	for (int i = 3; i < 6; i++)
	{
		draw_active_position[i].x = 8 + 24 * (i - 3);
		draw_active_position[i].y = 0;
	}
	command_system = new Command_System(input_game_system, this);
	item_system = new Item_System(input_game_system, this);
	skill_system = new Skill_System(input_game_system, this);
	attack_target_system = new Attack_Target_System(input_game_system, this);
	item_target_system = new Item_Target_System(input_game_system, this);
	skill_target_system = new Skill_Target_System(input_game_system, this);
	ai_system = new AI_System(input_game_system, this);
	win_system = new Win_System(input_game_system, this);
	lose_system = new Lose_System(input_game_system, this);
	current_sub_system = command_system;
};

//回傳目前行動中(頭上需顯示亮青色ACTIVE)的角色
//0 1 2代表第1 2 3個玩家角色(從左數到右)
//3 4 5代表第1 2 3個敵方角色(從左數到右)
int Battle_System::Get_Current_Active_Unit_Index()
{
	return current_active_unit_index;
};
//交棒給下一個角色
void Battle_System::Add_Current_Active_Unit_Index()
{
	Character** character_slot = game_system->Get_Character_Slot();
	Enemy** enemy = game_system->Get_Enemy();
	//取得下一個非NULL也沒死的角色，並把行動權交給他
	while (true)
	{
		current_active_unit_index = current_active_unit_index + 1 > 5 ? 0 : current_active_unit_index + 1;
		if (Is_Ally_Turn())
		{
			if (character_slot[current_active_unit_index] != NULL)
			{
				if (character_slot[current_active_unit_index]->Get_HP() > 0)
				{
					break;
				}
			}
		}
		else
		{
			if (enemy[current_active_unit_index - 3] != NULL)
			{
				if (enemy[current_active_unit_index - 3]->Get_HP() > 0)
				{
					break;
				}
			}
		}
	}
};
//取得友軍目前存活數量
int Battle_System::Get_Ally_Alive_Count()
{
	int count = 0;
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL )
		{
			if(character_slot[i]->Get_HP() > 0)
				count++;
		}
	}
	return count;
};
//取得敵軍目前存活數量
int Battle_System::Get_Enemy_Alive_Count()
{

	int count = 0;
	Enemy** enemy = game_system->Get_Enemy();
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->Get_HP() > 0)
				count++;
		}
	}
	return count;
};
//初始化，把角色移到第1個活著的角色的位置
//因為最左邊可能沒有角色，所以最左邊未必是起始行動的角色
void Battle_System::Initialize()
{
	initialized = true;
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL)
		{
			if (character_slot[i]->Get_HP() > 0)
			{
				current_active_unit_index = i;
				break;
			}
		}
	}
};
//重設，把該初始化的部份都初始化
void Battle_System::Reset()
{
	initialized = false;
	current_active_unit_index = 0;
	current_sub_system = command_system;
	command_system->Reset();
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL)
		{
			character_slot[i]->SetHP(character_slot[i]->Get_Max_HP());
			character_slot[i]->SetSP(character_slot[i]->Get_Max_SP());
			character_slot[i]->Transform_to_Normal();
		}
	}
};
//畫出所有角色，並在目前行動角色上方邊框畫出亮青色的ACTIVE
void Battle_System::Draw_Units_and_Active()
{
	Enemy** enemy = game_system->Get_Enemy();
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i] != NULL && enemy[i]->Get_HP()>0)
		{
			enemy[i]->Draw(0 + i * 24, 0);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL)
		{
			character_slot[i]->Draw(0 + i * 24, 27);
		}
	}
	//在目前行動角色的上方邊框，畫出亮青色ACTIVE
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
	int x = draw_active_position[current_active_unit_index].x;
	int y = draw_active_position[current_active_unit_index].y;
	Gotoxy(x, y);
	cout << "ACTIVE";
};

//如果目前輪到玩家角色行動，就回傳true
bool Battle_System::Is_Ally_Turn()
{
	if (current_active_unit_index >= 0 && current_active_unit_index <= 2)
		return true;
	else
		return false;
};
//如果目前輪到敵方角色行動，就回傳true
bool Battle_System::Is_Enemy_Turn()
{
	return !Is_Ally_Turn();
};
//畫出畫面
void Battle_System::Draw()
{
	if (!initialized)
	{
		Initialize();
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	system("CLS");
	//轉交給子系統去畫畫面
	current_sub_system->Draw();
	
};
//處理鍵盤輸入
void Battle_System::Update_Data(char key)
{
	//轉交給子系統去處理鍵盤輸入
	current_sub_system->Update_Data(key);
	
};
//設定目前使用的技能，供Skill_System與Skill_Target_System使用
void Battle_System::Set_Current_Skill(Skill* input_skill)
{
	current_skill = input_skill;
};
//取得目前使用的技能，供Skill_System與Skill_Target_System使用
Skill* Battle_System::Get_Current_Skill()
{
	return current_skill;
};
//設定目前使用的道具，供供Item_System與Item_Target_System使用
void Battle_System::Set_Current_Item(Item* input_item)
{
	current_item = input_item;
};
//取得目前使用的道具，供供Item_System與Item_Target_System使用
Item* Battle_System::Get_Current_Item()
{
	return current_item;
};
//更改子系統為目標子系統
void Battle_System::Change_Sub_System(Interface_Sub_System* target_sub_system)
{
	current_sub_system = target_sub_system;
};
//下面都是一堆getter
Interface_Sub_System* Battle_System::Get_Command_System()
{
	return command_system;
};
Interface_Sub_System* Battle_System::Get_Skill_System()
{
	return skill_system;
};
Interface_Sub_System* Battle_System::Get_Item_System()
{
	return item_system;
};
Interface_Sub_System* Battle_System::Get_Attack_Target_System()
{
	return attack_target_system;
};
Interface_Sub_System* Battle_System::Get_Item_Target_System()
{
	return item_target_system;
};
Interface_Sub_System* Battle_System::Get_Skill_Target_System()
{
	return skill_target_system;
};
Interface_Sub_System* Battle_System::Get_Win_System()
{
	return win_system;
};
Interface_Sub_System* Battle_System::Get_Lose_System()
{
	return lose_system;
};
Interface_Sub_System* Battle_System::Get_AI_System()
{
	return ai_system;
};
