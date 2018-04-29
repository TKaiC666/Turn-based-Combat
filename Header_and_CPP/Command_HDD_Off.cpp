#include"Command_HDD_Off.h"

//解除女神化 恢復到 普通狀態
Command_HDD_Off::Command_HDD_Off(Battle_System* input_battle_system, Character* input_character)
{
	name = "解除女神化";
	battle_system = input_battle_system;
	character = input_character;
};
void Command_HDD_Off::Fire_Command()
{
	character->Transform_to_Normal();
	//交棒給下一個角色
	battle_system->Add_Current_Active_Unit_Index();

};