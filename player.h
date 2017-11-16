#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "unit.h"
#include "stdio.h"
#include "pcolor.h"

#define Nil NULL
#define InitGold 200
#define IncomePerVillage 10
#define UpkeepPerUnit 3

typedef struct tPlayer{
	int PlayerNo;
	int Gold;
	UnitList *UnitP;
	VillageList *Village;
	int Income;
	int Upkeep;
} Player;

typedef Unit infounit;
typedef struct LUnit *addressUnit
typedef struct LUnit {
	infounit infoU;
	addressUnit nextU;
} ElmtUnitList;
typedef struct {
	addressUnit FirstUnit;
} UnitList;

typedef POINT infopoint;
typedef struct LPoint *addressPoint
typedef struct LPoint {
	infopoint infoV;
	addressPoint nextV;
} ElmtVillageList;
typedef struct {
	addressPoint FirstVil;
} VillageList;

extern int CurrPlayer;

/* Selektor-selektro List Unit */
#define InfoUnit(U) (U)->infoU
#define NextUnit(U)	(U)->nextU
#define FirstUnit(U) ((U).FirstUnit)
#define InfoVil(V)	(V)->infoV
#define NextVil(V)	(V)->nextV
#define FirstVillage(V) ((V).FirstVillage)

/* Selektor-selektor Player*/
#define PlayerNo(P) (P).PlayerNo
#define Gold(P) (P).Gold
#define Income(P) (P).Income
#define Upkeep(P) (P).Upkeep
#define ListUnit(P) (P).UnitP
#define ListVillage(P) (P).Village

/* Primitif-primitif Player */

void CreatePlayer(Player *P);
/* Membuat player*/

void PrintUnitPlayer(Player P);
/* Mencetak unit yang dimiliki player */





#endif