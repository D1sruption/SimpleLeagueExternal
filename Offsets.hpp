#pragma once

/*
Offset dumper by @Ph4nton
Mon Jul 27 14:30:15 2020
*/

#define BASEADDRESS GetModuleHandle(NULL) 370000
#define oGetAttackDelay 0x2B6D50	//8B 44 24 04 51 F3
#define oGetAttackCastDelay 0x2B6C50	//83 EC 0C 53 8B 5C 24 14 8B CB 56 57 8B 03 FF 90
#define oDrawCircle 0x50B8F0	//E8 ? ? ? ? 83 C4 1C 8B 7C 24 28
#define oIsAlive 0x1B8810	//56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19
#define oIsInhib 0x1CC250	//E8 ? ? ? ? 83 C4 04 84 C0 74 38
#define oIsNexus 0x1CC350	//E8 ? ? ? ? 57 88 44 24 20
#define oIsTurret 0x1CC5C0	//E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F
#define oIsMinion 0x1CC410	//E8 ? ? ? ? 83 C4 04 80 7F 26 06
#define oIsDragon 0x188F80	//83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 81 C1 ? ? ? ?
#define oIsBaron 0x18B030	//E8 ? ? ? ? 84 C0 74 0A BB ? ? ? ?
#define oIsHero 0x1CC3D0	//E8 ? ? ? ? 83 C4 04 84 C0 74 2B
#define oIsMissile 0x0	//E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF
#define oIsTargetable 0x1EFDB0	//56 8B F1 E8 ? ? ? ? 84 C0 74 2E
#define oIssueOrder 0x18B0E0	//81 EC ? ? ? ? 56 57 8B F9 C7
#define oGetSpellState 0x507BB0	//E8 ? ? ? ? 8B F8 8B CB 89
#define oCastSpell 0x0	//83 EC 38 56 8B 74 24 40
#define oGetBasicAttack 0x177590	//53 8B D9 B8 ? ? ? ? 8B 93
#define oUpdateChargeableSpell 0x519080	//E8 ? ? ? ? 8B 43 24 8B 0D ? ? ? ?
#define oIsNotWall 0x8E9850	//E8 ? ? ? ? 33 C9 83 C4 0C 84
#define oGameVersion 0x57C140	//8B 44 24 04 BA ? ? ? ? 2B D0
#define oWorldToScreen 0x966A90	//83 EC 10 56 E8 ? ? ? ? 8B 08
#define oGetFirstObject 0x2BC400	//8B 41 14 8B 51 18
#define oGetNextObject 0x2BD5B0	//E8 ? ? ? ? 8B F0 85 F6 75 E4
#define oChatClientPtr 0x18F10B	//8B 35 ? ? ? ? 52
#define oIsTroy 0xA8B060	//53 56 8B 74 24 10 57 8B 7C 24 10 8A 
#define oLocalPlayer 0x34FF448	//A1 ? ? ? ? 85 C0 74 07 05 ? ? ? ? EB 02 33 C0 56
#define oObjManager 0x1C5C8B0	//8B 0D ? ? ? ? E8 ? ? ? ? FF 77
#define oGameTime 0x34F7704	//F3 0F 11 05 ? ? ? ? 8B 49
#define oHudInstance 0x1C5C8EC	//8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0
#define oRenderer 0x3526534	//8B 15 ? ? ? ? 83 EC 08 F3
#define oD3DRenderer 0x3529200	//A1 ? ? ? ? 89 54 24 18
#define oZoomClass 0x34F6EA4	//A3 ? ? ? ? 83 FA 10 72 32
#define oNetClient 0x35062AC	//8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oUnderMouseObject 0x0	//8B 0D ? ? ? ? 89 0D ? ? ? ? 3B 44 24 30
#define oGameInfo 0x34F8654	//A1 ? ? ? ? 83 78 08 02 0F 94 C0
#define oViewMatrix 0x6C	//8D 4A ? 51 81 C2 ? ? ? ? 52
#define oProjection 0xAC	//8D 4A ? 51 81 C2 ? ? ? ? 52
#define oObjAttackRange 0x14A4	//D8 81 ? ? ? ? 8B 81 ? ? ? ?
