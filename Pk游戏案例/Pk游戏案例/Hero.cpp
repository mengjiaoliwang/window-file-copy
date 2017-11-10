#include "Hero.h"
#include "fileManager.h"
//���캯��
Hero::Hero(int heroId)
{
	FileManager file;
	map<string, map<string, string>>mHeroData;
	file.loadCSVData("./Hero.csv", mHeroData);

	string tmpId = std::to_string(heroId); // int תstring

	string id = mHeroData[tmpId]["heroId"];

	this->heroName = mHeroData[id]["heroName"];

	this->heroHp = atoi(mHeroData[id]["heroHp"].c_str());

	this->heroAtk = atoi(mHeroData[id]["heroAtk"].c_str());
	this->heroDef = atoi(mHeroData[id]["heroDef"].c_str());
	this->heroInfo = atoi(mHeroData[id]["heroInfo"].c_str());
	this->pWeapon = NULL; //���� ��ʼΪ NULL

}

//��������
void Hero::Attack(Monster *monster)
{
	int crit = 0;
	int addHp = 0;
	int forzen = 0;
	int damage = 0;

	if (this->pWeapon == NULL)
	{
		damage = this->heroAtk; //���ֿ�ȭ
	}
	else
	{
		//���ӻ����˺�
		damage = this->heroAtk + this->pWeapon->getBaseDamage();

		//�Ƿ񱩻�
		crit = this->pWeapon->getCrit();

		//�Ƿ���Ѫ
		addHp = this->pWeapon->getSuckBlood();

		//�Ƿ����
		forzen = this->pWeapon->getFrozen();
	}
	if (crit)
	{
		//�ۼ���ʵ�˺�
		damage += crit;
		cout << "Ӣ�����������˱���Ч�� �������ܵ�" << damage << "���˺���" << endl;
	}
	if (forzen)
	{
		cout << "Ӣ�����������˱���Ч�� ������" << monster->MonsterName << "ֹͣ����һ�غϣ�" << endl;
	}
	if (addHp)
	{
		cout << "Ӣ��������������ѪЧ�� , Ӣ������Ѫ��" << addHp << "��Ѫ����" << endl;
	}

	monster->isFrozen = forzen;
	int trueDamage = ((damage - monster->MonsterDef) > 0) ? (damage - monster->MonsterDef) : 1;

	//�����Ѫ
	monster->MonsterHp -= trueDamage;

	//��Ѫ
	this->heroHp += addHp;

	cout << "Ӣ�� <" << this->heroName << " > �����˹��� " << monster->MonsterName << " ��� " << trueDamage << " ���˺�!" << endl;

}

//װ������
void Hero::EquipWeapon(Weapon *weapon)
{
	if (weapon == NULL)
	{
		return;
	}
	this->pWeapon = weapon;
	cout << "Ӣ�� <" << this->heroName << " > װ��������  <" << this->pWeapon->weaponName << " > !" << endl;
}
