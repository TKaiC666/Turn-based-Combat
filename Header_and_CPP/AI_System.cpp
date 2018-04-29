#include"AI_System.h"
//這是讓電腦自動攻擊的子系統，是Battle_System的子系統之一
AI_System::AI_System(Game_System* input_game_system, Battle_System* input_battle_system) 
{
	game_system = input_game_system;
	battle_system = input_battle_system;
};
//這方法是隨機回傳1個還活著的玩家角色的index
int AI_System::Get_Random_Alive_Character_Index()
{
	Character** character_slot = game_system->Get_Character_Slot();
	//先骰唄，看骰到哪1個角色的index
	int dice_for_character_index = rand() % 3;
	while (true)
	{
		//如果看骰到的角色的位置是空的或是已經死了，就往下移動直到抓到1個沒死的角色，回傳該index
		if (character_slot[dice_for_character_index] != NULL)
		{
			if (character_slot[dice_for_character_index]->Get_HP() > 0)
			{
				break;
			}
			else
			{
				dice_for_character_index = dice_for_character_index + 1 > 2 ? 0 : dice_for_character_index + 1;

			}
		}
		else if (character_slot[dice_for_character_index] == NULL)
		{
			dice_for_character_index = dice_for_character_index + 1 > 2 ? 0 : dice_for_character_index + 1;
		}
	
	}
	return dice_for_character_index;
};
//在這裡會讓敵方自動進行攻擊，並且畫出攻擊的資訊到畫面中間
void AI_System::AI_Behaviour_and_Draw_Information()
{
	Character** character_slot = game_system->Get_Character_Slot();
	Enemy** enemy = game_system->Get_Enemy();
	int current_enemy_index = battle_system->Get_Current_Active_Unit_Index() - 3;
	int dice_for_skill_or_attack = 0;//擲骰子，如果是，1就用隨機的技能隨機攻擊玩家角色，如果是0就用攻擊去攻擊隨機玩家角色
	int skill_number = enemy[current_enemy_index]->Get_Skill_Number();
	//先看目前行動中的敵人有沒有技能
	if (skill_number > 0)
	{
		//如果有技能就骰骰子看看要用技能還是攻擊
		dice_for_skill_or_attack = rand() % 2;
	}

	//攻擊，隨機攻擊1個玩家角色
	if (dice_for_skill_or_attack == 0)
	{	
		//隨便攻擊1個角色
		int character_index = Get_Random_Alive_Character_Index();
		float atk = enemy[current_enemy_index]->Get_Attack();
		character_slot[character_index]->Damage(atk);

		//畫出攻擊訊息
		string enemy_name = enemy[current_enemy_index]->Get_Name();
		string charact_name = character_slot[character_index]->Get_Name();
		//to_string() 是把傳入引數轉成string輸出
		string information = enemy_name + " 攻擊了 " + charact_name + " 造成" + to_string((int)atk) + "點傷害";
		Draw_Utility::Draw_Border(6, 18, 62, 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
		Gotoxy(8, 19);
		cout << information;

	}
	//技能，隨機用1個技能攻擊隨機1個玩家角色(or全體玩家角色)
	else if(dice_for_skill_or_attack == 1)
	{
		//隨便選一個技能
		int skill_index = rand() % skill_number;
		Skill** skills = enemy[current_enemy_index]->Get_Skill();
		float power = skills[skill_index]->Get_Power();
		//如果是技能目標是ALL(表示全體攻擊)的話，就打全體
		if (skills[skill_index]->Get_TargetType() == ALL)
		{
			int dialogue_y = 15;
			for (int i = 0; i < 3; i++)
			{
				if (character_slot[i] != NULL)
				{
					if (character_slot[i]->Get_HP() > 0)
					{
						character_slot[i]->Damage(power);
						//畫出攻擊訊息
						string enemy_name = enemy[current_enemy_index]->Get_Name();
						string skill_name = skills[skill_index]->Get_Name();
						string charact_name = character_slot[i]->Get_Name();
						//to_string() 是把傳入引數轉成string輸出
						string information = enemy_name + " 使用 " + skill_name +  " 對 " + charact_name + " 造成" + to_string((int)power) + "點傷害";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
						Draw_Utility::Draw_Border(6, dialogue_y, 62, 3);
						Gotoxy(8, dialogue_y + 1);
						cout << information;
						dialogue_y = dialogue_y + 3;
					}
				}
			}
		}
		//如果是技能目標是SINGLE_TARGET(表示對單體攻擊)的話，就隨機挑一個目標打
		else if (skills[skill_index]->Get_TargetType() == SINGLE_TARGET)
		{
			int character_index = Get_Random_Alive_Character_Index();
			character_slot[character_index]->Damage(power);
			//畫出攻擊訊息
			string enemy_name = enemy[current_enemy_index]->Get_Name();
			string skill_name = skills[skill_index]->Get_Name();
			string charact_name = character_slot[character_index]->Get_Name();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
			//to_string() 是把傳入引數轉成string輸出
			string information = enemy_name + " 使用 " + skill_name + " 對 " + charact_name + " 造成" + to_string((int)power) + "點傷害";
			Draw_Utility::Draw_Border(6, 18, 62, 3);
			Gotoxy(8, 19);
			cout << information;
		}
	}
};
//畫出畫面
void AI_System::Draw()
{
	//讓AI自動行動並畫出資訊
	AI_Behaviour_and_Draw_Information();
	//畫出所有角色與Active
	battle_system->Draw_Units_and_Active();
};
//處理使用者按鍵
void AI_System::Update_Data(char key)
{
	//按g以外的鍵都會直接繼續執行

	//移交給下一位角色
	battle_system->Add_Current_Active_Unit_Index();
	//玩家角色死光光的情況，玩家輸掉，把子系統轉交給Lose_System
	if (battle_system->Get_Ally_Alive_Count() <= 0)
	{
		battle_system->Change_Sub_System(battle_system->Get_Lose_System());
	}
	//若輪到玩家的回合，則交棒給顯示指令選單的子系統
	if (battle_system->Is_Ally_Turn())
	{
		battle_system->Get_Command_System()->Reset();
		battle_system->Change_Sub_System(battle_system->Get_Command_System());
	}
	//按g就回競技場
	switch (key)
	{
	case 'g':case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}
};

