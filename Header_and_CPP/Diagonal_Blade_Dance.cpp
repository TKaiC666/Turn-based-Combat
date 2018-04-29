#include"Diagonal_Blade_Dance.h"

Diagonal_Blade_Dance::Diagonal_Blade_Dance(Character* input_character)
{
	character = input_character;
	name = "對角刀亂舞之太刀";
	power = 2000;
	target_type = SINGLE_TARGET;
	sp_cost = 150;

};

void Diagonal_Blade_Dance::Cancel_Transform()
{
	character->Transform_to_Normal();
};