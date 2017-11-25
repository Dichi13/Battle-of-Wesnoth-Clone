#ifndef _UNIT_H_
#define _UNIT_H_

#include "boolean.h"
#include "point.h"
#include "mesinkata.h"
#include <string.h>

#define Nil NULL
/* Definisi Tipe Unit */

typedef struct Utype{
	char *TypeName;
	int MaxHP;
	int Atk;
	int MaxMove;
	char AtkType;   // 'M' for melee, 'R' for ranged, 'K' for king
	int Cost;
} UnitType;	

typedef struct tUnit{
	int TypeIdx;
	int Owner;
	int Health;
	int Move;
	boolean Action;
	POINT Position;
} Unit;

/* variabel global */
extern UnitType *TypeList;
extern int NbUnitType;

/* selektor konstanta unit */
#define TypeName(U) TypeList[(U).TypeIdx].TypeName
#define MaxHP(U) TypeList[(U).TypeIdx].MaxHP
#define Atk(U) TypeList[(U).TypeIdx].Atk
#define MaxMove(U) TypeList[(U).TypeIdx].MaxMove
#define AtkType(U) TypeList[(U).TypeIdx].AtkType
#define Cost(U) TypeList[(U).TypeIdx].Cost

/* selektor variabel unit */ 
#define TypeID(U) (U).TypeIdx
#define OwnerUnit(U) (U).Owner
#define Health(U) (U).Health
#define MovePoint(U) (U).Move
#define CanAtk(U) (U).Action
#define Position(U) (U).Position


/* Primitif- priitif unit */

void InitUnitTypeList();
/* I.S. TypeList sembarang, terdapat file "unittype.txt" di folder yang sama */
/* F.S. TypeList terdefinisi dan terisi dengan tipe-tipe unit yang digunakan dalam game */ 

Unit CreateUnit(int IdxList, POINT P, int ownerNo);
/* Membuat unit baru dengan tipe unit yang terdapat pada TypeList[IdxList] */
/* Unit yang baru dibuat tidak dapat bergerak dan tidak bisa menyerang */

void MoveUnit(Unit *U, int dx, int dy);
/* I.S. U terdefinisi, dx dan dy valid */
/* F.S. Menggeser lokasi unit sejauh (dx,dy) */

boolean IsAdjacent(Unit U1, Unit U2);
/* mengembalikan true jika kedua unit berjarak satu petak. */

void UnreadyUnit(Unit *U);
/* I.S. Unit terdefinisi */
/* F.S. MovePoint unit menjadi 0 dan boolean Actionnya false */

boolean CanRetaliate(Unit U1, Unit U2);
/* Menghasilkan true jika tipe attack Unit U2 dapat retaliate jika diserang U1 */

void RefreshUnit(Unit *U);
/* I.S. U terdefinisi */
/* F.S MovePoint(U) berisi move point maksimum dan CanAtk(U) bernilai true */

void HealUnit(Unit *U, int heal);
/* I.S. U terdefinisi */
/* F.S Health(U) bertambah sebanyak heal jika tidak melebihi MaxHP(U), jika melebihi, 
 * Health(U) menjadi bernilai MaxHP(U) */ 

#endif
