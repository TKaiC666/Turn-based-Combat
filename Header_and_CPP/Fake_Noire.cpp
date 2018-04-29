#include"Fake_Noire.h"

Fake_Noire::Fake_Noire()
{
	name = "°°Noire";
	current_hp = 5000;
	max_hp = 5000;
	attack = 180;
	icon = new Icon_Noire();
	skill_number = 2;
	skill[0] = new Lacy_Dance();
	skill[1] = new Infinite_Slash();
};