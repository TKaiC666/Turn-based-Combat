#include"Command_HDD_On.h"

//�ܦ� �k���ƪ��A
Command_HDD_On::Command_HDD_On(Battle_System* input_battle_system, Character* input_character)
{
	name = "�k����";
	battle_system = input_battle_system;
	character = input_character;
};
void Command_HDD_On::Fire_Command()
{
	//�������ܦ��k���ƪ��A
	character->Transform_to_HDD();
	//��ε��U�@�Ө���
	battle_system->Add_Current_Active_Unit_Index();

};