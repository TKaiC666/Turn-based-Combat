#include"Battle_Lastation_Sisters.h"

Battle_Lastation_Sisters::Battle_Lastation_Sisters()
{
	name = "Lastation©n©f";
	reward_credits = 10000;
};

void Battle_Lastation_Sisters::Generate_Enemy(Enemy* enemy[3])
{
	enemy[0] = new Fake_Noire;
	enemy[1] = new Fake_Uni;
	enemy[2] = NULL;

};