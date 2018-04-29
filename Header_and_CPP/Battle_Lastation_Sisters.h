#pragma once
#include"Battle.h"
#include"Fake_Noire.h"
#include"Fake_Uni.h"
class Battle_Lastation_Sisters : public Battle
{
public:
	Battle_Lastation_Sisters();
	void Generate_Enemy(Enemy* enemy[3]);
};