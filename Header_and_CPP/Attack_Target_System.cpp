#include"Attack_Target_System.h"

//�����a���1�ӥؼЧ������t��
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

//�e�X�e��
void Attack_Target_System::Draw()
{
	//�e�X�Ҧ�����PActive
	battle_system->Draw_Units_and_Active();
	//�e�X����b�Y
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	Gotoxy(arrow_pos[arrow_position_index].x, arrow_pos[arrow_position_index].y);
	cout << "����";
};
//���]�A�Ψӧ�b�Y���V�̥���ĤH����m
void Attack_Target_System::Reset()
{
	Enemy** enemy = game_system->Get_Enemy();
	//��b�Y���V�̥���ĤH����m
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

//�^�ǥ���1��ĤH��Index(�p�G�S�����ܴN�^�ǥثe��Index)
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
//�^�ǥk��1��ĤH��Index(�p�G�S�����ܴN�^�ǥثe��Index)
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

//�B�z����
void Attack_Target_System::Update_Data(char key)
{
	
	Enemy** enemy = game_system->Get_Enemy();
	Character** character_slot = game_system->Get_Character_Slot();
	int character_index = battle_system->Get_Current_Active_Unit_Index();
	float atk = character_slot[character_index]->Get_Attack();

	switch (key)
	{
		//��b�Y������
	case'a': case'A':
		arrow_position_index = Get_Left_Enemy_Index();
		break;
		//��b�Y���k��
	case'd': case'D':	
		arrow_position_index = Get_Right_Enemy_Index();
		break;
		//�����b�Y���V��m���ĤH
	case'k': case'K':
		enemy[arrow_position_index]->Damage(atk);
		//�ˬdĹ�F�S���AĹ�F�N��l�t�Υ浹Win_System
		if (battle_system->Get_Enemy_Alive_Count() <= 0)
		{
			battle_system->Change_Sub_System(battle_system->Get_Win_System());
		}
		//�SĹ�~��
		else
		{
			//�ثe��쪺��ʵ����A��ε����U�@�ӳ��
			battle_system->Add_Current_Active_Unit_Index();
			//�p�G�O�ͭx���^�X�A�h��ܥi�Ϋ��O�Ѫ��a���
			if (battle_system->Is_Ally_Turn())
			{
				battle_system->Get_Command_System()->Reset();
				battle_system->Change_Sub_System(battle_system->Get_Command_System());
			}
			//�Y�O�Ĥ�^�X�A��AI_System�B�z�ĤH�����
			else
			{
				battle_system->Change_Sub_System(battle_system->Get_AI_System());
			}
		}
		break;
		//��J�����^����O���
	case'j': case'J':
		battle_system->Change_Sub_System(battle_system->Get_Command_System());
		break;
		//��g�^���v�޳�
	case'g': case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}

};
