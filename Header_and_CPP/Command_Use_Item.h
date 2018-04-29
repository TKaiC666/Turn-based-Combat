#pragma once
#include"Command.h"
#include"Battle_System.h"
class Battle_System;
class Command_Use_Item : public Command
{
private:
	Battle_System* battle_system;
public:
	Command_Use_Item(Battle_System* input_battle_system);
	void Fire_Command();
};