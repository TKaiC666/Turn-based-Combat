#include"Normal_Command_Set.h"

//普通人 的技能組
//IF是普通人
//特地獨立出來這種技能組是因為遊戲中有許多普通人，可以重覆利用
Normal_Command_Set::Normal_Command_Set(Battle_System* input_battle_system, Character* input_character)
{
	command_number = 3;
	commands[0] = new Command_Attack(input_battle_system);
	commands[1] = new Command_Use_Skill(input_battle_system, input_character);
	commands[2] = new Command_Use_Item(input_battle_system);
}