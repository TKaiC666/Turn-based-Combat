#pragma once
#include"Character.h"
#include"Icon_IF.h"
#include"Normal_Command_Set.h"
#include"Apocalypse_Nova.h"
#include"Demon_Summon.h"
class Battle_System;
class IF :public Character
{
private:
	Battle_System* battle_system;
public:
	IF(Battle_System* input_battle_system);
};