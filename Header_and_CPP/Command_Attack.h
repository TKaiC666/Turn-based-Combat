#pragma once
#include"Command.h"
#include"Battle_System.h"
class Battle_System;
class Command_Attack : public Command
{
private:
	Battle_System* battle_system;
public:
	Command_Attack(Battle_System* input_battle_system);
	void Fire_Command();
};