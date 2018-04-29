#pragma once
#include"Battle.h"
#include"Arfoire.h"
class Battle_Arfoire : public Battle
{
public:
	Battle_Arfoire();
	void Generate_Enemy(Enemy* enemy[3]);
};