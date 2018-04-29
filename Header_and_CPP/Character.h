#pragma once
#include<iostream>
#include<string>
#include"Icons.h"
#include"Draw_Utility.h"
#include"Skill.h"
#include"Command.h"
#include"Command_Set.h"
using namespace std;
class Character
{
protected:
	string name;
	float current_hp;
	float max_hp;
	float attack;
	float current_sp;
	float max_sp;
	Icons* icon;
	Skill* skill[2];
	Command_Set* command_set;
	int skill_number;
public:
	void Draw_Command(int x, int y);
	void Set_CommandSet(Command_Set* input_command_set);
	Command_Set* Get_CommandSet();
	void Set_Name(string input_name);
	void Set_HP(int input_hp);
	void Set_Max_HP(int input_max_hp);
	//從普通狀態 變身至 女神化狀態
	virtual void Transform_to_HDD();
	//從女神化狀態 變身至 Next Form狀態
	virtual void Transform_to_Next_Form();
	//從任意狀態 變身回 普通狀態
	virtual void Transform_to_Normal();

	void Draw_Simple(int x, int y);
	void Draw(int x, int y);
	
	void SetSP(float sp);
	
	void SetHP(float hp);
	void Heal(float heal);
	void Heal_Percentage(float percentage);
	void Recover_SP_Percentage(float percentage);
	void Damage(float damage);

	float Get_HP();
	float Get_Max_HP();
	float Get_SP();
	float Get_Max_SP();
	float Get_Attack();
	string Get_Name();

	Skill** Get_Skill();
	int Get_Skill_Number();

};
