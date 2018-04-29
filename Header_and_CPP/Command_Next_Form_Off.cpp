#include"Command_Next_Form_Off.h"

//解除 Next Form狀態 會直接變回普通狀態
Command_Next_Form_Off::Command_Next_Form_Off(Battle_System* input_battle_system, Character* input_character)
{
	name = "解除Next Form";
	battle_system = input_battle_system;
	character = input_character;
};

void Command_Next_Form_Off::Fire_Command()
{
	character->Transform_to_Normal();
	//交棒給下一個角色
	battle_system->Add_Current_Active_Unit_Index();

};