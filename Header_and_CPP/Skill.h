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
	//���@�ӧޯ�Q���S��A��ϧ����ޯ��A�ϥθӧޯ઺����n��_�����q���A
	//�o�ɧA�i��n��½(override)�o�Ӥ�k
	virtual void Cancel_Transform();
};