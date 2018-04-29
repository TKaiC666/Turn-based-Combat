#include"Uni.h"

Uni::Uni(Battle_System* input_battle_system)
{
	battle_system = input_battle_system;
	current_hp = 850;
	max_hp = 850;
	current_sp = 285;
	max_sp = 285;
	name = "Uni";
	attack = 120;
	icon = new Icon_Uni();
	command_set = new CPU_Candidate_Normal_Command_Set(battle_system, this);
	skill_number = 2;
	skill[0] = new EX_Multi_Blaster();
	skill[1] = new NGP();
};

//變身直接以比例改變current_hp
//女神化狀態的血量上限是1400
void Uni::Transform_to_HDD()
{
	float ratio = current_hp / max_hp;
	max_hp = 1400;
	current_hp = ratio *max_hp;
	name = "Black Sister";
	attack = 210;

	icon = new Icon_BlackSister();
	command_set = new CPU_Candidate_HDD_Command_Set(battle_system, this);
};
//變身直接以比例改變current_hp
//女神化狀態的血量上限是850
void Uni::Transform_to_Normal()
{
	float ratio = current_hp / max_hp;
	max_hp = 850;
	current_hp = ratio *max_hp;
	name = "Uni";
	attack = 120;
	icon = new Icon_Uni();
	command_set = new CPU_Candidate_Normal_Command_Set(battle_system, this);
};