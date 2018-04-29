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
//有一個技能十分特殊，當使完那技能後，使用該技能的角色要恢復成普通狀態
//這時你可能要推翻(override)這個方法
void Skill::Cancel_Transform()
{

};