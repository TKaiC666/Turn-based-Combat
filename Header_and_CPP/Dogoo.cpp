#include"Dogoo.h"

Dogoo::Dogoo()
{
	name = "Dogoo";
	current_hp = 300;
	max_hp = 300;
	attack = 50;
	icon = new Icon_Dogoo();
	skill_number = 0;
	skill[0] = NULL;
	skill[1] = NULL;
};