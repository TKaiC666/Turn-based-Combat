#pragma once
#include"Interface_system.h"
#include "Draw_Utility.h"
#include"Game_System.h"
#include"Battle.h"
#include"Battle_Dogoo_Assembly.h"
#include"Battle_Eggplant_Assembly.h"
#include"Battle_Arforie.h"
#include"Battle_Lastation_Sisters.h"
class Game_System;
//競技場系統
class Colosseum_System : public Interface_System
{
private:
	Enemy** enemy_input;
	int iIndex;
	Battle* battle[4];
	Game_System* game_system;
protected:
	Position diamond_posision;
	void Draw();
	void Update_Data(char key);
public:
	Colosseum_System(Game_System* input_game_system);

};