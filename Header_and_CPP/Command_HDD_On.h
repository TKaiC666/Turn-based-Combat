#pragma once
#include"Command.h"
#include"Battle_System.h"
#include"Character.h"
//�q���q���A �ܨ��� �k���ƪ��A
class Battle_System;
class Character;
class Command_HDD_On : public Command
{
private:
	Battle_System* battle_system;
	Character* character;
public:
	Command_HDD_On(Battle_System* input_battle_system, Character* input_character);
	void Fire_Command();
}; 
