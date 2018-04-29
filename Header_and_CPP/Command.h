#pragma once
#include<iostream>
using namespace std;
//Command Pattern
//不管使用之後會發生什麼事
//一概只提供一個啟動指令的抽象函式(Fire_Command())
//子類別必須推翻之
class Command
{
protected:
	string name;
public:
	string GetName();
	virtual void Fire_Command() = 0;
};