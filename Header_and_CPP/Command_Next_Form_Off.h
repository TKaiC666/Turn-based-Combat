#pragma once
#include"Command.h"
#include"Battle_System.h"
#include"Character.h"
//�qNext Form���A �ܦ^ ���q���A
class Battle_System;
class Character;
class Command_Next_Form_Off : public Command
{
private:
	Battle_System* battle_system;
	Character* character;
public:
	Command_Next_Form_Off(Battle_System* input_battle_system, Character* input_character);
	void Fire_Command();
};