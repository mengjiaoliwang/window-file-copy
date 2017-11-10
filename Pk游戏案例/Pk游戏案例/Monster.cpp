#include "Monster.h"
#include "fileManager.h"


Monster::Monster(int monsterId)
{
	FileManager file;
	map<string, map<string, string>>mMonsterData;
	file.loadCSVData("./Monsters.csv", mMonsterData);

	string tmpId = std::to_string(monsterId);

	string id = mMonsterData[tmpId]["monsterId"];

	this->MonsterName = mMonsterData[id]["monsterName"];

	this->MonsterHp = atoi(mMonsterData[id]["monsterHp"].c_str());

	this->MonsterAtk = atoi(mMonsterData[id]["monsterAtk"].c_str());

	this->MonsterDef = atoi(mMonsterData[id]["monsterDef"].c_str());

	this->isFrozen = false;
}

void Monster::Attack(Hero * hero)
{
	//攻击英雄
	if (this->isFrozen)
	{
		cout << "怪物：<" << this->MonsterName << "> 被冰冻了，本回合无法进行攻击！" << endl;
		return;
	}

	//攻击英雄
	int damage = ( (this->MonsterAtk - hero->heroDef) > 0 )? (this->MonsterAtk - hero->heroDef) : 1;

	//英雄掉血
	hero->heroHp -= damage;

	cout << "怪物 <" << this->MonsterName << " > 攻击了英雄" << hero->heroName << " 造成" << damage << "点伤害" << endl;

}
