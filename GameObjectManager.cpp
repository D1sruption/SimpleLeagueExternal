#include "GameObjectManager.h"
#include "main.h"

#include <vector>
#include <string>
#include <mutex>

GameObject g_localPlayer;
DWORD dw_localPlayer;

GameObjectManager* g_objectManager = new GameObjectManager;
DWORD dw_objectManager;

std::vector<GameObject> g_heroVector;
std::mutex g_heroVectorMutex;
DWORD dw_ManagerTemplate_AIHeroClient_;

std::vector<GameObject> g_minionVector;
std::mutex g_minionVectorMutex;
DWORD dw_ManagerTemplate_AIMinionClient_;

std::vector<GameObject> g_turretVector;
std::mutex g_turretVectorMutex;
DWORD dw_ManagerTemplate_AITurretClient_;

std::vector<GameObject> g_inhibitorVector;
std::mutex g_inhibitorVectorMutex;
DWORD dw_ManagerTemplate_AIInhibitorClient_;

namespace ObjectManager {
	std::vector<GameObject> GetHeroVector(DWORD mgrtmp) {
		DWORD dw_heroVector;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x4), (PBYTE)&dw_heroVector, sizeof(dw_heroVector), 0);

		int vecSize;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x8), (PBYTE)&vecSize, sizeof(vecSize), 0);

		g_heroVectorMutex.lock();
		g_heroVector.clear();
		GameObject object;
		for (size_t i = 0; i < vecSize; i++) {
			ReadProcessMemory(handle, (void*)(dw_heroVector + 0x4 * i), (PBYTE)&object, sizeof(object), 0);
			object = GameObject(object.base);
			if (!object.IsValid())
				continue;
			g_heroVector.push_back(object);
		}
		g_heroVectorMutex.unlock();
		return g_heroVector;
	}

	std::vector<GameObject> GetMinionVector(DWORD mgrtmp) {
		DWORD dw_minionVector;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x4), (PBYTE)&dw_minionVector, sizeof(dw_minionVector), 0);

		int vecSize;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x8), (PBYTE)&vecSize, sizeof(vecSize), 0);

		g_minionVectorMutex.lock();
		g_minionVector.clear();
		GameObject object;
		for (size_t i = 0; i < vecSize; i++) {
			//auto ST = std::chrono::steady_clock::now();
			ReadProcessMemory(handle, (void*)(dw_minionVector + 0x4 * i), (PBYTE)&object, sizeof(object), 0);
			object = GameObject(object.base);
			if (!object.IsValid())
				continue;
			g_minionVector.push_back(object);
			//auto ET = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - ST);
			//printf("Elapsed MS: %d\n", ET.count());
		}
		g_minionVectorMutex.unlock();
		return g_minionVector;
	}

	std::vector<GameObject> GetTurretVector(DWORD mgrtmp) {
		DWORD dw_turretVector;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x4), (PBYTE)&dw_turretVector, sizeof(dw_turretVector), 0);

		int vecSize;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x8), (PBYTE)&vecSize, sizeof(vecSize), 0);

		g_turretVectorMutex.lock();
		g_turretVector.clear();
		GameObject object;
		for (size_t i = 0; i < vecSize; i++) {
			ReadProcessMemory(handle, (void*)(dw_turretVector + 0x4 * i), (PBYTE)&object, sizeof(object), 0);
			object = GameObject(object.base);
			if (!object.IsValid())
				continue;
			g_turretVector.push_back(object);
		}
		g_turretVectorMutex.unlock();
		return g_turretVector;
	}

	std::vector<GameObject> GetInhibitorVector(DWORD mgrtmp) {
		DWORD dw_inhibitorVector;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x4), (PBYTE)&dw_inhibitorVector, sizeof(dw_inhibitorVector), 0);

		int vecSize;
		ReadProcessMemory(handle, (void*)(mgrtmp + 0x8), (PBYTE)&vecSize, sizeof(vecSize), 0);

		g_inhibitorVectorMutex.lock();
		g_inhibitorVector.clear();
		GameObject object;
		for (size_t i = 0; i < vecSize; i++) {
			ReadProcessMemory(handle, (void*)(dw_inhibitorVector + 0x4 * i), (PBYTE)&object, sizeof(object), 0);
			object = GameObject(object.base);
			if (!object.IsValid())
				continue;
			g_inhibitorVector.push_back(object);
		}
		g_inhibitorVectorMutex.unlock();
		return g_inhibitorVector;
	}

	bool Init() {
		ReadProcessMemory(handle, (void*)(baseAddress + oLocalPlayer), (PBYTE)&dw_localPlayer, sizeof(dw_localPlayer), 0);
		g_localPlayer = GameObject(dw_localPlayer);

		ReadProcessMemory(handle, (void*)(baseAddress + oObjManager), (PBYTE)&dw_objectManager, sizeof(dw_objectManager), 0);
		*g_objectManager = GameObjectManager(dw_objectManager);

		ReadProcessMemory(handle, (void*)(baseAddress + oHeroList), (PBYTE)&dw_ManagerTemplate_AIHeroClient_, sizeof(dw_ManagerTemplate_AIHeroClient_), 0);
		GetHeroVector(dw_ManagerTemplate_AIHeroClient_);

		ReadProcessMemory(handle, (void*)(baseAddress + oMinionList), (PBYTE)&dw_ManagerTemplate_AIMinionClient_, sizeof(dw_ManagerTemplate_AIMinionClient_), 0);
		GetMinionVector(dw_ManagerTemplate_AIMinionClient_);

		ReadProcessMemory(handle, (void*)(baseAddress + oTurretList), (PBYTE)&dw_ManagerTemplate_AITurretClient_, sizeof(dw_ManagerTemplate_AITurretClient_), 0);
		GetTurretVector(dw_ManagerTemplate_AITurretClient_);

		ReadProcessMemory(handle, (void*)(baseAddress + oInhibitorList), (PBYTE)&dw_ManagerTemplate_AIInhibitorClient_, sizeof(dw_ManagerTemplate_AIInhibitorClient_), 0);
		GetInhibitorVector(dw_ManagerTemplate_AIInhibitorClient_);

		return true;
	}

	void UpdateLists() {
		while (true)
		{
			GetMinionVector(dw_ManagerTemplate_AIMinionClient_);
			GetHeroVector(dw_ManagerTemplate_AIHeroClient_);
		}
	}


};