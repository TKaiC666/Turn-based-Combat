#include"Skill_Target_System.h"


Skill_Target_System::Skill_Target_System(Game_System* input_game_system, Battle_System* input_battle_system)
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
void Skill_Target_System::Reset()
{
	Enemy** enemy = game_system->Get_Enemy();
	//��b�Y���V�̥���ĤH����m
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->Get_HP() > 0)
			{
				arrow_position_index = i;
				break;
			}
		}
	}
};
void Skill_Target_System::Draw()
{

	battle_system->Draw_Units_and_Active();
	Skill* current_skill = battle_system->Get_Current_Skill();
	Target_Type target_type = current_skill->Get_TargetType();
	Enemy** enemy = game_system->Get_Enemy();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0e);
	if (SINGLE_TARGET == target_type) {
		Gotoxy(arrow_pos[arrow_position_index].x, arrow_pos[arrow_position_index].y);
		cout << "����";
	}
	if (ALL == target_type) {
		for (int i = 0; i < 3; i++) {
			if (0 >= enemy[i]->Get_HP()) continue;
			Gotoxy(arrow_pos[i].x, arrow_pos[i].y);
			cout << "����";
		}
	}
};


int Skill_Target_System::Get_Left_Enemy_Index()
{
	Enemy** enemy = game_system->Get_Enemy();
	for (int i = arrow_position_index - 1; i >= 0; i--)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->Get_HP() > 0)
			{
				return i;
			}
		}
	}
	return arrow_position_index;
};
int Skill_Target_System::Get_Right_Enemy_Index()
{
	Enemy** enemy = game_system->Get_Enemy();
	for (int i = arrow_position_index + 1; i <= 2; i++)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->Get_HP() > 0)
			{
				return i;
			}
		}
	}
	return arrow_position_index;
};
void Skill_Target_System::Update_Data(char key)
{
	Character** character_slot = game_system->Get_Character_Slot();
	int current_active_unit_index = battle_system->Get_Current_Active_Unit_Index();
	Enemy** enemy = game_system->Get_Enemy();
	Skill* current_skill = battle_system->Get_Current_Skill();
	float skill_power = current_skill->Get_Power();
	Target_Type target_type = current_skill->Get_TargetType();

	switch (key)
	{
	case'a': case'A':
		if (0 >= enemy[1]->Get_HP()) { arrow_position_index--; break; }
		arrow_position_index -= arrow_position_index > Get_Left_Enemy_Index() ? 1 : 0;
		break;
	case'd': case'D':
		arrow_position_index += arrow_position_index < Get_Right_Enemy_Index() ? 1 : 0;
		break;
	case'k': case'K':
		//�����I��ޯ઺���⪺SP
		character_slot[current_active_unit_index]->SetSP(character_slot[current_active_unit_index]->Get_SP() - current_skill->Get_SP_Cost());
		//�����ĤH
		if (target_type == SINGLE_TARGET)
		{
			enemy[arrow_position_index]->Damage(skill_power);
		}
		else if (target_type == ALL)
		{
			for (int i = 0; i < 3; i++)
			{
				if (enemy[i] != NULL)
				{
					if (enemy[i]->Get_HP() > 0)
					{
						enemy[i]->Damage(skill_power);
					}
				}
			}
		}
		//���ӧޯ�ܯS��|�����ܨ����A �ܦ����q���A ���L�ڭ̤����D(�]���Q���D)�{�b�O���O�Ψ쨺�ӧޯ�F
		//�ϥ��N�I�s�o��k �Y�u���Ψ�o�Ө����ܨ����ޯ� ���N�ۤv�|����
		current_skill->Cancel_Transform();

		//�ˬdĹ�F�S��
		if (battle_system->Get_Enemy_Alive_Count() <= 0)
		{
			battle_system->Change_Sub_System(battle_system->Get_Win_System());
		}
		//�SĹ�~��
		else
		{
			//�ثe��쪺��ʵ��� ��ε����U�@�ӳ��
			battle_system->Add_Current_Active_Unit_Index();
			//�p�G�O�ͭx���^�X �h��ܥi�Ϋ��O�Ѫ��a���
			if (battle_system->Is_Ally_Turn())
			{
				battle_system->Get_Command_System()->Reset();
				battle_system->Change_Sub_System(battle_system->Get_Command_System());
			}
			//�Y�O�Ĥ�^�X ��AI_System�B�z�ĤH���޿�
			else
			{
				battle_system->Change_Sub_System(battle_system->Get_AI_System());
			}
		}
		break;
	case'j': case'J':
		battle_system->Get_Skill_System()->Reset();
		battle_system->Change_Sub_System(battle_system->Get_Skill_System());
		break;
	case'g': case'G':
		battle_system->Reset();
		game_system->ChangeSystem(game_system->Get_Colosseum_System());
		break;
	}
};
