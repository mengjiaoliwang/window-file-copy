#pragma  once
#include <iostream>
using namespace std;
#include "weapon.h"

class Knife:public Weapon
{
public:
	Knife();

	//��ȡ�����˺�
	virtual int getBaseDamage();

	//��ȡ����
	virtual int getCrit();

	//��ȡ��Ѫ
	virtual int getSuckBlood();

	//��ȡ����
	virtual int getFrozen();

	//��ȡ����
	virtual bool isTrigger(int rate);

};