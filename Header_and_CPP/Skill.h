#pragma once
#include<iostream>
#include"Target_Type.h"
using namespace std;
class Skill
{
protected:
	string name;
	float power;
	float sp_cost;
	Target_Type target_type;
public:
	string Get_Name();
	float Get_Power();
	float Get_SP_Cost();
	Target_Type Get_TargetType();
	//有一個技能十分特殊，當使完那技能後，使用該技能的角色要恢復成普通狀態
	//這時你可能要推翻(override)這個方法
	virtual void Cancel_Transform();
};