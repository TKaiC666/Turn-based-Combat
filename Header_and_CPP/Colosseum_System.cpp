#include"Colosseum_System.h"
#define DIAMOND_BATTLE_0_Y 8
Colosseum_System::Colosseum_System(Game_System* input_game_system)
{
	battle[0] = new Battle_Dogoo_Assembly;
	battle[1] = new Battle_Eggplant_Assembly;
	battle[2] = new Battle_Arfoire;
	battle[3] = new Battle_Lastation_Sisters;
	game_system = input_game_system;
	enemy_input = game_system->Get_Enemy();
	diamond_posision.x = 10;
	diamond_posision.y = DIAMOND_BATTLE_0_Y;
};
void Colosseum_System::Draw()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	system("CLS");
	Draw_Utility::Draw_Border(0, 0, 12, 3);
	Gotoxy(2, 1);
	cout << "競技場";
	Draw_Utility::Draw_Border(12, 4, 44, 3);
	Gotoxy(14, 5);
	cout << "戰鬥名稱";
	Gotoxy(44, 5);
	cout << "報酬";

	for (int i = 7, j = 0; j<4; i += 3, j++)
	{
		Draw_Utility::Draw_Border(12, i, 44, 3);
		Gotoxy(14, i + 1);
		cout << battle[j]->GetName();
		Gotoxy(44, i + 1);
		cout << battle[j]->GetReward_Credits();
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(diamond_posision.x, diamond_posision.y);
	cout << "◆";
};
void Colosseum_System::Update_Data(char key)
{
	switch (key)
	{
	case'W':case'w':
		diamond_posision.y = diamond_posision.y > 10 ? diamond_posision.y - 3 : diamond_posision.y;
		iIndex = iIndex > 0 ? iIndex - 1 : iIndex;
		break;
	case'S':case's':
		diamond_posision.y = diamond_posision.y < 16 ? diamond_posision.y + 3 : diamond_posision.y;
		iIndex = iIndex < 3 ? iIndex + 1 : iIndex;
		break;
	case'K':case'k':
		battle[iIndex]->Generate_Enemy(enemy_input);
		game_system->Set_Current_Battle(battle[iIndex]);
		game_system->ChangeSystem(game_system->Get_Battle_System());
		break;
	case'G':case'g':
		game_system->ChangeSystem(game_system->Get_Main_Menu_System());
		break;
	}
};