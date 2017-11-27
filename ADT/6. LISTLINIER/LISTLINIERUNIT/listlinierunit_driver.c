/**
Filename: listlinierunit_driver.c (driver of listlinierunit.h)
Description: ADT listlinier dengan Tipe Element Unit
**/

#include "boolean.h"
#include "listlinierunit.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	UnitList L;
	Unit U;
	POINT P;
	addressUnit AU;
	
	/* MakeMATRIKS */
	InitUnitTypeList();
	P = MakePOINT(1, 1);
	U = CreateUnit(0, P, 1);
	
	printf("Create Empty UnitList L : \n");
	CreateEmptyListUnit(&L);
	printf("IsEmptyUnitList : ");
	if(IsEmptyUnitList(L)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("\n");
	printf("InsertFirstUnit : \n");
	InsertFirstUnit(&L, U);
	printf("IsEmptyUnitList : ");
	if(IsEmptyUnitList(L)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	AU = FirstUnit(L);
	
	printf("Unit dalam list (dibentuk King, (1,1), player 1) : \n");
	printf("Nomor Player Pemilik : %d\n", OwnerUnit(InfoUnit(AU)));
	printf("TypeName = %s\n", TypeName(InfoUnit(AU)));
	printf("MaxHP = %d\n", MaxHP(InfoUnit(AU)));
	printf("Health = %d\n", Health(InfoUnit(AU)));
	printf("Attack = %d\n", Atk(InfoUnit(AU)));
	printf("MaxMove = %d\n", MaxMove(InfoUnit(AU)));
	printf("Move Point = %d\n", MovePoint(InfoUnit(AU)));
	printf("Attack Type = %c\n", AtkType(InfoUnit(AU)));
	printf("CanAtk = ");
	if (CanAtk(InfoUnit(AU))){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("Position : "); TulisPOINT(Position(InfoUnit(AU))); printf("\n\n");
	
	
	return 0;	
}
