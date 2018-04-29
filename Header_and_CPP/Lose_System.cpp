#include"Lose_System.h"

//玩家全滅時的子系統
//簡單畫出YOU LOSE!
Lose_System::Lose_System(Game_System* input_game_system, Battle_System* input_battle_system)
{
	game_system = input_game_system;
	battle_system = input_battle_system;
};
void Lose_System::Draw()
{
	Draw_Utility::Draw_Border(24, 16, 28, 3);
	Gotoxy(26, 17);
	cout << "YOU LOSE!";

};
void Lose_System::Update_Data(char key)
{
	switch (key)
	{
	case 'k':case'K':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	case 'g':case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}
};
