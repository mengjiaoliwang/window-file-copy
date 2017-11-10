#include "Knife.h"
#include "fileManager.h"

Knife::Knife()
{
	FileManager fm;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("./Weapons.csv", mWeaponData);

	string id = mWeaponData["1"]["weaponId"];

	this->weaponName = mWeaponData[id]["weaponName"]; //��������

	this->baseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str()); //�����˺�

	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str()); //�����ӳ�

	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str()); //������

	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());  //��Ѫ�ӳ�

	this->suckRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str());  //��Ѫ��

	this->frozenRate = atoi(mWeaponData[id]["weaponFrozenRate"].c_str()); //������

}

int Knife::getBaseDamage()
{
	return this->baseDamage;
}

int Knife::getCrit()
{
	if (isTrigger(this->critRate))
	{
		//��������
		return this->baseDamage * this->critPlus;
	}
	else
	{
		return 0;
	}
}

int Knife::getSuckBlood()
{
	if (isTrigger(this->suckRate))
	{
		//������Ѫ
		return this->baseDamage * this->suckPlus;
	}
	else
	{
		return 0;
	}
}

int Knife::getFrozen()
{
	if (isTrigger(this->frozenRate))
	{
		//��������
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Knife::isTrigger(int rate)
{
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}
	return false;
}
