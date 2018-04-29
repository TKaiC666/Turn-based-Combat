#include"Skill_System.h"


Skill_System::Skill_System(Game_System* input_game_system, Battle_System* input_battle_system)
{
	game_system = input_game_system;
	battle_system = input_battle_system;
	diamond_position.x = 8;
	diamond_position.y = 16;
	current_skill_index = 0;
};
void Skill_System::Reset()
{
	diamond_position.x = 8;
	diamond_position.y = 16;
	current_skill_index = 0;
};
void Skill_System::Draw()
{
	Character** character_slot = game_system->Get_Character_Slot();
	int current_active_unit_index = battle_system->Get_Current_Active_Unit_Index();
	Skill** skills = character_slot[current_active_unit_index]->Get_Skill();
	int skill_number = character_slot[current_active_unit_index]->Get_Skill_Number();

	battle_system->Draw_Units_and_Active();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	Draw_Utility::Draw_Border(6, 14, 56, 5);

	Gotoxy(10, 15);
	cout << "招式名稱";
	Gotoxy(30, 15);
	cout << "消耗SP";
	Gotoxy(40, 15 );
	cout << "招式威力";
	Gotoxy(50, 15 );
	cout << "招式目標";
	for (int i = 0; i < skill_number; i++)
	{
		Gotoxy(10, 15+i+1);
		cout << character_slot[current_active_unit_index]->Get_Skill()[i]->Get_Name();
		Gotoxy(30, 15 + i + 1);
		cout << character_slot[current_active_unit_index]->Get_Skill()[i]->Get_SP_Cost();
		Gotoxy(40, 15 + i + 1);
		cout << character_slot[current_active_unit_index]->Get_Skill()[i]->Get_Power();
		Gotoxy(50, 15 + i + 1);
		if(SINGLE_TARGET == character_slot[current_active_unit_index]->Get_Skill()[i]->Get_TargetType())cout << "敵方單體";
		else cout << "敵方全體";
	}

	//畫出黃色菱形
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(diamond_position.x, diamond_position.y + current_skill_index);
	cout << "◆";
	


};

void Skill_System::Update_Data(char key)
{
	Character** character_slot = game_system->Get_Character_Slot();
	int current_active_unit_index = battle_system->Get_Current_Active_Unit_Index();
	Skill** skills = character_slot[current_active_unit_index]->Get_Skill();
	int skill_number = character_slot[current_active_unit_index]->Get_Skill_Number();

	switch (key)
	{
	case's': case'S':
		current_skill_index += current_skill_index < skill_number-1 ? 1 : 0;
		break;
	case'w': case'W':
		current_skill_index -= current_skill_index > 0 ? 1 : 0;
		break;
	case'k': case'K':
		//如果剩餘的sp足夠才能施放
		if (character_slot[current_active_unit_index]->Get_SP() >= skills[current_skill_index]->Get_SP_Cost())
		{
			battle_system->Set_Current_Skill(skills[current_skill_index]);
			battle_system->Get_Skill_Target_System()->Reset();
			battle_system->Change_Sub_System(battle_system->Get_Skill_Target_System());
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

