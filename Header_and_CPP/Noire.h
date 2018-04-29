#pragma once
#include"Character.h"
#include"Battle_System.h"
#include"Icon_Noire.h"
#include"Icon_BlackHeart.h"
#include"Icon_NextBlack.h"
#include"CPU_Normal_Command_Set.h"
#include"CPU_HDD_Command_Set.h"
#include"CPU_Next_Command_Set.h"

#include"Lacy_Dance.h"
#include"Infinite_Slash.h"
#include"Diagonal_Blade_Dance.h"
//我們在這裡大幅更動了Noire class
//這將導致所有使用到Noire class的部份都需要更改(在Game_System裡實體化的部份)
//就是我們最後一週提及的整合class的代價 (integration
//當程式碼愈來愈龐大時 要新增/修改功能 也可能使

//就算使用factory method也可能要改變整個factory產生實體的方法 畢竟整個建構子都改變
//factory method回傳實體的部份也要改變

class Battle_System;
class Noire :public Character
{
private:
	Battle_System* battle_system;
	public:
		Noire(Battle_System* input_battle_system);
		//推翻(override)
		//變身至 女神化狀態
		void Transform_to_HDD();
		//變身至 Next form狀態
		void Transform_to_Next_Form();
		//變身回 普通狀態
		void Transform_to_Normal();
};