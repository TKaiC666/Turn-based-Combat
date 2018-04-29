#include"Item_Uni_Curry.h"

Item_Uni_Curry::Item_Uni_Curry()
{
	cost = 1500;
	description = "Uni風的Lastation咖哩，單體恢復30%HP與SP";
	amount = 2;
	name = "Uni咖哩";
	target_type = SINGLE_TARGET;
	hp_recover_percent = 0.3;
	sp_recover_percent = 0.3;
};