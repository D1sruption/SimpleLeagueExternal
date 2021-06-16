#pragma once
#include <Windows.h>

extern DWORD procID;
extern DWORD baseAddress;
extern HANDLE handle;

int main();
DWORD dwGetModuleBaseAddy(TCHAR* lpszModuleName, DWORD pID);