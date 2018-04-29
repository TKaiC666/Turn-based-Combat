#include "Battle_Arforie.h"

Battle_Arfoire::Battle_Arfoire()
{
	name = "º¿³Ç±±§V";
	reward_credits = 5000;
};
void Battle_Arfoire::Generate_Enemy(Enemy* enemy[3])
{
	enemy[0] = NULL;
	enemy[1] = new Arfoire;
	enemy[2] = NULL;
};