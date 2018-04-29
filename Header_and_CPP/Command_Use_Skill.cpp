#include"Command_Use_Skill.h"

Command_Use_Skill::Command_Use_Skill(Battle_System* input_battle_system, Character* input_character)
{
	name = "使用技能";
	battle_system = input_battle_system;
	character = input_character;
};
void Command_Use_Skill::Fire_Command()
{
	battle_system->Get_Skill_System()->Reset();
	battle_system->Change_Sub_System(battle_system->Get_Skill_System());

};

