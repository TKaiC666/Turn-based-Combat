#include"AI_System.h"
//�o�O���q���۰ʧ������l�t�ΡA�OBattle_System���l�t�Τ��@
AI_System::AI_System(Game_System* input_game_system, Battle_System* input_battle_system) 
{
	game_system = input_game_system;
	battle_system = input_battle_system;
};
//�o��k�O�H���^��1���٬��۪����a���⪺index
int AI_System::Get_Random_Alive_Character_Index()
{
	Character** character_slot = game_system->Get_Character_Slot();
	//�������A�ݻ���1�Ө��⪺index
	int dice_for_character_index = rand() % 3;
	while (true)
	{
		//�p�G�ݻ�쪺���⪺��m�O�Ū��άO�w�g���F�A�N���U���ʪ�����1�ӨS��������A�^�Ǹ�index
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
//�b�o�̷|���Ĥ�۰ʶi������A�åB�e�X��������T��e������
void AI_System::AI_Behaviour_and_Draw_Information()
{
	Character** character_slot = game_system->Get_Character_Slot();
	Enemy** enemy = game_system->Get_Enemy();
	int current_enemy_index = battle_system->Get_Current_Active_Unit_Index() - 3;
	int dice_for_skill_or_attack = 0;//�Y��l�A�p�G�O�A1�N���H�����ޯ��H���������a����A�p�G�O0�N�Χ����h�����H�����a����
	int skill_number = enemy[current_enemy_index]->Get_Skill_Number();
	//���ݥثe��ʤ����ĤH���S���ޯ�
	if (skill_number > 0)
	{
		//�p�G���ޯ�N���l�ݬݭn�Χޯ��٬O����
		dice_for_skill_or_attack = rand() % 2;
	}

	//�����A�H������1�Ӫ��a����
	if (dice_for_skill_or_attack == 0)
	{	
		//�H�K����1�Ө���
		int character_index = Get_Random_Alive_Character_Index();
		float atk = enemy[current_enemy_index]->Get_Attack();
		character_slot[character_index]->Damage(atk);

		//�e�X�����T��
		string enemy_name = enemy[current_enemy_index]->Get_Name();
		string charact_name = character_slot[character_index]->Get_Name();
		//to_string() �O��ǤJ�޼��নstring��X
		string information = enemy_name + " �����F " + charact_name + " �y��" + to_string((int)atk) + "�I�ˮ`";
		Draw_Utility::Draw_Border(6, 18, 62, 3);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
		Gotoxy(8, 19);
		cout << information;

	}
	//�ޯ�A�H����1�ӧޯ�����H��1�Ӫ��a����(or���骱�a����)
	else if(dice_for_skill_or_attack == 1)
	{
		//�H�K��@�ӧޯ�
		int skill_index = rand() % skill_number;
		Skill** skills = enemy[current_enemy_index]->Get_Skill();
		float power = skills[skill_index]->Get_Power();
		//�p�G�O�ޯ�ؼЬOALL(��ܥ������)���ܡA�N������
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
						//�e�X�����T��
						string enemy_name = enemy[current_enemy_index]->Get_Name();
						string skill_name = skills[skill_index]->Get_Name();
						string charact_name = character_slot[i]->Get_Name();
						//to_string() �O��ǤJ�޼��নstring��X
						string information = enemy_name + " �ϥ� " + skill_name +  " �� " + charact_name + " �y��" + to_string((int)power) + "�I�ˮ`";
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
						Draw_Utility::Draw_Border(6, dialogue_y, 62, 3);
						Gotoxy(8, dialogue_y + 1);
						cout << information;
						dialogue_y = dialogue_y + 3;
					}
				}
			}
		}
		//�p�G�O�ޯ�ؼЬOSINGLE_TARGET(��ܹ�������)���ܡA�N�H���D�@�ӥؼХ�
		else if (skills[skill_index]->Get_TargetType() == SINGLE_TARGET)
		{
			int character_index = Get_Random_Alive_Character_Index();
			character_slot[character_index]->Damage(power);
			//�e�X�����T��
			string enemy_name = enemy[current_enemy_index]->Get_Name();
			string skill_name = skills[skill_index]->Get_Name();
			string charact_name = character_slot[character_index]->Get_Name();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
			//to_string() �O��ǤJ�޼��নstring��X
			string information = enemy_name + " �ϥ� " + skill_name + " �� " + charact_name + " �y��" + to_string((int)power) + "�I�ˮ`";
			Draw_Utility::Draw_Border(6, 18, 62, 3);
			Gotoxy(8, 19);
			cout << information;
		}
	}
};
//�e�X�e��
void AI_System::Draw()
{
	//��AI�۰ʦ�ʨõe�X��T
	AI_Behaviour_and_Draw_Information();
	//�e�X�Ҧ�����PActive
	battle_system->Draw_Units_and_Active();
};
//�B�z�ϥΪ̫���
void AI_System::Update_Data(char key)
{
	//��g�H�~���䳣�|�����~�����

	//���浹�U�@�쨤��
	battle_system->Add_Current_Active_Unit_Index();
	//���a���⦺���������p�A���a�鱼�A��l�t����浹Lose_System
	if (battle_system->Get_Ally_Alive_Count() <= 0)
	{
		battle_system->Change_Sub_System(battle_system->Get_Lose_System());
	}
	//�Y���쪱�a���^�X�A�h��ε���ܫ��O��檺�l�t��
	if (battle_system->Is_Ally_Turn())
	{
		battle_system->Get_Command_System()->Reset();
		battle_system->Change_Sub_System(battle_system->Get_Command_System());
	}
	//��g�N�^�v�޳�
	switch (key)
	{
	case 'g':case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}
};

