#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "unit.h"
#include "stdio.h"
#include "pcolor.h"
#include "stdlib.h"
#include "map.h"
#include "listlinierunit.h"
#include "listliniervillage.h"

#define Nil NULL
#define InitGold 150
#define IncomePerVillage 25
#define UpkeepPerUnit 3

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

/* Selektor-selektor Player*/
#define PlayerNo(P) (P).PlayerNo
#define Gold(P) (P).Gold
#define Income(P) (P).Income
#define Upkeep(P) (P).Upkeep
#define ListUnit(P) (P).UnitP
#define ListVillage(P) (P).VillageP

/* Primitif-primitif Player */
Player CreatePlayer(int No);
/* Membuat player */
void PrintUnitPlayer(Player P);
/* Mencetak unit yang dimiliki player */
void PrintInfoPlayer(Player P);
/* Mencetak info Player P */

boolean IsEmptyUnit(Player P);
/* Mengirimkan True jika Player P tidak memiliki unit apapun */
void AddUnit(Player *P, Unit U);
/* Menambah Unit U ke dalam UnitList Player*/
/* Unit pada Peta pada koordinat Position(U) menjadi U */
void DelUnit(Player *P, Unit *U);
/* Menghapus Unit U dari dalam List Unit Player */
int NbElmtListUnit(Player P);
/* Mengembalikan jumlah element ListUnit dari player P */
addressUnit TraversalElmtUnitList (Player P, int i);
/* Mengembalikan Unit ke-i jika dihitung dari depan dari ListUnit Player P */
/* Elemen ke-i ada di ListUnit */

boolean IsEmptyVillage(Player P);
/* Mengirimkan True jika Player P tidak memiliki Village apapun */
void AddVillage(Player *PL, POINT P);
/* Menambah Village pada POINT P ke dalam VillageList Player*/
void DelVillage(Player *PL, POINT *P);
/* Menghapus Village pada POINT P ke dalam VillageList Player*/




#endif
