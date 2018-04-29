#pragma once

#include"Draw_Utility.h"
#include"Game_System.h"
#include"Battle_System.h"
#include"Skill.h"
class Game_System;
class Battle_System;
class Skill_Target_System : public Interface_Sub_System
{
private:
	Game_System* game_system;
	Battle_System* battle_system;
	int arrow_position_index;
	Position arrow_pos[3];
	int Get_Left_Enemy_Index();
	int Get_Right_Enemy_Index();
public:
	Skill_Target_System(Game_System* input_game_system, Battle_System* input_battle_system);
	void Update_Data(char key);
	void Draw();
	void Reset();
};