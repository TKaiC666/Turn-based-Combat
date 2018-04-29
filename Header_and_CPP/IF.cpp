#include"IF.h"

IF::IF(Battle_System* input_battle_system)
{
	battle_system = input_battle_system;
	current_hp = 900;
	max_hp = 900;
	current_sp = 270;
	max_sp = 270;
	name = "IF";
	attack = 130;
	icon = new Icon_IF();
	command_set = new Normal_Command_Set(input_battle_system, this);
	skill_number = 2;
	skill[0] = new Demon_Summon();
	skill[1] = new Apocalypse_Nova();
};