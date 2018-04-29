#include"Interface_system.h"

char Interface_System::Wait_for_Input()
{
	while (true)
	{
		if (_kbhit())
			return _getch();
	}
};
void Interface_System:: Run()
{
	Draw();
	Input_key = Wait_for_Input();
	Update_Data(Input_key);
}
