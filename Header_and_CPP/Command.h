#pragma once
#include<iostream>
using namespace std;
//Command Pattern
//���ިϥΤ���|�o�ͤ����
//�@���u���Ѥ@�ӱҰʫ��O����H�禡(Fire_Command())
//�l���O������½��
class Command
{
protected:
	string name;
public:
	string GetName();
	virtual void Fire_Command() = 0;
};