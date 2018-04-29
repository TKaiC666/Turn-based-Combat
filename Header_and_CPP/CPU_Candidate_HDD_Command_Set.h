#pragma once
#include"Command_Set.h"
#include"Character.h"
#include"Command_Attack.h"
#include"Command_Use_Skill.h"
#include"Command_Use_Item.h"
#include"Command_HDD_Off.h"

class CPU_Candidate_HDD_Command_Set : public Command_Set
{
public:
	CPU_Candidate_HDD_Command_Set(Battle_System* input_battle_system, Character* input_character);
};