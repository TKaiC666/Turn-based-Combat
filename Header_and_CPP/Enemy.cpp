#include"Enemy.h"

Skill** Enemy::Get_Skill()
{
	return skill;
};
int Enemy::Get_Skill_Number()
{
	return skill_number;
};

void Enemy::Draw_Simple(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	Gotoxy(x + 2, y + 1);
	cout << name;
	Draw_Utility::Draw_Border(x, y, 24, 11);
	icon->Draw(x + 2, y + 2);
};

void Enemy::Draw(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	Gotoxy(x + 2, y + 1);
	cout << name;
	Gotoxy(x + 2, y + 2);
	cout << "HP: " << (int)current_hp << "/" << (int)max_hp;
	Draw_Utility::Draw_Border(x, y, 24, 12);
	icon->Draw(x + 2, y + 3);
};

void Enemy::Damage(float damage)
{
	current_hp = current_hp - damage < 0 ? 0 : current_hp - damage;
};

float Enemy::Get_HP()
{
	return current_hp;
};
float Enemy::Get_Max_HP()
{
	return max_hp;
};
float Enemy::Get_Attack()
{
	return attack;
};


string Enemy::Get_Name()
{
	return name;
};