#pragma once
#include<iostream>
#include"Enemy.h"

using namespace std;
class Battle
{
protected:
	string name;
	int reward_credits;
public:
	string GetName();
	virtual void Generate_Enemy(Enemy* enemy[3]) = 0;
	int GetReward_Credits();
};