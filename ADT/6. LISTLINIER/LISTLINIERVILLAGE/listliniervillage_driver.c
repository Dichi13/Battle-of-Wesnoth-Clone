/**
Filename: listliniervillage_driver.c (driver of listliniervillage.h)
Description: ADT listlinier dengan Tipe Element POINT
**/

#include "boolean.h"
#include "listliniervillage.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	VillageList L;
	POINT P;
	addressPoint AP;
	
	/* MakeMATRIKS */
	printf("Create Empty VillageList L : \n");
	CreateEmptyListVillage(&L);
	printf("IsEmptyVillageList : ");
	if(IsEmptyVillageList(L)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("\n");
	printf("InsertFirstVillaget : \n");
	P = MakePOINT(1, 1);
	InsertFirstVillage(&L, P);
	P = MakePOINT(6, 9);
	InsertFirstVillage(&L, P);
	printf("IsEmptyVillageList : ");
	if(IsEmptyVillageList(L)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	AP = FirstVillage(L);
	
	printf("POINT dalam list ((6,9), (1,1)) : \n");
	printf("Isi List : \n");
	while (AP != Nil){
		TulisPOINT(InfoVillage(AP));
		printf("\n");
		AP = NextVillage(AP);
	}
	
	
	return 0;	
}
