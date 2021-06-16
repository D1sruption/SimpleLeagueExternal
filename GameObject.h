#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "Matrix.h"
#include "Offsets.h"
#include "LeagueUtils.h"
#include "Vector.h"

using namespace std;

enum ObjectTypeFlag
{
	AIGameObject = (1 << 0),
	NeutralCampClient = (1 << 1),
	DeadObjectIdentifier = (1 << 4),
	AIBaseCommon = (1 << 7),
	AttackableUnitIdentifier = (1 << 9),
	AIBaseClient = (1 << 10),
	AIMinionClient = (1 << 11),
	AIHeroClient = (1 << 12),
	AITurretClient = (1 << 13),
	UnknownClient_1 = (1 << 14),
	AIMissileClient = (1 << 15),
	UnknownClient_2 = (1 << 16),
	BuildingProps = (1 << 17),
	UnknownClient_3 = (1 << 18),
};


class GameObject {
public:
	DWORD base;
	int team;
	char name[32];
	DWORD networkid;
	float posX;
	float posY;
	float posZ;
	Vector3 position;
	bool visible;
	float mana;
	float ammo;
	int recallstate;
	float health;
	float bonusatk;
	float bonusap;
	float baseatk;
	float critrate;
	float armor;
	float bonusarmor;
	float mr;
	float bonusmr;
	float movespeed;
	float atkrange;
	float currentgold;
	float totalgold;
	float dirX;
	float dirY;
	float dirZ;
	Vector3 direction;
	//BuffManager
	float boundingradius;
	//Spellbook
	//AIManager
	char championname[32];
	int skillpoints;
	int level;
	unsigned int is_alive;

	GameObject() {
		base = NULL;
		strcpy(name, "null");
		team = -1;
	}

	GameObject(DWORD offset) {
		base = offset;
		LeagueUtils::GetStr(offset + oObjName, name);
		LeagueUtils::GetStr(offset + oObjChampionName, championname);
		ReadProcessMemory(handle, (void*)(offset + oObjTeam), (PBYTE)&team, sizeof(team), 0);
		position = GetPos();
	}

	Vector3 GetPos() {
		Vector3 position;
		float posX;
		float posY;
		float posZ;
		ReadProcessMemory(handle, (void*)(base + oObjPos), (PBYTE)&posX, sizeof(posX), 0);
		ReadProcessMemory(handle, (void*)(base + oObjPos + 0x4), (PBYTE)&posY, sizeof(posY), 0);
		ReadProcessMemory(handle, (void*)(base + oObjPos + 0x8), (PBYTE)&posZ, sizeof(posZ), 0);
		position = Vector3(posX, posY, posZ);
		return position;
	}

	bool IsVisible() {
		bool visible;
		ReadProcessMemory(handle, (void*)(base + oObjVisibility), (PBYTE)&visible, sizeof(visible), 0);
		return visible;
	}

	bool IsValid() {
		int team;
		ReadProcessMemory(handle, (void*)(base + oObjTeam), (PBYTE)&team, sizeof(team), 0);

		if (team == 0 || team == 100 || team == 200 || team == 300) {
			static char name[32];
			LeagueUtils::GetStr(base + oObjName, name);

			if (strcmp(name, "") != 0)
				return true;
		}
		return false;
	}

	DWORD GetNetworkID() {
		DWORD networkid;
		ReadProcessMemory(handle, (void*)(base + oObjNetworkID), (PBYTE)&networkid, sizeof(networkid), 0);
		return networkid;
	}

	char* GetName() {
		static char name[32];
		LeagueUtils::GetStr(base + oObjName, name);
		return name;
	}

	char* GetChampionName() {
		static char championname[32];
		LeagueUtils::GetStr(base + oObjChampionName, championname);
		return championname;
	}

	int GetTeam() {
		int team;
		ReadProcessMemory(handle, (void*)(base + oObjTeam), (PBYTE)&team, sizeof(team), 0);
		return team;
	}

	bool IsEnemyTo(GameObject object) {
		if (object.team == 100 && team == 200)
			return true;

		else if (object.team == 200 && team == 100)
			return true;

		return false;
	}

	bool IsJungle() {
		if (team == 300)
			return true;

		return false;
	}

	int GetLevel() {
		int level;
		ReadProcessMemory(handle, (void*)(base + oObjLevel), (PBYTE)&level, sizeof(level), 0);
		return level;
	}

	float GetHealth() {
		float health;
		ReadProcessMemory(handle, (void*)(base + oObjHealth), (PBYTE)&health, sizeof(health), 0);
		return health;
	}

	float GetMaxHealth() {
		float maxhealth;
		ReadProcessMemory(handle, (void*)(base + oObjHealth + 0x10), (PBYTE)&maxhealth, sizeof(maxhealth), 0);
		return maxhealth;
	}

	inline float GetEffectiveHP() {
		return GetHealth() * (100.0f + GetArmor()) / 100.0f;
	}

	float GetMana() {
		float mana;
		ReadProcessMemory(handle, (void*)(base + oObjMana), (PBYTE)&mana, sizeof(mana), 0);
		return mana;
	}

	float GetMaxMana() {
		float maxmana;
		ReadProcessMemory(handle, (void*)(base + oObjMana + 0x10), (PBYTE)&maxmana, sizeof(maxmana), 0);
		return maxmana;
	}

	inline float GetTotalDamage(GameObject target) {
		return GetTotalAD() * (100 / (100 + target.GetArmor()));
	}

	float GetArmor() {
		float armor;
		ReadProcessMemory(handle, (void*)(base + oObjArmor), (PBYTE)&armor, sizeof(armor), 0);
		return armor;
	}

	float GetBaseAD() {
		float basead;
		ReadProcessMemory(handle, (void*)(base + oObjBaseAtk), (PBYTE)&basead, sizeof(basead), 0);
		return basead;
	}

	float GetBonusAD() {
		float bonusad;
		ReadProcessMemory(handle, (void*)(base + oObjBonusAtk), (PBYTE)&bonusad, sizeof(bonusad), 0);
		return bonusad;
	}

	float GetTotalAD() {
		return GetBaseAD() + GetBonusAD();
	}

	float GetMovementSpeed() {
		float movespeed;
		ReadProcessMemory(handle, (void*)(base + oObjMoveSpeed), (PBYTE)&movespeed, sizeof(movespeed), 0);
		return movespeed;
	}

	float GetAttackRange() {
		float atkrange;
		ReadProcessMemory(handle, (void*)(base + oObjAtkRange), (PBYTE)&atkrange, sizeof(atkrange), 0);
		return atkrange;
	}

	bool IsAlive() {
		ReadProcessMemory(handle, (void*)(base + oIsAlive), (PBYTE)&is_alive, sizeof(is_alive), 0);
		if (!(is_alive & 1))
		{
			//ALIVE
			return true;
		}
		else
		{
			//DEAD
			return false;
		}
		//return GetHealth() > 0.f;
	}

	bool IsKillable(GameObject source)
	{
		//cout << GetTotalAD() * (100.0f / (100.0f + target.GetArmor())) << endl;
		if (GetEffectiveHP() <= source.GetTotalAD())
		{
			return true;
		}
		else
		{
			//cout << target.GetName() << " | NOT KILLABLE" << endl;
			return false;
		}
		//return GetTotalAD() * (100.0f / (100.0f + target.GetArmor()));
	}

	float GetDistTo(GameObject object) {
		return GetPos().DistTo(object.GetPos());
	}
};
#endif