#include"Command_HDD_Off.h"

//�Ѱ��k���� ��_�� ���q���A
Command_HDD_Off::Command_HDD_Off(Battle_System* input_battle_system, Character* input_character)
{
	name = "�Ѱ��k����";
	battle_system = input_battle_system;
	character = input_character;
};
void Command_HDD_Off::Fire_Command()
{
	character->Transform_to_Normal();
	//��ε��U�@�Ө���
	battle_system->Add_Current_Active_Unit_Index();

};