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
//�ڭ̦b�o�̤j�T��ʤFNoire class
//�o�N�ɭP�Ҧ��ϥΨ�Noire class���������ݭn���(�bGame_System�̹���ƪ�����)
//�N�O�ڭ̳̫�@�g���Ϊ���Xclass���N�� (integration
//��{���X�U�ӷU�e�j�� �n�s�W/�ק�\�� �]�i���

//�N��ϥ�factory method�]�i��n���ܾ��factory���͹��骺��k ������ӫغc�l������
//factory method�^�ǹ��骺�����]�n����

class Battle_System;
class Noire :public Character
{
private:
	Battle_System* battle_system;
	public:
		Noire(Battle_System* input_battle_system);
		//��½(override)
		//�ܨ��� �k���ƪ��A
		void Transform_to_HDD();
		//�ܨ��� Next form���A
		void Transform_to_Next_Form();
		//�ܨ��^ ���q���A
		void Transform_to_Normal();
};