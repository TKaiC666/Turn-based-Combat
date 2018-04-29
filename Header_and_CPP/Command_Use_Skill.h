#pragma once
#include"Command.h"
#include"Battle_System.h"
#include"Character.h"
class Battle_System;
class Character;
class Command_Use_Skill : public Command
{
private:
	Battle_System* battle_system;
	Character* character;
public:
	Command_Use_Skill(Battle_System* input_battle_system, Character* input_character);
	void Fire_Command();
};