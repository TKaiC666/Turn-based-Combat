#include "Command_Set.h"

Command* Command_Set::Get_Command(int index)
{
	return commands[index];
};
int Command_Set::Get_Command_Number()
{
	return command_number;
};