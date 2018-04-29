#pragma once
#include"Character.h"
#include"Skill.h"

class Diagonal_Blade_Dance : public Skill
{
private:
	Character* character;
public:
	Diagonal_Blade_Dance(Character* input_character);
	void Cancel_Transform();
};