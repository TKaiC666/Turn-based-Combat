#include"Main_Menu_System.h"

Main_Menu_System::Main_Menu_System(Game_System * input_game_system)
{
	game_system = input_game_system;
	diamond_posision.x = 2;
	diamond_posision.y = 1;
};
void Main_Menu_System::Update_Data(char key)
{
	switch (key)
	{
	case'W':case'w':
		diamond_posision.y = diamond_posision.y > 1 ? diamond_posision.y - 3 : diamond_posision.y;
		break;
	case'S':case's':
		diamond_posision.y = diamond_posision.y < 7 ? diamond_posision.y + 3 : diamond_posision.y;
		break;
	case'K':case'k':
		if (diamond_posision.y == 1)
		{
			game_system->ChangeSystem(game_system->Get_Character_Selection_System());
		}
		else if (diamond_posision.y == 4)
		{
			game_system->ChangeSystem(game_system->Get_Shop_System());
		}
		else if (diamond_posision.y == 7)
		{
			game_system->ChangeSystem(game_system->Get_Colosseum_System());
		}
		break;
	}
};
void Main_Menu_System::Draw()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	system("CLS");
	Draw_Utility::Draw_Border(4, 0, 20, 3);
	Gotoxy(6, 1);
	cout << "隊伍組成";
	Draw_Utility::Draw_Border(4, 3, 20, 3);
	Gotoxy(6, 4);
	cout << "商店";
	Draw_Utility::Draw_Border(4, 6, 20, 3);
	Gotoxy(6, 7);
	cout << "競技場";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(diamond_posision.x, diamond_posision.y);
	cout << "◆";
};