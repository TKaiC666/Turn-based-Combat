#include<iostream>
#include<string>
#include<ctime>
#include <windows.h>
#include"Game_System.h"

using namespace std;

void main()
{
	Game_System* gs = new Game_System();
	gs->Game_Run();
	system("pause");
}
