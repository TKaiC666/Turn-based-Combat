#pragma once
#include"Command_Set.h"
#include"Command_Attack.h"
#include"Command_Use_Skill.h"
#include"Command_Use_Item.h"
class Normal_Command_Set :public Command_Set
{
public:
	Normal_Command_Set(Battle_System* input_battle_system, Character* input_character);
};