#pragma once
#include<iostream>
#include"Target_Type.h"
using namespace std;
class Item
{
protected:
	int cost;
	string description;
	int amount;
	string name;
	Target_Type target_type;
	float hp_recover_percent;
	float sp_recover_percent;
public:
	int GetAmount();
	string GetDescription();
	string GetName();
	int GetCost();
	void SetAmount(int target_amount);
	Target_Type GetTargetType();
	float Get_HP_Recover_Percent();
	float Get_SP_Recover_Percent();
};