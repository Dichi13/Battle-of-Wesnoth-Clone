/* Deskripsi		: Driver ADT Jam */
/* File: jam_driver.c */

#include "jam.h"
#include <math.h>
#include <stdio.h>
#include "boolean.h"

int main () 
{
	/* KAMUS */
	
	JAM J0, J1, J2;
	long S;
	int N;
	
	/* ALGORITMA */
	
	printf("Baca Jam : ");
	BacaJAM(&J0);
	TulisJAM(J0);
	printf("\n");

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
	
	printf("Jam to Detik : ");
	BacaJAM(&J0);
	S = JAMToDetik(J0);
	printf("%ld\n", S);

	printf("Detik to Jam : ");
	scanf("%ld\n", &S);
	J0 = DetikToJAM(S);
	TulisJAM(J0);
	printf("\n");

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
	
	printf("JEQ : ");
	BacaJAM(&J1);
	BacaJAM(&J2);
	if (JEQ (J1, J2))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	
	printf("JNEQ : ");
	BacaJAM(&J1);
	BacaJAM(&J2);
	if (JNEQ (J1, J2))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	
	printf("JLT : ");
	BacaJAM(&J1);
	BacaJAM(&J2);
	if (JLT (J1, J2))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	
	printf("JGT : ");
	BacaJAM(&J1);
	BacaJAM(&J2);
	if (JGT (J1, J2))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

/* *** Operator aritmatika JAM *** */
	
	printf("Next Detik : ");
	BacaJAM(&J0);
	J1 = NextDetik(J0);
	TulisJAM(J1);
	printf("\n");
	
	printf("Next N Detik : ");
	BacaJAM(&J0);
	scanf("%d", &N);
	J1 = NextNDetik(J0, N);
	TulisJAM(J1);
	printf("\n");
	
	printf("Prev Detik : ");
	BacaJAM(&J0);
	J1 = PrevDetik(J0);
	TulisJAM(J1);
	printf("\n");
	
	printf("Prev N Detik : ");
	BacaJAM(&J0);
	scanf("%d", &N);
	J1 = PrevNDetik(J0, N);
	TulisJAM(J1);
	printf("\n");
	
	printf("Durasi : ");
	BacaJAM(&J1);
	BacaJAM(&J2);
	S = Durasi(J1, J2);
	printf("%ld", S);
	
	return 0;

}
