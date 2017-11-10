#pragma  once
#include <iostream>
using namespace std;
#include "weapon.h"
#include "Monster.h"

class Monster;
class Hero
{
public:
	Hero(int heroId);

	void Attack(Monster *monster);
	void EquipWeapon(Weapon *weapon);
public:
	int heroHp;
	int heroAtk;
	int heroDef;
	string heroName;
	string heroInfo;
	Weapon *pWeapon;

};
