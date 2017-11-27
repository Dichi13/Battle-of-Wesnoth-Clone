/**
Filename: listliniervillage.c
Description: ADT List dengan infotype POINT yang melambangkan posisi village player di map
**/

#include "unit.h"
#include "stdio.h"
#include "pcolor.h"
#include "stdlib.h"

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

void CreateEmptyListVillage(VillageList *L)
{
	FirstVillage(*L) = Nil;
}

addressPoint AlokVillage(POINT P)
{
	addressPoint V;

	V = (addressPoint) malloc (sizeof(ElmtVillageList));
	if (V != Nil) {
		InfoVillage(V) = P;
		NextVillage(V) = Nil;
	}

	return V;
}
/* Alokasi unit Village pada POINT P */

void DealokVillage(addressPoint V)
{
	free(V);
}
/* Dealokasi addressPoint V */

boolean IsEmptyVillageList(VillageList L)
{
	return (FirstVillage(L) == Nil);
}
/* Mengirimkan True jika VillageList L Kosong */

void InsertFirstVillage(VillageList *L, POINT P)
{
	/* KAMUS LOKAL */
	addressPoint V;
	
	/* ALGORITMA */
	V = AlokVillage(P);
	NextVillage(V) = FirstVillage(*L);
	FirstVillage(*L) = V;
}
/* Insert elemen POINT P ke dalam ListVillage L */
