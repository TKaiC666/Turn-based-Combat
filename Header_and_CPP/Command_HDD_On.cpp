#include"Command_HDD_On.h"

//變成 女神化狀態
Command_HDD_On::Command_HDD_On(Battle_System* input_battle_system, Character* input_character)
{
	name = "女神化";
	battle_system = input_battle_system;
	character = input_character;
};
void Command_HDD_On::Fire_Command()
{
	//讓角色變成女神化狀態
	character->Transform_to_HDD();
	//交棒給下一個角色
	battle_system->Add_Current_Active_Unit_Index();

};