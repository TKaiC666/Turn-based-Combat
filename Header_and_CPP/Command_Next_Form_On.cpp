#include"Command_Next_Form_On.h"

//�ܦ�Next Form���A
Command_Next_Form_On::Command_Next_Form_On(Battle_System* input_battle_system, Character* input_character)
{
	name = "Next Form��";
	battle_system = input_battle_system;
	character = input_character;
};
void Command_Next_Form_On::Fire_Command()
{
	character->Transform_to_Next_Form();
	//��ε��U�@�Ө���
	battle_system->Add_Current_Active_Unit_Index();

};