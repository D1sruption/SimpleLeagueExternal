#define TARGET_GAMEVERSION "Version 10.23.343.2581 [PUBLIC]"

#define oGetBasicAttack 0x001681e0            // 53 8B D9 B8 ? ? ? ? 8B 93
#define oBaseDrawPosition 0x0016a480          // 30 44 14 10 42 3B D1 72 F0 8B 74 24 14 83 7C 24 ? ? 74
#define oIsDragon 0x00173470                  // 83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 81
#define oIsBaron 0x00175320                   // 56 81 C1 ? ? ? ? E8 ? ? ? ? 68
#define oIssueOrder 0x001753d0                // 56 57 8B F9 C7 84 24 ? ? ? ? ? ? ? ? 8B 87
#define oIsAlive 0x0019f580                   // 56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19
#define oIsInhib 0x001adc40                   // E8 ? ? ? ? 55 88 44 24 1F
#define oIsNexus 0x001add40                   // E8 ? ? ? ? 55 88 44 24 20
#define oIsHero 0x001addc0                    // E8 ? ? ? ? 83 C4 04 84 C0 74 52
#define oIsMinion 0x001ade00                  // E8 ? ? ? ? 83 C4 04 80 7F 26 06
#define oIsMissile 0x001ade20                 // E8 ? ? ? ? 83 C4 04 84 C0 74 3F
#define oIsTurret 0x001ae030                  // E8 ? ? ? ? 83 C4 04 84 C0 75 22
#define oIsTargetable 0x001d6300              // 56 8B F1 E8 ? ? ? ? 84 C0 74 2E 8D
#define oGetNextObject 0x0028bb30             // 8B 44 24 04 56 8B 71 18
#define oGetAttackCastDelay 0x002a0ee0        // 83 EC 0C 53 8B 5C 24 14 8B CB 56
#define oGetAttackDelay 0x002a0fe0            // 8B 44 24 04 51 F3
#define oGetPing 0x00332ff0                   // 55 8B EC 83 EC 08 0F B6
#define oGetSpellState 0x004fb1f0             // 83 EC 14 8B 44 24 1C 55
#define oCastSpell 0x00509aaf                 // 50 6A 02 E8 ? ? ? ? 83 C4 14 5B 5F 5D 83 C4 34 C2 14
#define oDrawCircle 0x00519d70                // 33 C4 89 84 24 ? ? ? ? F3 0F 10 84 24 ? ? ? ? 8D 0C
#define oGameVersion 0x0055c300               // E8 ? ? ? ? 50 FF 36 8D 44 24 6C
#define oPrintChat 0x005a5730                 // 83 EC 44 A1 ? ? ? ? 33 C5 89 45 FC 53 8B 5D 0C 56 8B
#define oSendChat 0x005ef540                  // A1 ? ? ? ? 56 6A FF
#define oIsNotWall 0x008f38b0                 // 85 FF 0F 48 C3 0F AF C8 8B 86 ? ? ? ? 5F 5E 5B 03 CA 8D
#define oWorldToScreen 0x0097be80             // 83 EC 10 56 E8 ? ? ? ? 8B 08
#define oUnderMouseObject 0x01c100f0          // 8B 0D ? ? ? ? 89 0D
#define oChatClientPtr 0x01c6e030             // 8B 0D ? ? ? ? 6A 00 50 E8 ? ? ? ? 33
#define oObjManager 0x01c706b0                // 8B 0D ? ? ? ? 89 74 24 14
#define oHudInstance 0x01c706e8               // 8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0 01 C2
#define oZoomClass 0x03504afc                 // A3 ? ? ? ? 83 FA 10 72 32
#define oGameTime 0x03505318                  // F3 0F 11 05 ? ? ? ? 8B 49
#define oGameInfo 0x035064ac                  // A1 ? ? ? ? 83 78 08 02 0F 94
#define oMenuGUI 0x0350cc38                   // 8B 0D ? ? ? ? 6A 00 E8 ? ? ? ? C7
#define oLocalPlayer 0x0350d168               // A1 ? ? ? ? 85 C0 74 07 05 ? ? ? ? EB 02 33 C0 56
#define oNetClient 0x0351446c                 // 8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oPingInstance 0x0351446c              // 8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oRenderer 0x03535c3c                  // 8B 15 ? ? ? ? 83 EC 08
#define oD3DRenderer 0x035389e0               // A1 ? ? ? ? 89 54 24 18

#define oViewMatrix 0xFFF //UPDATE
//CObject UPDATE
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x6C
#define oObjNetworkID 0xCC //
#define oObjPos 0x1D8 //220
#define oObjVisibility 0x270
#define oObjHealth 0xDC4
#define oObjMana 0x298
#define oObjMaxMana 0x2A8
#define oObjArmor 0x12B0
#define oObjMagicRes 0x12B8
#define oObjBonusMagicRes 0x12BC
#define oObjBaseAtk 0x1288
#define oObjBonusAtk 0x1208
#define oObjMoveSpeed 0x12C8
#define oObjAtkRange 0x12D0
#define oObjBuffMgr 0x2174
#define oObjSpellBook 0x2720
#define oObjChampionName 0x314C
#define oObjLevel 0x36BC
#define oIsAlive 0x218 //TESTING

#define oHeroList 0x1C6E60C        //A1 ? ? ? ? 53 55 56 8B 68 04 8B 40 08 57 33 FF
#define oMinionList 0x28BCCB8      //A1 ? ? ? ? 8B 50 04 8D 48 04 89 44 24 1C	
#define oTurretList 0x35042D0      //8B 0D ? ? ? ? E8 ? ? ? ? 85 C0 74 13 8B 10
#define oInhibitorList 0x350D98C   //8B 15 ? ? ? ? 8B 7A 04 8B 42 08 8D 0C 87 3B F9 73 31 66 90
#define oMissilesList 0x350B4F8