#include "Hero.h"
#include "fileManager.h"
//构造函数
Hero::Hero(int heroId)
{
	FileManager file;
	map<string, map<string, string>>mHeroData;
	file.loadCSVData("./Hero.csv", mHeroData);

	string tmpId = std::to_string(heroId); // int 转string

	string id = mHeroData[tmpId]["heroId"];

	this->heroName = mHeroData[id]["heroName"];

	this->heroHp = atoi(mHeroData[id]["heroHp"].c_str());

	this->heroAtk = atoi(mHeroData[id]["heroAtk"].c_str());
	this->heroDef = atoi(mHeroData[id]["heroDef"].c_str());
	this->heroInfo = atoi(mHeroData[id]["heroInfo"].c_str());
	this->pWeapon = NULL; //武器 初始为 NULL

}

//攻击函数
void Hero::Attack(Monster *monster)
{
	int crit = 0;
	int addHp = 0;
	int forzen = 0;
	int damage = 0;

	if (this->pWeapon == NULL)
	{
		damage = this->heroAtk; //赤手空拳
	}
	else
	{
		//增加基础伤害
		damage = this->heroAtk + this->pWeapon->getBaseDamage();

		//是否暴击
		crit = this->pWeapon->getCrit();

		//是否吸血
		addHp = this->pWeapon->getSuckBlood();

		//是否冰冻
		forzen = this->pWeapon->getFrozen();
	}
	if (crit)
	{
		//累加真实伤害
		damage += crit;
		cout << "英雄武器触发了暴击效果 ，怪物受到" << damage << "点伤害！" << endl;
	}
	if (forzen)
	{
		cout << "英雄武器触发了冰冻效果 ，怪物" << monster->MonsterName << "停止攻击一回合！" << endl;
	}
	if (addHp)
	{
		cout << "英雄武器触发了吸血效果 , 英雄增加血量" << addHp << "点血量！" << endl;
	}

	monster->isFrozen = forzen;
	int trueDamage = ((damage - monster->MonsterDef) > 0) ? (damage - monster->MonsterDef) : 1;

	//怪物掉血
	monster->MonsterHp -= trueDamage;

	//吸血
	this->heroHp += addHp;

	cout << "英雄 <" << this->heroName << " > 攻击了怪物 " << monster->MonsterName << " 造成 " << trueDamage << " 点伤害!" << endl;

}

//装备武器
void Hero::EquipWeapon(Weapon *weapon)
{
	if (weapon == NULL)
	{
		return;
	}
	this->pWeapon = weapon;
	cout << "英雄 <" << this->heroName << " > 装备了武器  <" << this->pWeapon->weaponName << " > !" << endl;
}
