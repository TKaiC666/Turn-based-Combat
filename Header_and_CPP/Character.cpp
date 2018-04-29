#include"Character.h"
//�ܨ��� �k���ƪ��A
void Character::Transform_to_HDD()
{

};
//�ܨ��� Next Form���A
void Character::Transform_to_Next_Form()
{

};
//�ܨ��^ ���q���A
void Character::Transform_to_Normal()
{

};
//�e�X�ثe�����ϥΪ����O
//�p ���� �ϥΧޯ� �ϥιD�� �k����
void Character::Draw_Command(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	Gotoxy(x, y);
	int command_number = command_set->Get_Command_Number();
	Draw_Utility::Draw_Border(x, y, 24, command_number + 2);
	for (int i = 0; i < command_number; i++)
	{
		Gotoxy(x + 4, y + 1 + i);
		cout << command_set->Get_Command(i)->GetName();
	}
};
//�^�Ǿ��Skill�}�C
Skill** Character::Get_Skill()
{
	return skill;
};
//���o�����⦳�X�ӧޯ�
int Character::Get_Skill_Number()
{
	return skill_number;
};
void Character::Heal_Percentage(float percentage)
{
	float heal = max_hp * percentage * 0.01f;
	current_hp = current_hp + heal > max_hp ? max_hp : current_hp + heal;
};
void Character::Recover_SP_Percentage(float percentage)
{
	float recover = max_sp * percentage * 0.01f;
	current_sp = current_sp + recover > max_sp ? max_sp : current_sp + recover;
};
Command_Set* Character::Get_CommandSet()
{
	return command_set;
}
void Character::Set_HP(int input_hp)
{
	current_hp = input_hp;
};
void Character::Set_Max_HP(int input_max_hp)
{
	max_hp = input_max_hp;
};

void Character::Set_CommandSet(Command_Set* input_command_set)
{
	command_set = input_command_set;
};
void Character::Set_Name(string input_name)
{
	name = input_name;
};
void Character::Draw_Simple(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	Gotoxy(x + 2, y + 1);
	cout << name;
	Draw_Utility::Draw_Border(x, y, 24, 11);
	icon->Draw(x + 2, y + 2);
};

void Character::Draw(int x, int y)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	Gotoxy(x + 2, y + 1);
	cout << name;
	Gotoxy(x + 2, y + 2);
	cout << "HP: " << (int)current_hp << "/" << (int)max_hp;
	Gotoxy(x + 2, y + 3);
	cout << "SP: " << (int)current_sp << "/" << (int)max_sp;
	Draw_Utility::Draw_Border(x, y, 24, 13);
	icon->Draw(x + 2, y + 4);
};
void Character::SetSP(float sp)
{
	current_sp = sp > max_sp? max_sp : sp;
};
void Character::SetHP(float hp)
{
	current_hp = hp > max_hp ? max_hp : hp;
};
void Character::Heal(float heal)
{
	current_hp = current_hp + heal > max_hp ? max_hp : current_hp + heal;
};

void Character::Damage(float damage)
{
	current_hp = current_hp - damage < 0 ? 0 : current_hp - damage;
};

float Character::Get_HP()
{
	return current_hp;
};
float Character::Get_Max_HP()
{
	return max_hp;
};
float Character::Get_SP()
{
	return current_sp;
};
float Character::Get_Max_SP()
{
	return max_sp;
};
float Character::Get_Attack()
{
	return attack;
};
string Character::Get_Name()
{
	return name;
};