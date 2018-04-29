#pragma once
#include"Battle.h"
#include"Eggplant.h"
class Battle_Eggplant_Assembly : public Battle
{
public:
	Battle_Eggplant_Assembly();
	void Generate_Enemy(Enemy* enemy[3]);
};