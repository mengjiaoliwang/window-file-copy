#include "DragonSword.h"
#include "fileManager.h"

DragonSword::DragonSword()
{
	FileManager fm;
	map<string, map<string, string>>mWeaponData;
	fm.loadCSVData("./Weapons.csv", mWeaponData);

	string id = mWeaponData["3"]["weaponId"];

	this->weaponName = mWeaponData[id]["weaponName"]; //ÎäÆ÷Ãû³Æ

	this->baseDamage = atoi(mWeaponData[id]["weaponAtk"].c_str()); //»ù´¡ÉËº¦

	this->critPlus = atoi(mWeaponData[id]["weaponCritPlus"].c_str()); //±©»÷¼Ó³É

	this->critRate = atoi(mWeaponData[id]["weaponCritRate"].c_str()); //±©»÷ÂÊ

	this->suckPlus = atoi(mWeaponData[id]["weaponSuckPlus"].c_str());  //ÎüÑª¼Ó³É

	this->suckRate = atoi(mWeaponData[id]["weaponSuckRate"].c_str());  //ÎüÑªÂÊ

	this->frozenRate = atoi(mWeaponData[id]["weaponFrozenRate"].c_str()); //±ù¶³ÂÊ

}

int DragonSword::getBaseDamage()
{
	return this->baseDamage;
}

int DragonSword::getCrit()
{
	if (isTrigger(this->critRate))
	{
		//´¥·¢±©»÷
		return this->baseDamage * this->critPlus;
	}
	else
	{
		return 0;
	}
}

int DragonSword::getSuckBlood()
{
	if (isTrigger(this->suckRate))
	{
		//´¥·¢ÎüÑª
		return this->baseDamage * this->suckPlus;
	}
	else
	{
		return 0;
	}
}

int DragonSword::getFrozen()
{
	if (isTrigger(this->frozenRate))
	{
		//´¥·¢±ù¶³
		return 1;
	}
	else
	{
		return 0;
	}
}

bool DragonSword::isTrigger(int rate)
{
	int num = rand() % 100 + 1;
	if (num < rate)
	{
		return true;
	}
	return false;
}
