#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "fileManager.h"
#include "weapon.h"
#include "Knife.h"
#include "DragonSword.h"
#include "BoardSword.h"
#include "Hero.h"
#include "Monster.h"
#include <ctime>


void Fighting()
{

	cout << "��ӭ�����������" << endl;
	cout << "��ѡ������Ӣ��" << endl;

	FileManager file;
	map<string, map<string, string>>mHeroData;
	file.loadCSVData("./Hero.csv", mHeroData);

	char buf[1024];
	sprintf(buf, "1��%s<%s>", mHeroData["1"]["heroName"].c_str(), mHeroData["1"]["heroInfo"].c_str());

	cout << buf << endl;

	sprintf(buf, "2��%s<%s>", mHeroData["2"]["heroName"].c_str(), mHeroData["2"]["heroInfo"].c_str());

	cout << buf << endl;

	sprintf(buf, "3��%s<%s>", mHeroData["3"]["heroName"].c_str(), mHeroData["3"]["heroInfo"].c_str());

	cout << buf << endl;

	//�����û���������
	int select = 0;
	cin >> select;

	//���������Ļ�������
	getchar();

	//����Ӣ��
	Hero hero(select);
	
	cout << "��ѡ���Ӣ����" << hero.heroName << endl;
	cout << endl;

	cout << "��ѡ����������" << endl;
	
	map<string, map<string, string>>mWeaponData;
	file.loadCSVData("./Weapons.csv", mWeaponData);
	cout << "1�� ���ֿ�ȭ" << endl;
	sprintf(buf, "2��%s ", mWeaponData["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "3��%s ", mWeaponData["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "4��%s ", mWeaponData["3"]["weaponName"].c_str());
	cout << buf << endl;

	cin >> select;
	getchar();
	Weapon * weapon = NULL;

	switch (select)
	{
	case 1:
		cout << "����ţ�ƣ�������" << endl;
		break;
	case 2:
		weapon = new Knife;
		break;
	case 3:
		weapon = new BoardSword;
		break;
	case 4:
		weapon = new DragonSword;
		break;
	default:
		break;
	}
	//Ӣ��װ������
	hero.EquipWeapon(weapon);

	//��������
	int monsterId = 5; // rand() % 5 + 1; //1~5
	Monster monster(monsterId);

	int round = 1; //�غ���

	while (true)
	{
		getchar();
		system("cls"); //����

		cout << " ------ ��ǰ�ǵ� " << round << "�غ� ------" << endl;

		if (hero.heroHp <= 0)
		{
			cout << "Ӣ��" << hero.heroName << "�ѹ�  ��Ϸ������" << endl;
			break;
		}
		hero.Attack(&monster);

		if (monster.MonsterHp <= 0)
		{
			cout << "����" << monster.MonsterName << "�ѹ�  ˳��ͨ�أ�" << endl;
			break;
		}
		monster.Attack(&hero);

		cout << "Ӣ��" << hero.heroName << " ʣ��Ѫ����" << hero.heroHp << endl;
		cout << "����" << monster.MonsterName << " ʣ��Ѫ���� " << monster.MonsterHp << endl;

		if (hero.heroHp <= 0)
		{
			cout << "Ӣ��" << hero.heroName << "�ѹ�  ��Ϸ������" << endl;
			break;
		}

		round++;
	}


}

int main(){

	srand((unsigned int)time(NULL));

	Fighting();

	/*FileManager file;
	map<string, map<string, string>>mHeroData;
	file.loadCSVData("./Hero.csv", mHeroData);

	cout << "main�����в��� �� "<< mHeroData["1"]["heroName"] << endl;

	map<string, map<string, string>>mMonsterData;
	file.loadCSVData("./Monsters.csv", mMonsterData);
	cout << "main�����в��� �� " << mMonsterData["1"]["monsterName"] << endl;


	map<string, map<string, string>>mWeaponData;
	file.loadCSVData("./Weapons.csv", mWeaponData);
	cout << "main�����в��� �� " << mWeaponData["3"]["weaponName"] << endl;*/


	//Weapon * weapon = NULL;
	//weapon = new Knife;
	//cout << weapon->getBaseDamage() << weapon->weaponName << endl;

	//weapon = new BoardSword;
	//cout << weapon->getBaseDamage() << weapon->weaponName << endl;

	//weapon = new DragonSword;
	//cout << weapon->getBaseDamage() << weapon->weaponName << endl;

	
	system("pause");
	return EXIT_SUCCESS;
}