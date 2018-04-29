#include"Normal_Command_Set.h"

//���q�H ���ޯ��
//IF�O���q�H
//�S�a�W�ߥX�ӳo�اޯ�լO�]���C�������\�h���q�H�A�i�H���ЧQ��
Normal_Command_Set::Normal_Command_Set(Battle_System* input_battle_system, Character* input_character)
{
	command_number = 3;
	commands[0] = new Command_Attack(input_battle_system);
	commands[1] = new Command_Use_Skill(input_battle_system, input_character);
	commands[2] = new Command_Use_Item(input_battle_system);
}