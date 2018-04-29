#pragma once
#include"Command_Set.h"
#include"Command_Attack.h"
#include"Command_Use_Skill.h"
#include"Command_Use_Item.h"
#include"Command_HDD_Off.h"
#include"Command_Next_Form_On.h"

//女神(此例中為Noire)在女神化的狀態下 能夠使用的指令
class CPU_HDD_Command_Set :public Command_Set
{
public:
	CPU_HDD_Command_Set(Battle_System* input_battle_system, Character* input_character);
};