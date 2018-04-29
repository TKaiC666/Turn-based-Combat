#pragma once
#include<iostream>
#include<string>
#include"Gotoxy.h"
using namespace std;
class Position
{
public:
	int x;
	int y;
};
class Draw_Utility
{

public:
	static void Draw_Skill_Point_Bar(int x, int y, float current_sp, float max_sp)
	{
		Gotoxy(x, y);
		for (int i = 0; i < (int)(current_sp / max_sp * 10); i++)
		{
			if (i < 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x03);
				cout << "█";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
				cout << "█";
			}

		}
	}
	static void Draw_Health_Point_Bar(int x, int y, float current_hp, float max_hp)
	{
		Gotoxy(x, y);
		for (int i = 0; i < (int)(current_hp / max_hp * 10); i++)
		{
			if (i < 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
				cout << "█";
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
				cout << "█";
			}

		}
	}
	static void Draw_Border(int x, int y, int width, int height)
	{
		if (x < 0 || y < 0 || width < 4 || width % 2 != 0 || height < 2 )
			throw exception("參數錯誤");
		//draw border
		Gotoxy(x, y);
		cout << "╔";
		Gotoxy(x + width - 2, y);
		cout << "╗";
		Gotoxy(x, y + height - 1);
		cout << "╚ ";
		Gotoxy(x + width - 2, y + height - 1);
		cout << "╝ ";
		Gotoxy(x + 2, y);
		for (int i = 2; i < width - 2; i += 2)
		{
			cout << "═";
		}
		Gotoxy(x + 2, y + height - 1);
		for (int i = 2; i < width - 2; i += 2)
		{
			cout << "═";
		}

		for (int j = 1; j < height - 1; j++)
		{
			Gotoxy(x, y + j);
			cout << "║";
		}

		for (int j = 1; j < height - 1; j++)
		{
			Gotoxy(x + width - 2, y + j);
			cout << "║";
		}
		
	}
	static void Draw_Dialogue(int x, int y, int width, int height, string message)
	{
		//計算總共能容納的字元空間
		int size = (width - 6) * (height - 2);
		if (x < 0 || y < 0 || width < 4 || width % 2 !=0 || height < 2 || size < message.size())
			throw exception("參數錯誤");
		//draw border
		Gotoxy(x, y);
		cout << "┌";
		Gotoxy(x + width - 2 , y);
		cout << "┐";
		Gotoxy(x, y + height - 1);
		cout << "└ ";
		Gotoxy(x + width - 2, y + height - 1);
		cout << "┘ ";
		Gotoxy(x + 2 , y);
		for (int i = 2; i < width-2; i+=2)
		{
			cout << "─";
		}
		Gotoxy(x + 2, y + height - 1);
		for (int i = 2; i < width - 2; i += 2)
		{
			cout << "─";
		}
		
		for (int j = 1; j < height-1; j++)
		{
			Gotoxy(x, y + j);
			cout << "│";
		}
		
		for (int j = 1; j < height - 1; j++)
		{
			Gotoxy(x + width - 2, y + j);
			cout << "│";
		}
		//message
		int x_c = 2;
		int y_c = 1;
		for (int i = 0; i < size && i< message.size(); i++, x_c++)
		{
			Gotoxy(x + x_c, y + y_c);
			cout << message[i];
			if ((i + 1) % (width - 6) == 0)
			{
				y_c++;
				x_c = 1;
			}
			
		}
	}
};
