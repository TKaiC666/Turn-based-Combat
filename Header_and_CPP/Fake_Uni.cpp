#include"Fake_Uni.h"

Fake_Uni::Fake_Uni()
{
	name = "°°Uni";
	current_hp = 3500;
	max_hp = 3500;
	attack = 150;
	icon = new Icon_Uni();
	skill_number = 2;
	skill[0] = new EX_Multi_Blaster();
	skill[1] = new NGP();
}