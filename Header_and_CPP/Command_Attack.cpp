#include"Command_Attack.h"


Command_Attack::Command_Attack(Battle_System* input_battle_system)
{
	name = "����";
	battle_system = input_battle_system;
};

void Command_Attack::Fire_Command()
{
	//���l�t�ε�  ���w�����ؼ�  ���t��
	battle_system->Get_Attack_Target_System()->Reset();
	battle_system->Change_Sub_System(battle_system->Get_Attack_Target_System());

};