#pragma  once
#include <iostream>
using namespace std;
#include "weapon.h"

class DragonSword :public Weapon
{
public:
	DragonSword();

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