#include"Win_System.h"

Win_System::Win_System(Game_System* input_game_system, Battle_System* input_battle_system)
{
	game_system = input_game_system;
	battle_system = input_battle_system;
};
void Win_System::Draw()
{
	Draw_Utility::Draw_Border(24, 16, 28, 4);
	Gotoxy(26, 17);
	cout << "YOU WIN!";
	Gotoxy(26, 18);
	int reward_credits = game_system->Get_Current_Battle()->GetReward_Credits();
	game_system->SetCredits(game_system->GetCredits() + reward_credits);
	cout << "Àò±o" + to_string(reward_credits) + "Credits!";

};
void Win_System::Update_Data(char key)
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
