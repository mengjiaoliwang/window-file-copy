#pragma once
#include <iostream>
using namespace std;

class Weapon
{
public:

	//��ȡ�����˺�
	virtual int getBaseDamage() = 0;

	//��ȡ����
	virtual int getCrit() = 0;

	//��ȡ��Ѫ
	virtual int getSuckBlood() = 0;

	//��ȡ����
	virtual int getFrozen() = 0;

	//��ȡ����
	virtual bool isTrigger(int rate) = 0;

	//�����˺�
	int baseDamage;

	//��������
	string weaponName;

	//����ϵ��
	int critPlus; 

	//������
	int critRate;

	//��Ѫϵ��
	int suckPlus;

	//��Ѫ��
	int suckRate;
	
	//������
	int frozenRate;


};