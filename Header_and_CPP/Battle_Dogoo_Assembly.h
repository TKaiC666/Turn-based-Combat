#pragma once
#include"Battle.h"
#include"Dogoo.h"
class Battle_Dogoo_Assembly : public Battle
{
public:
	Battle_Dogoo_Assembly();
	void Generate_Enemy(Enemy* enemy[3]);
};