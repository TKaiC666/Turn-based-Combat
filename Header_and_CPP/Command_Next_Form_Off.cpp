#include"Command_Next_Form_Off.h"

//�Ѱ� Next Form���A �|�����ܦ^���q���A
Command_Next_Form_Off::Command_Next_Form_Off(Battle_System* input_battle_system, Character* input_character)
{
	name = "�Ѱ�Next Form";
	battle_system = input_battle_system;
	character = input_character;
};

void Command_Next_Form_Off::Fire_Command()
{
	character->Transform_to_Normal();
	//��ε��U�@�Ө���
	battle_system->Add_Current_Active_Unit_Index();

};