#pragma once

#include"Interface_system.h"
#include"Game_System.h"
#include<iostream>
#include<string>
#include <windows.h>
#include <conio.h>
#include"Noire.h"
#include"Icon_Uni.h"
#include"Icon_Noire.h"
#include"Icon_IF.h"

#include"Icons.h"
#include"Character.h"
#include"Draw_Utility.h"
using namespace std;
class Game_System;
class Character_Selection_System: public Interface_System
{
	bool clicked;
	int clicked_index;
	Character** character_slot;
private:
	int current_arrow_position;
	Position character_pos[6];
	Position arrow_pos[6];
	Game_System* game_system;
protected:
	void Draw();
	void Update_Data(char key);
public:
	Character_Selection_System(Game_System* input_game_system);
};
