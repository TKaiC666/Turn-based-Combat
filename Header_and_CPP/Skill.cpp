#include"Skill.h"

string Skill::Get_Name()
{
	return name;
};
float Skill::Get_Power()
{
	return power;
};
float Skill::Get_SP_Cost()
{
	return sp_cost;
};
Target_Type Skill::Get_TargetType()
{
	return target_type;
};
//���@�ӧޯ�Q���S��A��ϧ����ޯ��A�ϥθӧޯ઺����n��_�����q���A
//�o�ɧA�i��n��½(override)�o�Ӥ�k
void Skill::Cancel_Transform()
{

};