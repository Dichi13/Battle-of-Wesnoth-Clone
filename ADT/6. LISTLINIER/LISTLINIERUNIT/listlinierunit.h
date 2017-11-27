/**
Filename: listlinierunit.h
Description: ADT List dengan infotype Unit
**/

#include "unit.h"
#include "stdio.h"
#include "pcolor.h"
#include "stdlib.h"

#define Nil NULL

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

void CreateEmptyListUnit(UnitList *L);
/* Membuat UnitList *L Kosong */

addressUnit AlokUnit(Unit X);
/* Alokasi unit U */

void DealokUnit(addressUnit U);
/* Dealokasi U */

boolean IsEmptyUnitList(UnitList L);
/* Mengirimkan True jika UnitList L Kosong */

void InsertFirstUnit(UnitList *L, Unit X);
/* Insert elemen Unit X ke dalam ListUnit L */

