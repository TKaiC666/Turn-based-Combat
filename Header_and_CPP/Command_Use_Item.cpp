#include"Command_Use_Item.h"

Command_Use_Item::Command_Use_Item(Battle_System* input_battle_system)
{
	name = "使用道具";
	battle_system = input_battle_system;
};
void Command_Use_Item::Fire_Command()
{
	battle_system->Get_Item_System()->Reset();
	battle_system->Change_Sub_System(battle_system->Get_Item_System());
};