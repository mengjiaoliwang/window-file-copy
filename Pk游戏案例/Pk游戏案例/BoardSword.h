#pragma  once
#include <iostream>
using namespace std;
#include "weapon.h"

class BoardSword :public Weapon
{
public:
	BoardSword();

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