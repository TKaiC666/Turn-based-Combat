#include"Item.h"
int Item::GetAmount()
{
	return amount;
};
string Item::GetDescription()
{
	return description;
}
;
int Item::GetCost()
{
	return cost;
};
string Item::GetName()
{
	return name;
}
void Item::SetAmount(int target_amount)
{
	amount = target_amount;
}

Target_Type Item::GetTargetType()
{
	return target_type;
};

float Item::Get_HP_Recover_Percent()
{
	return hp_recover_percent;
};
float Item::Get_SP_Recover_Percent()
{
	return sp_recover_percent;
};