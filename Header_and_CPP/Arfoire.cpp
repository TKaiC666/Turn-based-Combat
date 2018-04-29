#include"Arfoire.h"

Arfoire::Arfoire()
{
	name = "Arfoire";
	current_hp = 4000;
	max_hp = 4000;
	attack = 210;
	icon = new Icon_Arforie();
	skill_number = 2;
	skill[0] = new Magic();
	skill[1] = new Dragon_Raid();
};