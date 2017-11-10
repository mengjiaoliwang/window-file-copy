#pragma  once 
#include <iostream>
using namespace std;
#include "Hero.h"
#include <string>

class Hero;
class Monster
{
public:

	Monster(int monsterId);

	void Attack( Hero * hero );

	//属性
	string MonsterName;
	//血量
	int MonsterHp;
	//攻击力
	int MonsterAtk;
	//防御力
	int MonsterDef;
	//是否被冰冻
	bool isFrozen;

};