#pragma once
#include"Interface_Sub_System.h"
#include"Game_System.h"
#include"Battle_System.h"
class Game_System;
class Battle_System;
class Skill_System : public Interface_Sub_System
{
private:
	Game_System* game_system;
	Battle_System* battle_system;
	int current_skill_index;
	Position diamond_position;
public:
	Skill_System(Game_System* input_game_system, Battle_System* input_battle_system);
	void Update_Data(char key);
	void Draw();
	void Reset();
};