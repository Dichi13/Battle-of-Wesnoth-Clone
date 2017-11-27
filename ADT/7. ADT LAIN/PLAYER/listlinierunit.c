/**
Filename: listlinierunit.c
Description: ADT List dengan infotype Unit
**/

#include "unit.h"
#include "stdio.h"
#include "pcolor.h"
#include "stdlib.h"

typedef Unit infounit;
typedef struct LUnit *addressUnit;
typedef struct LUnit {
	infounit infoU;
	addressUnit nextU;
} ElmtUnitList;

typedef addressUnit UnitList;

/* Selektor List Unit */
#define InfoUnit(U) (U)->infoU      //U = addressUnit (Pointer ke tipe ElmtUnitList)
#define NextUnit(U)	(U)->nextU		//U = addressUnit
#define FirstUnit(L) (L)			//L = UnitList

void CreateEmptyListUnit(UnitList *L)
{
	FirstUnit(*L) = Nil;
}

addressUnit AlokUnit(Unit X) 
{
	/* KAMUS LOKAL */
	addressUnit U;
	
	/* ALGORITMA */
	U = (addressUnit) malloc (sizeof(ElmtUnitList));
	if (U != Nil) {
		InfoUnit(U) = X;
		NextUnit(U) = Nil;
	}

	return U;
}

void DealokUnit(addressUnit U) 
{
	free(U);
}

boolean IsEmptyUnitList(UnitList L) 
{
	return (FirstUnit(L) == Nil);
}

void InsertFirstUnit(UnitList *L, Unit X)
{
	/* KAMUS LOKAL */
	addressUnit U;
	
	/* ALGORITMA */
	U = AlokUnit(X);
	NextUnit(U) = FirstUnit(*L);
	FirstUnit(*L) = U;
}
