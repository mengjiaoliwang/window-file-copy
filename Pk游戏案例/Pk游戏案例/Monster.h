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

	//����
	string MonsterName;
	//Ѫ��
	int MonsterHp;
	//������
	int MonsterAtk;
	//������
	int MonsterDef;
	//�Ƿ񱻱���
	bool isFrozen;

};