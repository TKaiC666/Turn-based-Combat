#pragma once
#include<conio.h>
class Interface_System
{
protected:
	char Input_key;
	virtual void Update_Data(char key) = 0;
	virtual void Draw() = 0;
	char Wait_for_Input();
public:
	void Run();
};