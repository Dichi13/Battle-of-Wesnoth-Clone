/**
Filename: matriks_driver.c (driver of matriks.h)
Description: ADT Matriks dengan Tipe Element Plot (dalam plot.h)
**/

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	MATRIKS M;
	int x, y;
	boolean Eff;
	
	/* MakeMATRIKS */
	printf("Input jumlah baris dan kolom matriks : ");
	scanf("%d %d", &x, &y);
	
	MakeMATRIKS(x, y, &M);
	
	printf("NBrsEff = %d\n", NBrsEff(M));
	printf("NKolEff = %d\n\n", NKolEff(M));
	
	printf("GetFirstIdxBrs = %d\n", GetFirstIdxBrs(M));
	printf("GetFirstIdxKol = %d\n", GetFirstIdxKol(M));
	printf("GetLastIdxBrs = %d\n", GetLastIdxBrs(M));
	printf("GetLastIdxKol = %d\n\n", GetLastIdxKol(M));
	printf("NBElmt = %d\n", NBElmt(M));
	
	printf("IsIdxEff (masukan indeks i j) : ");
	scanf("%d %d", &x, &y);
	Eff = IsIdxEff (M, x, y);
	printf("\nIsIdxEff = ");
	if(Eff){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	/* GetElmtDiagonal tidak di test pada driver matriks karena tipe plot hanya bisa di print lewat map, yang diprint lewat command.h */
	
	return 0;	
}
