#pragma once
#include"Command_Set.h"
#include"Command_Attack.h"
#include"Command_Use_Skill.h"
#include"Command_Use_Item.h"
#include"Command_HDD_Off.h"
#include"Command_Next_Form_On.h"

//�k��(���Ҥ���Noire)�b�k���ƪ����A�U ����ϥΪ����O
class CPU_HDD_Command_Set :public Command_Set
{
public:
	CPU_HDD_Command_Set(Battle_System* input_battle_system, Character* input_character);
};