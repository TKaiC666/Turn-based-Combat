#include"Shop_System.h"
#define DIAMOND_ITEM_0_Y 8
Shop_System::Shop_System(Game_System* input_game_system)
{
	game_system = input_game_system;
	diamond_posision.x = 10;
	diamond_posision.y = DIAMOND_ITEM_0_Y;
	items = game_system->GetItems();
	iIndex = 0;

};
void Shop_System::Draw()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	system("CLS");
	Draw_Utility::Draw_Border(0, 0, 8, 3);
	Gotoxy(2, 1);
	cout << "SHOP";
	Draw_Utility::Draw_Border(12, 4, 44, 3);
	Gotoxy(14, 5);
	cout << "名稱";
	Gotoxy(34, 5);
	cout << "價格";
	Gotoxy(44, 5);
	cout << "持有數量";

	for (int i = 7, j = 0; j<3; i += 3, j++)
	{
		Draw_Utility::Draw_Border(12, i, 44, 3);
		Gotoxy(14, i + 1);
		cout << items[j]->GetName();
		Gotoxy(34, i + 1);
		cout << items[j]->GetCost();
		Gotoxy(44, i + 1);
		cout << items[j]->GetAmount();
	}

	Draw_Utility::Draw_Border(12, 19, 34, 3);
	Gotoxy(14, 20);
	cout << "Credits: " << game_system->GetCredits();

	Draw_Utility::Draw_Border(12, 23, 44, 3);
	Gotoxy(14, 24);
	cout << items[iIndex]->GetDescription();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(diamond_posision.x, diamond_posision.y);
	cout << "◆";
};

void Shop_System::Update_Data(char key)
{

	switch (key)
	{
	case'W':case'w':
		diamond_posision.y = diamond_posision.y > 8 ? diamond_posision.y - 3 : diamond_posision.y;
		iIndex = iIndex > 0 ? iIndex - 1 : iIndex;
		break;
	case'S':case's':
		diamond_posision.y = diamond_posision.y < 14 ? diamond_posision.y + 3 : diamond_posision.y;
		iIndex = iIndex < 2 ? iIndex + 1 : iIndex;
		break;
	case'K':case'k':
		if (game_system->GetCredits() >= items[iIndex]->GetCost())
		{
			items[iIndex]->SetAmount(items[iIndex]->GetAmount() + 1);
			game_system->SetCredits(game_system->GetCredits() - items[iIndex]->GetCost());
		}
		break;
	case'G':case'g':
		game_system->ChangeSystem(game_system->Get_Main_Menu_System());
		break;
	}
};