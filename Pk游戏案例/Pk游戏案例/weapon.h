#pragma once
#include <iostream>
using namespace std;

class Weapon
{
public:

	//获取基础伤害
	virtual int getBaseDamage() = 0;

	//获取暴击
	virtual int getCrit() = 0;

	//获取吸血
	virtual int getSuckBlood() = 0;

	//获取冰冻
	virtual int getFrozen() = 0;

	//获取几率
	virtual bool isTrigger(int rate) = 0;

	//基础伤害
	int baseDamage;

	//武器名称
	string weaponName;

	//暴击系数
	int critPlus; 

	//暴击率
	int critRate;

	//吸血系数
	int suckPlus;

	//吸血率
	int suckRate;
	
	//冰冻率
	int frozenRate;


};