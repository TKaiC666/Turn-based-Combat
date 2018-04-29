#pragma once
#include"Command.h"
#include"Battle_System.h"
#include"Character.h"
//解除女神化狀態 變回 普通狀態  
class Battle_System;
class Character;
class Command_HDD_Off : public Command
{
private:
	Battle_System* battle_system;
	Character* character;
public:
	Command_HDD_Off(Battle_System* input_battle_system, Character* input_character);
	void Fire_Command();
};
