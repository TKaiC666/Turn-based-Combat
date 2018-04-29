#pragma once
#include<iostream>
#include<string>
#include <windows.h>
using namespace std;
#define BG_BLACK 0x00
#define BG_BLUE 0x10
#define BG_GREEN 0x20
#define BG_CYAN 0x30
#define BG_RED 0x40
#define BG_MAGENTA 0x50
#define BG_BROWN 0x60
#define BG_LIGHTGREY 0x70
#define BG_DARKGREY 0x80
#define BG_LIGHTBLUE 0x90
#define BG_LIGHTGREEN 0xa0
#define BG_LIGHTCYAN 0xb0
#define BG_LIGHTRED 0xc0
#define BG_LIGHTMAGENTA 0xd0
#define BG_YELLOW 0xe0
#define BG_WHITE 0xf0

#define WORD_BLACK 0x00
#define WORD_BLUE 0x01
#define WORD_GREEN 0x02
#define WORD_CYAN 0x03
#define WORD_RED 0x04
#define WORD_MAGENTA 0x05
#define WORD_BROWN 0x06
#define WORD_LIGHTGREY 0x07
#define WORD_DARKGREY 0x08
#define WORD_LIGHTBLUE 0x09
#define WORD_LIGHTGREEN 0x0a
#define WORD_LIGHTCYAN 0x0b
#define WORD_LIGHTRED 0x0c
#define WORD_LIGHTMAGENTA 0x0d
#define WORD_YELLOW 0x0e
#define WORD_WHITE 0x0f
class Icons
{
protected:
	string pic[8];
	unsigned short background_color[8][20];
	unsigned short word_color[8][20];
public:
	void Draw(int x, int y)
	{
		COORD coord;
		coord.X = x;
		coord.Y = y;
		for (int i = 0; i < 8; i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			for (int j = 0; j < pic[i].length(); j++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background_color[i][j] + word_color[i][j]);
				cout << pic[i][j];
			}
			cout << endl;
			coord.Y = coord.Y + 1 ;
		}
	};
};