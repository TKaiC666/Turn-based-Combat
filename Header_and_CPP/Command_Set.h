#pragma once
#include"Command.h"
class Command_Set
{
protected:
	Command* commands[6];
	int command_number;
public:
	Command* Get_Command(int index);
	int Get_Command_Number();
};