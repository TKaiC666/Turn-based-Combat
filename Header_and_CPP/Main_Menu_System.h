#pragma once
#include"Interface_system.h"
#include "Draw_Utility.h"
#include"Game_System.h"
class Game_System;
class Main_Menu_System: public Interface_System
{
private:
	Game_System* game_system;
protected:
	Position diamond_posision;
	//╠юб╫(override)
	void Update_Data(char key);
	//╠юб╫(override)
	void Draw();
public:
	Main_Menu_System(Game_System*  input_game_system);
//	Main_Menu_System(Game_System * const game_system);
};