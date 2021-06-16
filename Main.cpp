#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <TlHelp32.h>
#include <tchar.h>
#include <thread>

#include "GameObjectManager.h"

using namespace std;

DWORD baseAddress;
DWORD procID;
HANDLE handle;

DWORD dwGetModuleBaseAddy(TCHAR* lpszModuleName, DWORD pID)
{
    // FUNCTION TO GET THE BASE MODULE ADDRESS IN THIS CASE LEAGUE.EXE WHICH IS DYNAMICALLY ALLOCATED IN RAM

    DWORD dwModuleBaseAddress = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
    MODULEENTRY32 ModuleEntry32 = { 0 };
    ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshot, &ModuleEntry32))
    {
        do
        {
            if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
            {
                dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshot, &ModuleEntry32));
    }
    CloseHandle(hSnapshot);
    return dwModuleBaseAddress;
}

int main()
{
    thread t1;
    cout << "Attempting to get window..." << endl;

    HWND hwnd = FindWindowA(NULL, "League of Legends (TM) Client");

    if (hwnd == NULL) 
    {
        cout << "Error getting handle!" << endl;

    }
    else 
    {
        GetWindowThreadProcessId(hwnd, &procID);

        char moduleName[] = "League of Legends.exe";
        baseAddress = dwGetModuleBaseAddy((TCHAR*)moduleName, procID);

        handle = OpenProcess(PROCESS_VM_READ, false, procID);
        if (handle == NULL) 
        {
            cout << "Error opening process handle!" << endl;
        }
        else 
        {
            DWORD LocalPlayer;
            char pName[16];

            cout << "[+] Process ID: " << procID << endl;
            //cout << "Base Address: " << baseAddress << endl;
            printf("[+] Base Address: 0x%X\n\n", baseAddress);

            ObjectManager::Init();

            cout << "Player Name: " << g_heroVector[0].GetName() << "\n" << endl;

            for (int i = 0; i < g_minionVector.size(); i++)
            {
                cout << g_minionVector[i].GetName() << endl;
            }

            t1 = thread(ObjectManager::UpdateLists);
            t1.join();

        }

    }

    return 0;
}
