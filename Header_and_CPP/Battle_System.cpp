#include"Battle_System.h"

//�԰��t�ΡA�b�粒1���v�޳��԰���|�i�J���t��
//���a�i�H�ϥδ��Ѫ����O�Ӿ԰�
Battle_System::Battle_System(Game_System* input_game_system)
{
	game_system = input_game_system;
	initialized = false;
	current_active_unit_index = 0;
	for (int i = 0; i < 3; i++)
	{
		draw_active_position[i].x = 8 + 24 * i;
		draw_active_position[i].y = 27;
	}
	for (int i = 3; i < 6; i++)
	{
		draw_active_position[i].x = 8 + 24 * (i - 3);
		draw_active_position[i].y = 0;
	}
	command_system = new Command_System(input_game_system, this);
	item_system = new Item_System(input_game_system, this);
	skill_system = new Skill_System(input_game_system, this);
	attack_target_system = new Attack_Target_System(input_game_system, this);
	item_target_system = new Item_Target_System(input_game_system, this);
	skill_target_system = new Skill_Target_System(input_game_system, this);
	ai_system = new AI_System(input_game_system, this);
	win_system = new Win_System(input_game_system, this);
	lose_system = new Lose_System(input_game_system, this);
	current_sub_system = command_system;
};

//�^�ǥثe��ʤ�(�Y�W����ܫG�C��ACTIVE)������
//0 1 2�N���1 2 3�Ӫ��a����(�q���ƨ�k)
//3 4 5�N���1 2 3�ӼĤ訤��(�q���ƨ�k)
int Battle_System::Get_Current_Active_Unit_Index()
{
	return current_active_unit_index;
};
//��ε��U�@�Ө���
void Battle_System::Add_Current_Active_Unit_Index()
{
	Character** character_slot = game_system->Get_Character_Slot();
	Enemy** enemy = game_system->Get_Enemy();
	//���o�U�@�ӫDNULL�]�S��������A�ç����v�浹�L
	while (true)
	{
		current_active_unit_index = current_active_unit_index + 1 > 5 ? 0 : current_active_unit_index + 1;
		if (Is_Ally_Turn())
		{
			if (character_slot[current_active_unit_index] != NULL)
			{
				if (character_slot[current_active_unit_index]->Get_HP() > 0)
				{
					break;
				}
			}
		}
		else
		{
			if (enemy[current_active_unit_index - 3] != NULL)
			{
				if (enemy[current_active_unit_index - 3]->Get_HP() > 0)
				{
					break;
				}
			}
		}
	}
};
//���o�ͭx�ثe�s���ƶq
int Battle_System::Get_Ally_Alive_Count()
{
	int count = 0;
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL )
		{
			if(character_slot[i]->Get_HP() > 0)
				count++;
		}
	}
	return count;
};
//���o�ĭx�ثe�s���ƶq
int Battle_System::Get_Enemy_Alive_Count()
{

	int count = 0;
	Enemy** enemy = game_system->Get_Enemy();
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i] != NULL)
		{
			if (enemy[i]->Get_HP() > 0)
				count++;
		}
	}
	return count;
};
//��l�ơA�⨤�Ⲿ���1�Ӭ��۪����⪺��m
//�]���̥���i��S������A�ҥH�̥��䥼���O�_�l��ʪ�����
void Battle_System::Initialize()
{
	initialized = true;
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL)
		{
			if (character_slot[i]->Get_HP() > 0)
			{
				current_active_unit_index = i;
				break;
			}
		}
	}
};
//���]�A��Ӫ�l�ƪ���������l��
void Battle_System::Reset()
{
	initialized = false;
	current_active_unit_index = 0;
	current_sub_system = command_system;
	command_system->Reset();
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL)
		{
			character_slot[i]->SetHP(character_slot[i]->Get_Max_HP());
			character_slot[i]->SetSP(character_slot[i]->Get_Max_SP());
			character_slot[i]->Transform_to_Normal();
		}
	}
};
//�e�X�Ҧ�����A�æb�ثe��ʨ���W����صe�X�G�C�⪺ACTIVE
void Battle_System::Draw_Units_and_Active()
{
	Enemy** enemy = game_system->Get_Enemy();
	Character** character_slot = game_system->Get_Character_Slot();
	for (int i = 0; i < 3; i++)
	{
		if (enemy[i] != NULL && enemy[i]->Get_HP()>0)
		{
			enemy[i]->Draw(0 + i * 24, 0);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (character_slot[i] != NULL)
		{
			character_slot[i]->Draw(0 + i * 24, 27);
		}
	}
	//�b�ثe��ʨ��⪺�W����ءA�e�X�G�C��ACTIVE
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
	int x = draw_active_position[current_active_unit_index].x;
	int y = draw_active_position[current_active_unit_index].y;
	Gotoxy(x, y);
	cout << "ACTIVE";
};

//�p�G�ثe���쪱�a�����ʡA�N�^��true
bool Battle_System::Is_Ally_Turn()
{
	if (current_active_unit_index >= 0 && current_active_unit_index <= 2)
		return true;
	else
		return false;
};
//�p�G�ثe����Ĥ訤���ʡA�N�^��true
bool Battle_System::Is_Enemy_Turn()
{
	return !Is_Ally_Turn();
};
//�e�X�e��
void Battle_System::Draw()
{
	if (!initialized)
	{
		Initialize();
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0f);
	system("CLS");
	//��浹�l�t�Υh�e�e��
	current_sub_system->Draw();
	
};
//�B�z��L��J
void Battle_System::Update_Data(char key)
{
	//��浹�l�t�Υh�B�z��L��J
	current_sub_system->Update_Data(key);
	
};
//�]�w�ثe�ϥΪ��ޯ�A��Skill_System�PSkill_Target_System�ϥ�
void Battle_System::Set_Current_Skill(Skill* input_skill)
{
	current_skill = input_skill;
};
//���o�ثe�ϥΪ��ޯ�A��Skill_System�PSkill_Target_System�ϥ�
Skill* Battle_System::Get_Current_Skill()
{
	return current_skill;
};
//�]�w�ثe�ϥΪ��D��A�Ѩ�Item_System�PItem_Target_System�ϥ�
void Battle_System::Set_Current_Item(Item* input_item)
{
	current_item = input_item;
};
//���o�ثe�ϥΪ��D��A�Ѩ�Item_System�PItem_Target_System�ϥ�
Item* Battle_System::Get_Current_Item()
{
	return current_item;
};
//���l�t�ά��ؼФl�t��
void Battle_System::Change_Sub_System(Interface_Sub_System* target_sub_system)
{
	current_sub_system = target_sub_system;
};
//�U�����O�@��getter
Interface_Sub_System* Battle_System::Get_Command_System()
{
	return command_system;
};
Interface_Sub_System* Battle_System::Get_Skill_System()
{
	return skill_system;
};
Interface_Sub_System* Battle_System::Get_Item_System()
{
	return item_system;
};
Interface_Sub_System* Battle_System::Get_Attack_Target_System()
{
	return attack_target_system;
};
Interface_Sub_System* Battle_System::Get_Item_Target_System()
{
	return item_target_system;
};
Interface_Sub_System* Battle_System::Get_Skill_Target_System()
{
	return skill_target_system;
};
Interface_Sub_System* Battle_System::Get_Win_System()
{
	return win_system;
};
Interface_Sub_System* Battle_System::Get_Lose_System()
{
	return lose_system;
};
Interface_Sub_System* Battle_System::Get_AI_System()
{
	return ai_system;
};
