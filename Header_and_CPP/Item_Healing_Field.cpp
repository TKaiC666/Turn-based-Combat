#include"Item_Healing_Field.h"

Item_Healing_Field::Item_Healing_Field()
{
	cost = 3000;
	description = "ฅþล้ฆ^ด_70%HP";
	amount = 0;
	name = "Healing Field";
	target_type = ALL;
	hp_recover_percent=0.7;
	sp_recover_percent=0;
};