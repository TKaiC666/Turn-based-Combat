#include"Command_Attack.h"


Command_Attack::Command_Attack(Battle_System* input_battle_system)
{
	name = "攻擊";
	battle_system = input_battle_system;
};

void Command_Attack::Fire_Command()
{
	//轉交子系統給  指定攻擊目標  的系統
	battle_system->Get_Attack_Target_System()->Reset();
	battle_system->Change_Sub_System(battle_system->Get_Attack_Target_System());

};