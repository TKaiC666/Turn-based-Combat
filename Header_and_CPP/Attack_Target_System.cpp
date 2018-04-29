#include"Attack_Target_System.h"

//讓玩家選擇1個目標攻擊的系統
Attack_Target_System::Attack_Target_System(Game_System* input_game_system, Battle_System* input_battle_system)
{
	game_system = input_game_system;
	battle_system = input_battle_system;
	arrow_pos[0].x = 10;
	arrow_pos[0].y = 12;
	arrow_pos[1].x = 34;
	arrow_pos[1].y = 12;
	arrow_pos[2].x = 58;
	arrow_pos[2].y = 12;
	arrow_position_index = 0;
};

//畫出畫面
void Attack_Target_System::Draw()
{
	//畫出所有角色與Active
	battle_system->Draw_Units_and_Active();
	//畫出黃色箭頭
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(arrow_pos[arrow_position_index].x, arrow_pos[arrow_position_index].y);
	cout << "◢◣";
};
//重設，用來把箭頭指向最左邊敵人的位置
void Attack_Target_System::Reset()
{
	Enemy** enemy = game_system->Get_Enemy();
	//把箭頭指向最左邊敵人的位置
	for (int i = 0; i < 3; i++)
	{
		if(enemy[i]!=NULL )
		{
			if (enemy[i]->Get_HP() > 0)
			{
				arrow_position_index = i;
				break;
			}
		}
	}
};

//回傳左邊1位敵人的Index(如果沒有的話就回傳目前的Index)
int Attack_Target_System::Get_Left_Enemy_Index()
{
	Enemy** enemy = game_system->Get_Enemy();
	for (int i = arrow_position_index - 1; i >= 0; i--)
	{
		if (enemy[i] != NULL )
		{
			if (enemy[i]->Get_HP() > 0)
			{
				return i;
			}
		}
	}
	return arrow_position_index;
};
//回傳右邊1位敵人的Index(如果沒有的話就回傳目前的Index)
int Attack_Target_System::Get_Right_Enemy_Index()
{
	Enemy** enemy = game_system->Get_Enemy();
	for (int i = arrow_position_index + 1; i <=2; i++)
	{
		if (enemy[i] != NULL && enemy[i]->Get_HP()>0)
		{
			if (enemy[i]->Get_HP() > 0)
			{
				return i;
			}
		}
	}
	return arrow_position_index;
};

//處理按鍵
void Attack_Target_System::Update_Data(char key)
{
	
	Enemy** enemy = game_system->Get_Enemy();
	Character** character_slot = game_system->Get_Character_Slot();
	int character_index = battle_system->Get_Current_Active_Unit_Index();
	float atk = character_slot[character_index]->Get_Attack();

	switch (key)
	{
		//把箭頭往左指
	case'a': case'A':
		arrow_position_index = Get_Left_Enemy_Index();
		break;
		//把箭頭往右指
	case'd': case'D':	
		arrow_position_index = Get_Right_Enemy_Index();
		break;
		//攻擊箭頭指向位置的敵人
	case'k': case'K':
		enemy[arrow_position_index]->Damage(atk);
		//檢查贏了沒有，贏了就把子系統交給Win_System
		if (battle_system->Get_Enemy_Alive_Count() <= 0)
		{
			battle_system->Change_Sub_System(battle_system->Get_Win_System());
		}
		//沒贏繼續
		else
		{
			//目前單位的行動結束，交棒給往下一個單位
			battle_system->Add_Current_Active_Unit_Index();
			//如果是友軍的回合，則顯示可用指令供玩家選擇
			if (battle_system->Is_Ally_Turn())
			{
				battle_system->Get_Command_System()->Reset();
				battle_system->Change_Sub_System(battle_system->Get_Command_System());
			}
			//若是敵方回合，讓AI_System處理敵人的行動
			else
			{
				battle_system->Change_Sub_System(battle_system->Get_AI_System());
			}
		}
		break;
		//按J取消回到指令選單
	case'j': case'J':
		battle_system->Change_Sub_System(battle_system->Get_Command_System());
		break;
		//按g回到競技場
	case'g': case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}

};
