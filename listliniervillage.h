/**
Filename: listliniervillage.h
Description: ADT List dengan infotype POINT yang melambangkan posisi village player di map
**/

#include "unit.h"
#include "stdio.h"
#include "pcolor.h"
#include "stdlib.h"

#define Nil NULL

typedef POINT infopoint;
typedef struct LPoint* addressPoint;
typedef struct LPoint {
	infopoint infoV;
	addressPoint nextV;
} ElmtVillageList;

typedef addressPoint VillageList;

/* Selektor List Village */
#define InfoVillage(V)	(V)->infoV			// V = addressPoint (Pointer ke tipe ElmtVillageList)
#define NextVillage(V)	(V)->nextV			// V = addressPoint
#define FirstVillage(L) (L) //L = VillageList

void CreateEmptyListVillage(VillageList *L);
/* Membuat VillageList *L Kosong */

addressPoint AlokVillage(POINT P);
/* Alokasi unit Village pada POINT P */

void DealokVillage(addressPoint V);
/* Dealokasi addressPoint V */

boolean IsEmptyVillageList(VillageList L);
/* Mengirimkan True jika VillageList L Kosong */

void InsertFirstVillage(VillageList *L, POINT P);
/* Insert elemen POINT P ke dalam ListVillage L */
