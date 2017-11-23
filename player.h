#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "unit.h"
#include "stdio.h"
#include "pcolor.h"
#include "stdlib.h"

#define Nil NULL
#define InitGold 200
#define IncomePerVillage 10
#define UpkeepPerUnit 3

typedef Unit infounit;
typedef struct LUnit *addressUnit;
typedef struct LUnit {
	infounit infoU;
	addressUnit nextU;
} ElmtUnitList;

typedef POINT infopoint;
typedef struct LPoint* addressPoint;
typedef struct LPoint {
	infopoint infoV;
	addressPoint nextV;
} ElmtVillageList;

typedef addressUnit UnitList;

typedef addressPoint VillageList;

typedef struct tPlayer{
	int PlayerNo;
	int Gold;
	UnitList UnitP;
	VillageList VillageP;
	int Income;
	int Upkeep;
} Player;

extern Player* currPlayer;
extern Unit* SelectedUnit;

/* Selektor-selektro List Unit */
#define InfoUnit(U) (U)->infoU      //U = addressUnit (Pointer ke tipe ElmtUnitList)
#define NextUnit(U)	(U)->nextU		//U = addressUnit
#define FirstUnit(L) (L)			//L = UnitList
#define InfoVillage(V)	(V)->infoV			// V = addressPoint (Pointer ke tipe ElmtVillageList)
#define NextVillage(V)	(V)->nextV			// V = addressPoint
#define FirstVillage(L) (L) //L = VillageList

/* Selektor-selektor Player*/
#define PlayerNo(P) (P).PlayerNo
#define Gold(P) (P).Gold
#define Income(P) (P).Income
#define Upkeep(P) (P).Upkeep
#define ListUnit(P) (P).UnitP
#define ListVillage(P) (P).VillageP

/* Primitif-primitif Player */

addressUnit AlokUnit(Unit U);
/* Alokasi unit U */
void DealokUnit(addressUnit U);
/* Dealokasi U */
boolean IsEmptyUnit(Player P);
/* Mengirimkan True jika Player P tidak memiliki unit apapun */
void CreatePlayer(Player *P);
/* Membuat player*/
void PrintUnitPlayer(Player P);
/* Mencetak unit yang dimiliki player */
void AddUnit(Player *P, Unit U);
/* Menambah Unit U ke dalam UnitList Player*/
void DelUnit(Player *P, Unit *U);
/* Menghapus Unit U dari dalam List Unit Player */
void PrintInfoPlayer(Player P);
/* Mencetak info Player P */
addressPoint AlokVillage(POINT P);
/* Alokasi unit Village pada POINT P */
void DealokVillage(addressPoint V);
/* Dealokasi addressPoint V */
boolean IsEmptyVillage(Player P);
/* Mengirimkan True jika Player P tidak memiliki Village apapun */
void AddVillage(Player *PL, POINT P);
/* Menambah Village pada POINT P ke dalam VillageList Player*/
void DelVillage(Player *PL, POINT *P);
/* Menghapus Village pada POINT P ke dalam VillageList Player*/



#endif
