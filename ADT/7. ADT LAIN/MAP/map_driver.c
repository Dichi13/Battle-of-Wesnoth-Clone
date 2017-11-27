/**
Filename: map_driver.c (driver of map.h)
Description: ADT Map dengan menggunakan matriks.h
**/

#include "boolean.h"
#include "map.h"
#include <stdio.h>
#include "command.h"

int main()
{
	/* KAMUS */
	int X, Y;
	POINT P;
	/* MakeMATRIKS */
	printf("Ukuran map : ");
	scanf("%d %d", &X, &Y);
	MakeEmptyMap(X, Y);
	MakeNormalPlot();
	currPlayer = Nil;
	SelectedUnit = Nil;
	
	printf("Peta setelah MakeEmptyMap dan MakeNormalPlot :\n");
	PrintMap();
	printf("\n");
	
	printf("Peta setelah MakePlayerPlot :\n");
	MakePlayerPlot();
	PrintMap();
	printf("\n");
	
	printf("Peta setelah CreateVillage :\n");
	CreateVillage();
	PrintMap();
	printf("\n");
	
	printf("Cek apakah koordinat ada di map : ");
	BacaPOINT(&P);
	printf("IsPlotInMap(M,P) = ");
	if(IsPlotInMap(M,P)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("\n");
	
	
	return 0;	
}
