#include"Character_Selection_System.h"

Character_Selection_System::Character_Selection_System(Game_System* input_game_system)
{
	clicked = false;
	clicked_index = 0;
	current_arrow_position = 0;
	character_pos[0].x = 0;
	character_pos[0].y = 0;
	character_pos[1].x = 24;
	character_pos[1].y = 0;
	character_pos[2].x = 48;
	character_pos[2].y = 0;
	character_pos[3].x = 0;
	character_pos[3].y = 22;
	character_pos[4].x = 24;
	character_pos[4].y = 22;
	character_pos[5].x = 48;
	character_pos[5].y = 22;
	arrow_pos[0].x = 10;
	arrow_pos[0].y = 11;
	arrow_pos[1].x = 34;
	arrow_pos[1].y = 11;
	arrow_pos[2].x = 58;
	arrow_pos[2].y = 11;
	arrow_pos[3].x = 10;
	arrow_pos[3].y = 21;
	arrow_pos[4].x = 34;
	arrow_pos[4].y = 21;
	arrow_pos[5].x = 58;
	arrow_pos[5].y = 21;
	game_system = input_game_system;
	character_slot = game_system->Get_Character_Slot();
};
void Character_Selection_System::Draw()
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	system("CLS");
	for (int j = 0; j < 6; j++)
	{
		if (NULL == character_slot[j]) continue;
		character_slot[j]->Draw_Simple(character_pos[j].x, character_pos[j].y);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	Gotoxy(0, 15);
	cout << "出戰區";
	Gotoxy(0, 16);
	for (int i = 0; i < 36; i++)
		cout << "─";
	Gotoxy(0, 17);
	cout << "休息區";


	if (clicked)SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0c);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(arrow_pos[current_arrow_position].x, arrow_pos[current_arrow_position].y);
	if (current_arrow_position<3) cout << "◢◣";
	else cout << "◥◤";
};
void Character_Selection_System::Update_Data(char key)
{
	switch (key)
	{
	case 'w':case'W':
		if (current_arrow_position > 2)current_arrow_position -= 3;
		break;
	case 's':case'S':
		if (current_arrow_position <= 2)current_arrow_position += 3;
		break;
	case 'd':case'D':
		if (current_arrow_position % 3 < 2)current_arrow_position++;
		break;
	case 'a':case'A':
		if (current_arrow_position % 3 > 0)current_arrow_position--;
		break;
	case 'g':case'G':
		game_system->ChangeSystem(game_system->Get_Main_Menu_System());
		break;
	case 'k':case'K':
		if (!clicked)
		{
			clicked_index = current_arrow_position;
			clicked = true;
		}
		else if (clicked)
		{
			Character* temp = character_slot[current_arrow_position];
			character_slot[current_arrow_position] = character_slot[clicked_index];
			character_slot[clicked_index] = temp;
			temp = NULL;
			clicked = false;
		}
		break;
	case'j':case'J':
		clicked = false;
		break;
	}
};