#pragma once
#include"Character.h"
#include"Icon_BlackSister.h"
#include"Icon_Uni.h"
#include"CPU_Candidate_Normal_Command_Set.h"
#include"CPU_Candidate_HDD_Command_Set.h"
#include"EX_Multi_Blaster.h"
#include"NGP.h"
class Battle_System;
class Uni :public Character
{
private:
	Battle_System* battle_system;
public:
	Uni(Battle_System* input_battle_system);
	//��½(override)
	//�ܨ��� �k���ƪ��A
	void Transform_to_HDD();
	//�ܨ��^ ���q���A
	void Transform_to_Normal();
};