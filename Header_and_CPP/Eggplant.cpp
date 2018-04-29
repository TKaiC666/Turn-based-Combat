#include"Eggplant.h"

Eggplant::Eggplant()
{
	name = "Eggplant";
	current_hp = 450;
	max_hp = 450;
	attack = 60;
	icon = new Icon_Eggplant();
	skill_number = 0;
	skill[0] = NULL;
	skill[1] = NULL;
};