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
	//����Ӣ��
	if (this->isFrozen)
	{
		cout << "���<" << this->MonsterName << "> �������ˣ����غ��޷����й�����" << endl;
		return;
	}

	//����Ӣ��
	int damage = ( (this->MonsterAtk - hero->heroDef) > 0 )? (this->MonsterAtk - hero->heroDef) : 1;

	//Ӣ�۵�Ѫ
	hero->heroHp -= damage;

	cout << "���� <" << this->MonsterName << " > ������Ӣ��" << hero->heroName << " ���" << damage << "���˺�" << endl;

}
