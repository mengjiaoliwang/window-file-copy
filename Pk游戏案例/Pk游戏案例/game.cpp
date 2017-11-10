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

	cout << "欢迎来到力量大会" << endl;
	cout << "请选择您的英雄" << endl;

	FileManager file;
	map<string, map<string, string>>mHeroData;
	file.loadCSVData("./Hero.csv", mHeroData);

	char buf[1024];
	sprintf(buf, "1、%s<%s>", mHeroData["1"]["heroName"].c_str(), mHeroData["1"]["heroInfo"].c_str());

	cout << buf << endl;

	sprintf(buf, "2、%s<%s>", mHeroData["2"]["heroName"].c_str(), mHeroData["2"]["heroInfo"].c_str());

	cout << buf << endl;

	sprintf(buf, "3、%s<%s>", mHeroData["3"]["heroName"].c_str(), mHeroData["3"]["heroInfo"].c_str());

	cout << buf << endl;

	//接受用户输入内容
	int select = 0;
	cin >> select;

	//将缓冲区的换行拿走
	getchar();

	//创建英雄
	Hero hero(select);
	
	cout << "您选择的英雄是" << hero.heroName << endl;
	cout << endl;

	cout << "请选择您的武器" << endl;
	
	map<string, map<string, string>>mWeaponData;
	file.loadCSVData("./Weapons.csv", mWeaponData);
	cout << "1、 赤手空拳" << endl;
	sprintf(buf, "2、%s ", mWeaponData["1"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "3、%s ", mWeaponData["2"]["weaponName"].c_str());
	cout << buf << endl;
	sprintf(buf, "4、%s ", mWeaponData["3"]["weaponName"].c_str());
	cout << buf << endl;

	cin >> select;
	getchar();
	Weapon * weapon = NULL;

	switch (select)
	{
	case 1:
		cout << "你真牛逼！等死吧" << endl;
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
	//英雄装备武器
	hero.EquipWeapon(weapon);

	//创建怪物
	int monsterId = 5; // rand() % 5 + 1; //1~5
	Monster monster(monsterId);

	int round = 1; //回合数

	while (true)
	{
		getchar();
		system("cls"); //清屏

		cout << " ------ 当前是第 " << round << "回合 ------" << endl;

		if (hero.heroHp <= 0)
		{
			cout << "英雄" << hero.heroName << "已挂  游戏结束！" << endl;
			break;
		}
		hero.Attack(&monster);

		if (monster.MonsterHp <= 0)
		{
			cout << "怪物" << monster.MonsterName << "已挂  顺利通关！" << endl;
			break;
		}
		monster.Attack(&hero);

		cout << "英雄" << hero.heroName << " 剩余血量：" << hero.heroHp << endl;
		cout << "怪物" << monster.MonsterName << " 剩余血量： " << monster.MonsterHp << endl;

		if (hero.heroHp <= 0)
		{
			cout << "英雄" << hero.heroName << "已挂  游戏结束！" << endl;
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

	cout << "main函数中测试 ： "<< mHeroData["1"]["heroName"] << endl;

	map<string, map<string, string>>mMonsterData;
	file.loadCSVData("./Monsters.csv", mMonsterData);
	cout << "main函数中测试 ： " << mMonsterData["1"]["monsterName"] << endl;


	map<string, map<string, string>>mWeaponData;
	file.loadCSVData("./Weapons.csv", mWeaponData);
	cout << "main函数中测试 ： " << mWeaponData["3"]["weaponName"] << endl;*/


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