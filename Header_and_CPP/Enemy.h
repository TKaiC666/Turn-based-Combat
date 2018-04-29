#pragma once
#include<iostream>
#include<string>
#include"Icons.h"
#include"Draw_Utility.h"
#include"Skill.h"
using namespace std;
class Enemy
{
protected:
	string name;
	float current_hp;
	float max_hp;
	float attack;
	Icons* icon;
	Skill* skill[2];
	int skill_number;
public:
	void Draw_Simple(int x, int y);
	void Draw(int x, int y);
	void Damage(float damage);

	float Get_HP();
	float Get_Max_HP();
	float Get_Attack();
	string Get_Name();


	Skill** Get_Skill();
	int Get_Skill_Number();
};
