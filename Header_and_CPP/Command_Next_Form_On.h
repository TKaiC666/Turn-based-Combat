#pragma once
#include"Command.h"
#include"Battle_System.h"
#include"Character.h"
//從女神化狀態 變身成 Next Form狀態
class Battle_System;
class Character;
class Command_Next_Form_On : public Command
{
private:
	Battle_System* battle_system;
	Character* character;
public:
	Command_Next_Form_On(Battle_System* input_battle_system, Character* input_character);
	void Fire_Command();
};