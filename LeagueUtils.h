#ifndef __UTILS_H__
#define __UTILS_H__

#pragma warning(disable : 4996)

#include "math.h"
#include <string>
#include <Windows.h>
#include "Main.h"

#define SCREENWIDTH 1920
#define SCREENHEIGHT 1080

#define INRANGE(x,a,b)   (x >= a && x <= b)
#define GET_BYTE( x )    (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

#define STR_MERGE_IMPL(x, y)				x##y
#define STR_MERGE(x,y)						STR_MERGE_IMPL(x,y)
#define MAKE_PAD(size)						BYTE STR_MERGE(pad_, __COUNTER__) [ size ]

#define DEFINE_MEMBER_0(x, y)				x
#define DEFINE_MEMBER_N(x,offset)			struct { MAKE_PAD(offset); x; }

class LeagueUtils {
	static BYTE ReadByte(DWORD pid, DWORD module, DWORD pCur) {
		BYTE byte;
		ReadProcessMemory(handle, (void*)pCur, &byte, sizeof(byte), 0);
		return byte;
	}

public:
	static bool GetStr(DWORD offset, char* outArr) {
		int len;
		ReadProcessMemory(handle, (void*)(offset + 0x10), (PBYTE)&len, sizeof(len), 0);
		if (len > 15) {
			static char string[32];
			DWORD tmpCharArr;
			ReadProcessMemory(handle, (void*)offset, (PBYTE)&tmpCharArr, sizeof(tmpCharArr), 0);
			ReadProcessMemory(handle, (void*)tmpCharArr, (PBYTE)&string, sizeof(string), 0);
			for (int i = 0; i < 32; i++) {
				outArr[i] = string[i];
			}
			return true;
		}
		else {
			static char string[16];
			ReadProcessMemory(handle, (void*)offset, (PBYTE)&string, sizeof(string), 0);
			for (int i = 0; i < 16; i++) {
				outArr[i] = string[i];
			}
			return true;
		}
		return false;
	}

	static std::string ConvertToString(char* a, int size) {
		int i;
		std::string s = "";
		for (i = 0; i < size; i++) {
			s = s + a[i];
		}
		return s;
	}


	static char* ConvertToChar(std::string str, char out[]) {
		strcpy(out, str.c_str());
		return out;
	}
};
#endif