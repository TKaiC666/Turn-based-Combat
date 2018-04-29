#include"CPU_Next_Command_Set.h"

//�k�� �b Next Form���A�� ���ޯ��
//Noire�O�k��
//�S�a�W�ߥX�ӳo�اޯ�լO�]���C�������\�h�k���A�i�H���ЧQ��
CPU_Next_Command_Set::CPU_Next_Command_Set(Battle_System* input_battle_system, Character* input_character)
{
	command_number = 4;
	commands[0] = new Command_Attack(input_battle_system);
	commands[1] = new Command_Use_Skill(input_battle_system, input_character);
	commands[2] = new Command_Use_Item(input_battle_system);
	commands[3] = new Command_Next_Form_Off(input_battle_system, input_character);
};