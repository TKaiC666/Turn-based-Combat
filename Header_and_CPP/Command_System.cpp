#include"Command_System.h"

//讓玩家選擇指令用的子系統
//像是
//攻擊 使用技能 使用道具 女神化 解除女神化 Next Form化 解除Next Form化
Command_System::Command_System(Game_System* input_game_system, Battle_System* input_battle_system)
{
	game_system = input_game_system;
	battle_system = input_battle_system;
	diamond_position.x = 8;
	diamond_position.y = 18;
	current_command_index = 0;
};

void Command_System::Reset()
{
	diamond_position.x = 8;
	diamond_position.y = 18;
	current_command_index = 0;
};
void Command_System::Draw()
{
	Battle* battle = game_system->Get_Current_Battle();
	Enemy** enemy = game_system->Get_Enemy();
	Character** character_slot = game_system->Get_Character_Slot();
	int current_active_unit_index = battle_system->Get_Current_Active_Unit_Index();
	int index = battle_system->Get_Current_Active_Unit_Index();

	battle_system->Draw_Units_and_Active();
	
	//畫出指令 攻擊 道具 技能...
	character_slot[current_active_unit_index]->Draw_Command(6, 17);

	//畫出黃色菱形
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(diamond_position.x, diamond_position.y + current_command_index);
	cout << "◆";
};

void Command_System::Update_Data(char key)
{
	//int command_index = (diamond_position.y - 20) / 3;
	
	Character** character_slot = game_system->Get_Character_Slot();
	int character_index = battle_system->Get_Current_Active_Unit_Index();
	Command_Set* command_set = character_slot[character_index]->Get_CommandSet();
	int command_number = command_set->Get_Command_Number();
	switch (key)
	{
		case's': case'S':
			if (current_command_index < command_number - 1)
			{
				current_command_index++;
			}
			break;
		case'w': case'W':
			if (current_command_index > 0 )
			{
				current_command_index--;
			}
			break;
		case'k': case'K':
			
			command_set->Get_Command(current_command_index)->Fire_Command();
			break;
		case 'g':case'G':
			battle_system->Reset();
			game_system->ChangeSystem(game_system->Get_Colosseum_System());
			break;
	}
};

