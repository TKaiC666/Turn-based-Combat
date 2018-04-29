#include"CPU_Candidate_HDD_Command_Set.h"

//女神候補生 在 女神化狀態時 的技能組
//Uni是女神候補生
//特地獨立出來這種技能組是因為遊戲中有許多女神候補生，可以重覆利用
CPU_Candidate_HDD_Command_Set::CPU_Candidate_HDD_Command_Set(Battle_System* input_battle_system, Character* input_character)
{
	command_number = 4;
	commands[0] = new Command_Attack(input_battle_system);
	commands[1] = new Command_Use_Skill(input_battle_system, input_character);
	commands[2] = new Command_Use_Item(input_battle_system);
	commands[3] = new Command_HDD_Off(input_battle_system, input_character);
};