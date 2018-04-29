#include"Noire.h"

Noire::Noire(Battle_System* input_battle_system)
{
	battle_system = input_battle_system;
	current_hp = 1250;
	max_hp = 1250;
	current_sp = 300;
	max_sp = 300;
	name = "Noire";
	attack = 150;
	icon = new Icon_Noire();
	command_set = new CPU_Normal_Command_Set(battle_system, this);
	skill_number = 2;
	skill[0] = new Lacy_Dance();
	skill[1] = new Infinite_Slash();
};

//�ܨ������H��ҧ���current_hp
//�k���ƪ��A����q�W���O1750
void Noire::Transform_to_HDD()
{
	float ratio = current_hp / max_hp;
	max_hp = 1750;
	current_hp = ratio *max_hp;
	name = "Black Heart";
	attack = 230;
	icon = new Icon_BlackHeart();
	command_set = new CPU_HDD_Command_Set(battle_system, this);
	skill[0] = new Lacy_Dance();
	skill[1] = new Infinite_Slash();
};

//�ܨ������H��ҧ���current_hp
//Next Form���A����q�W���O2250
//���2�ӧޯ�令Diagonal_Blade_Dance
void Noire::Transform_to_Next_Form()
{
	float ratio = current_hp / max_hp;
	max_hp = 2250;
	current_hp = ratio *max_hp;
	name = "Next Black";
	attack = 310;
	icon = new Icon_NextBlack();
	command_set = new CPU_Next_Command_Set(battle_system, this);
	skill[0] = new Lacy_Dance();
	skill[1] = new Diagonal_Blade_Dance(this);
};

//�ܦ^���q���A�H��ҧ���current_hp
//���q���A����q�W���O1250
void Noire::Transform_to_Normal()
{
	float ratio = current_hp / max_hp;
	max_hp = 1250;
	current_hp = ratio *max_hp;
	name = "Noire";
	attack = 150;
	icon = new Icon_Noire();
	command_set = new CPU_Normal_Command_Set(battle_system, this);
	skill[0] = new Lacy_Dance();
	skill[1] = new Infinite_Slash();
};