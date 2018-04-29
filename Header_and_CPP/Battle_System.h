#pragma once
#include"Interface_system.h"
#include"Draw_Utility.h"
#include"Battle.h"
#include"Character.h"
#include"Item.h"
#include"Game_System.h"
#include"Interface_Sub_System.h"
#include"Command_System.h"
#include"Item_System.h"
#include"Skill_System.h"
#include"Attack_Target_System.h"
#include"Item_Target_System.h"
#include"Skill_Target_System.h"
#include"Win_System.h"
#include"Lose_System.h"
#include"AI_System.h"

class Game_System;
class Battle_System :public Interface_System
{
private:

	//�s�W�{���X

	Interface_Sub_System* current_sub_system;
	Interface_Sub_System* command_system;
	Interface_Sub_System* item_system;
	Interface_Sub_System* skill_system;
	Interface_Sub_System* attack_target_system;
	Interface_Sub_System* item_target_system;
	Interface_Sub_System* skill_target_system;
	Interface_Sub_System* win_system;
	Interface_Sub_System* lose_system;
	Interface_Sub_System* ai_system;

//	bool win;
	//bool lose;
	bool initialized;
	int current_active_unit_index;

	Skill* current_skill;

	Item* current_item;

	Game_System* game_system;

	void Initialize();
protected:
	Position arrow_posision;
	Position diamond_position;
	Position draw_active_position[6];
	void Draw();
	void Update_Data(char key);
public:
	Battle_System(Game_System* input_game_system);

	//�s�W�{���X
	//��_�P���]���A
	void Reset();
	//���o�ثe��ʪ�����
	//0: ���U
	//1: ���U
	//2: �k�U
	//3: ���W
	//4: ���W
	//5: �k�W
	int Get_Current_Active_Unit_Index();
	void Add_Current_Active_Unit_Index();
	//���o�ͭx�ͦs�ƶq
	int Get_Ally_Alive_Count();
	//���o�ĭx�ͦs�ƶq
	int Get_Enemy_Alive_Count();
	void Draw_Units_and_Active();

	bool Is_Ally_Turn();
	bool Is_Enemy_Turn();
	void Change_Sub_System(Interface_Sub_System* target_sub_system);

	void Set_Current_Skill(Skill* input_skill);
	Skill* Get_Current_Skill();

	void Set_Current_Item(Item* input_item);
	Item* Get_Current_Item();

	Interface_Sub_System* Get_Command_System();
	Interface_Sub_System* Get_Skill_System();
	Interface_Sub_System* Get_Item_System();
	Interface_Sub_System* Get_Attack_Target_System();
	Interface_Sub_System* Get_Item_Target_System();
	Interface_Sub_System* Get_Skill_Target_System();
	Interface_Sub_System* Get_Win_System();
	Interface_Sub_System* Get_Lose_System();
	Interface_Sub_System* Get_AI_System();
};