#include"Battle_Eggplant_Assembly.h"

Battle_Eggplant_Assembly::Battle_Eggplant_Assembly()
{
	name = "�X�l�j���X";
	reward_credits = 2500;
};

void Battle_Eggplant_Assembly::Generate_Enemy(Enemy* enemy[3])
{
	enemy[0] = new Eggplant;
	enemy[1] = new Eggplant;
	enemy[2] = new Eggplant;
};