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
	//推翻(override)
	//變身至 女神化狀態
	void Transform_to_HDD();
	//變身回 普通狀態
	void Transform_to_Normal();
};