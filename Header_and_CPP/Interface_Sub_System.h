#pragma once
/*#include"Game_System.h"
#include"Battle_System.h"

class Battle_System;
class Game_System;*/
class Interface_Sub_System
{
/*protected:
	Game_System* game_system;
	Battle_System* battle_system;*/
public:
//	Interface_Sub_System();
	//Interface_Sub_System(Game_System* input_game_system, Battle_System* input_battle_system);
	virtual void Update_Data(char key) = 0;
	virtual void Draw() = 0;
	virtual void Reset();
	
};