#pragma  once
#include <iostream>
using namespace std;
#include "weapon.h"

class BoardSword :public Weapon
{
public:
	BoardSword();

	//获取基础伤害
	virtual int getBaseDamage();

	//获取暴击
	virtual int getCrit();

	//获取吸血
	virtual int getSuckBlood();

	//获取冰冻
	virtual int getFrozen();

	//获取几率
	virtual bool isTrigger(int rate);

};