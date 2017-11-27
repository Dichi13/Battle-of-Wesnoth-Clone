/* Deskripsi		: Driver ADT Point */

#include "point.h"
#include <stdio.h>

int main () 
{
	/* KAMUS */
	
	POINT P0, P1, P2;
	float dx, dy, length, sudut;
	
	/* ALGORITMA */
	        
/* *** TEST Konstruktor membentuk POINT *** */
	
/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */  

	printf("BacaPOINT : ");
	BacaPOINT(&P0); 
	TulisPOINT(P0);
	printf("\n");
	
/* *** Kelompok operasi relasional terhadap POINT *** */

	printf("EQ : ");
	BacaPOINT(&P1);
	BacaPOINT(&P2);
	if (EQ (P1, P2))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}
	
	printf("NEQ : ");
	BacaPOINT(&P1);
	BacaPOINT(&P2);
	if (NEQ (P1, P2))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

/* *** Kelompok menentukan di mana P berada *** */

	printf("IsOrigin : ");
	BacaPOINT(&P0);
	if (IsOrigin (P0))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	printf("IsOnSbX : ");
	BacaPOINT(&P0);
	if (IsOnSbX (P0))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	printf("IsOnSbY : ");
	BacaPOINT(&P0);
	if (IsOnSbY (P0))
	{
		printf("true\n");
	}
	else
	{
		printf("false\n");
	}

	printf("Kuadran dari : ");
	BacaPOINT(&P0);
	printf("%d\n", (Kuadran (P0)));

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */

	printf("NextX : ");
	BacaPOINT(&P0);
	P1 = NextX (P0);
	TulisPOINT(P1);
	printf("\n");

	printf("NextY : ");
	BacaPOINT(&P0);
	P1 = NextY (P0);
	TulisPOINT(P1);
	printf("\n");

	printf("PlusDelta : ");
	BacaPOINT(&P0);
	scanf("%f", &dx);
	scanf("%f", &dy);
	P1 = PlusDelta (P0, dx, dy);
	TulisPOINT(P1);
	printf("\n");
	
	printf("MirrorOf : ");
	BacaPOINT(&P0);
	P1 = MirrorOf(P0, true);
	TulisPOINT(P1);
	printf("\n");
	P2 = MirrorOf(P0, false);
	TulisPOINT(P2);
	printf("\n");

	printf("Jarak0 : ");
	BacaPOINT(&P0);
	length = Jarak0(P0);
	printf("%.2f", length);
	printf("\n");
	
	printf("Panjang 2 POINT : ");	
	BacaPOINT(&P1);
	BacaPOINT(&P2);
	length = Panjang(P1, P2);
	printf("%.2f\n", length);
	printf("\n");

	printf("Geser : ");
	BacaPOINT(&P0);
	scanf("%f", &dx);
	scanf("%f", &dy);
	Geser(&P0, dx, dy);
	TulisPOINT(P0);
	printf("\n");

	printf("GeserKeSbX : ");
	BacaPOINT(&P0);
	GeserKeSbX(&P0);
	TulisPOINT(P0);
	printf("\n");
	
	printf("GeserKeSbY : ");
	BacaPOINT(&P0);
	GeserKeSbY(&P0);
	TulisPOINT(P0);
	printf("\n");

	printf("Mirror : ");
	BacaPOINT(&P0);
	Mirror(&P0, true);
	TulisPOINT(P0);
	printf("\n");
	Mirror(&P0, false);
	TulisPOINT(P0);
	printf("\n");

	printf("Putar : ");
	BacaPOINT(&P0);
	scanf("%f", &sudut);
	Putar (&P0, sudut);
	TulisPOINT(P0);
	printf("\n");

	return 0;
}
