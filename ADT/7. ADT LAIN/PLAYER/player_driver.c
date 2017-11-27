/**
Filename: player_driver.c (driver of player.h)
Description: ADT player
**/

#include "boolean.h"
#include "player.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	Player P;
	int No;
	Unit U;
	addressUnit AU;
	POINT Po;
	
	/* ALGORITMA */
	InitUnitTypeList();
	printf("Player CreatePlayer(int No) : \n");
	printf("No = ");
	scanf("%d", &No);
	
	P = CreatePlayer(No);
	printf("Player No : %d\n", PlayerNo(P));
	printf("\nPrintInfoPlayer : \n");
	PrintInfoPlayer(P);
	
	
	printf("IsEmptyUnit : ");
	if(IsEmptyUnit(P)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("Dibuat unit King, (6,9), untuk Player, lalu dimasukan dalam List\n");
	Po = MakePOINT(6, 9);
	U = CreateUnit(0, Po, No);
	AddUnit(&P, U);
	
	printf("IsEmptyUnit : ");
	if(IsEmptyUnit(P)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("NbElmtListUnit(P) : %d\n", NbElmtListUnit(P));
	printf("\nPrintUnitPlayer : \n");
	PrintUnitPlayer(P);
	
	printf("\nTraversalElmUnitList(P, 1) : \n");
	AU = TraversalElmtUnitList(P, 1);
	printf("Nomor Player Pemilik : %d\n", OwnerUnit(InfoUnit(AU)));
	printf("TypeName = %s\n", TypeName(InfoUnit(AU)));
	printf("MaxHP = %d\n", MaxHP(InfoUnit(AU)));
	printf("Health = %d\n", Health(InfoUnit(AU)));
	printf("Attack = %d\n", Atk(InfoUnit(AU)));
	printf("MaxMove = %d\n", MaxMove(InfoUnit(AU)));
	printf("Attack Type = %c\n", AtkType(InfoUnit(AU)));
	printf("Position : "); TulisPOINT(Position(InfoUnit(AU))); printf("\n\n");
	
	printf("DelUnit : \n");
	DelUnit(&P, &InfoUnit(AU));
	printf("IsEmptyUnit : ");
	if(IsEmptyUnit(P)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	
	printf("\n=========================\n");
	printf("IsEmptyVillage : ");
	if(IsEmptyVillage(P)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("Koordinat village untuk dimasukan dalam list : ");
	BacaPOINT(&Po);
	AddVillage(&P, Po);
	printf("IsEmptyVillage : ");
	if(IsEmptyVillage(P)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("\nDelVillage : \n");
	DelVillage(&P, &Po);
	printf("IsEmptyVillage : ");
	if(IsEmptyVillage(P)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	return 0;
}
