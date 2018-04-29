#pragma once
#include"Interface_system.h"
#include "Draw_Utility.h"
#include"Game_System.h"
#include"Item.h"
class Game_System;
class Shop_System : public Interface_System
{
private:
	Game_System* game_system;
	int iIndex;
	Item** items;
protected:
	Position diamond_posision;
	void Draw();
	void Update_Data(char key);
public:
	Shop_System(Game_System* input_game_system);
};