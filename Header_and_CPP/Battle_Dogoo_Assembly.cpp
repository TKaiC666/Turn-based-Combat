#include"Battle_Dogoo_Assembly.h"

Battle_Dogoo_Assembly::Battle_Dogoo_Assembly()
{
	name = "¥vµÜª¯¤j¶°¦X";
	reward_credits = 1500;
};

void Battle_Dogoo_Assembly::Generate_Enemy(Enemy* enemy[3])
{
	enemy[0] = new Dogoo;
	enemy[1] = new Dogoo;
	enemy[2] = new Dogoo;
};