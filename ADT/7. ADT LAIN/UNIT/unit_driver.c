/**
Filename: unit_driver.c (driver of unit.h)
Description: ADT Unit
**/

#include "boolean.h"
#include "unit.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	int i,x ,y;
	POINT P;
	int PlayerNo;
	Unit U1, U2;
	
	/* MakeMATRIKS */
	
	printf("Inisiasi UnitTypeList : \n");
	InitUnitTypeList();
	for(i = 0; i <= 3; i++){ /* diketahui ada 4 jenis unit */
		printf("Unit %d\n", i);
		printf("TypeName = %s\n", TypeList[i].TypeName);
		printf("MaxHP = %d\n", TypeList[i].MaxHP);
		printf("Attack = %d\n", TypeList[i].Atk);
		printf("MaxMove = %d\n", TypeList[i].MaxMove);
		printf("Attack Type = %c\n", TypeList[i].AtkType);
		printf("Cost = %dG\n", TypeList[i].Cost);
		printf("\n");
	}
	printf("\n");
	
	printf("Create Unit1 : \n");
	printf("Masukan Index jenis unit, posisi unit, dan pemilik :\n");
	scanf("%d ", &i);
	BacaPOINT(&P);
	scanf("%d", &PlayerNo);
	
	U1 = CreateUnit(i, P, PlayerNo);
	printf("Unit yang terbentuk : \n");
	printf("Nomor Player Pemilik : %d\n", OwnerUnit(U1));
	printf("TypeName = %s\n", TypeName(U1));
	printf("MaxHP = %d\n", MaxHP(U1));
	printf("Health = %d\n", Health(U1));
	printf("Attack = %d\n", Atk(U1));
	printf("MaxMove = %d\n", MaxMove(U1));
	printf("Move Point = %d\n", MovePoint(U1));
	printf("Attack Type = %c\n", AtkType(U1));
	printf("CanAtk = ");
	if (CanAtk(U1)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("Position : "); TulisPOINT(Position(U1)); printf("\n\n");
	
	printf("Create Unit2 : \n");
	printf("Masukan Index jenis unit, posisi unit, dan pemilik :\n");
	scanf("%d ", &i);
	BacaPOINT(&P);
	scanf("%d", &PlayerNo);
	
	U2 = CreateUnit(i, P, PlayerNo);
	printf("Unit yang terbentuk : \n");
	printf("Nomor Player Pemilik : %d\n", OwnerUnit(U2));
	printf("TypeName = %s\n", TypeName(U2));
	printf("MaxHP = %d\n", MaxHP(U2));
	printf("Health = %d\n", Health(U2));
	printf("Attack = %d\n", Atk(U2));
	printf("MaxMove = %d\n", MaxMove(U2));
	printf("Move Point = %d\n", MovePoint(U2));
	printf("Attack Type = %c\n", AtkType(U2));
	printf("CanAtk = ");
	if (CanAtk(U2)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("Position : "); TulisPOINT(Position(U2)); printf("\n\n");
	
	printf("MoveUnit (Unit 1) : \n");
	printf("Jarak x y : ");
	scanf("%d %d", &x, &y);
	MoveUnit(&U1, x, y);
	printf("Position : "); TulisPOINT(Position(U1)); printf("\n\n");
	printf("\n");
	
	printf("IsAdjacent(U1,U2) : ");
	if(IsAdjacent(U1, U2)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("\n");
	
	printf("CanRetaliate(U1,U2) : ");
	if(CanRetaliate(U1, U2)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("\n");
	
	printf("RefreshUnit(U1) : \n");
	RefreshUnit(&U1);
	printf("Move Point = %d\n", MovePoint(U1));
	printf("Attack Type = %c\n", AtkType(U1));
	printf("CanAtk = ");
	if (CanAtk(U1)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("\n");
	
	printf("UnreadyUnit(U1) : \n");
	UnreadyUnit(&U1);
	printf("Move Point = %d\n", MovePoint(U1));
	printf("Attack Type = %c\n", AtkType(U1));
	printf("CanAtk = ");
	if (CanAtk(U1)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("\n");
	
	printf("HealUnit(U1, x) : ");
	printf("Health Unit U1 telah dikurangi sebesar 5\n");
	Health(U1) -= 5;
	printf("Health = %d/%d\n", Health(U1), MaxHP(U1));
	printf("\n");
	printf("x = ");
	scanf("%d", &x);
	HealUnit(&U1, x);
	printf("Health = %d/%d\n", Health(U1), MaxHP(U1));
	
	return 0;	
}
