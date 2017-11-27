/* File : point.c */
/* Deskripsi : Primitif ADT Point */
/* Isi : realisasi/ kode program dari semua prototype Point */
/* yg didefinisikan pada point.h */
/* Untuk sebuah mesin akan mengandung deklarasi variabel */
/* state dari mesin tsb */

#include "point.h"
#include <math.h>
#include <stdio.h>

/* Realisasi kode program */

/* Tanggal: 28 Agustus 2016 */
/* *** Realisasi ABSTRACT DATA TYPE POINT *** */

#include "boolean.h"
        
/* *** REALISASI PROTOTIPE PRIMITIF *** */

/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y)
{
	/* KAMUS */
	POINT P;
	
	/* ALGORITMA */
	Absis(P) = X;
	Ordinat(P) = Y;
	
	return P;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */                                                 
void BacaPOINT (POINT *P) 
{
	/* KAMUS */
	float x, y;
	
	/* ALGORITMA */
	scanf("%f %f", &x, &y);
	*P = MakePOINT(x, y);
}

void TulisPOINT (POINT P)
{
	/* KAMUS */
	
	/* ALGORITMA */
	printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}


/* *** Kelompok operasi relasional terhadap POINT *** */
boolean EQ (POINT P1, POINT P2)
{
	/* KAMUS */
	
	/* ALGORITMA */
	return ((Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2)));
}

boolean NEQ (POINT P1, POINT P2)
{
	/* KAMUS */
	
	/* ALGORITMA */
	return ((Absis(P1) != Absis(P2)) || (Ordinat(P1) != Ordinat(P2)));
}


/* *** Kelompok menentukan di mana P berada *** */
boolean IsOrigin (POINT P)
{
	/* KAMUS */
	
	/* ALGORITMA */
	return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P)
{
	/* KAMUS */
	
	/* ALGORITMA */
	return (Ordinat(P) == 0);
}

boolean IsOnSbY (POINT P)
{
	/* KAMUS */
	
	/* ALGORITMA */
	return (Absis(P) == 0);
}

int Kuadran (POINT P)
{
	/* KAMUS */
	
	/* ALGORITMA */
	if ( (!IsOnSbX(P)) && (!IsOnSbY(P)) )
	{
		if (Absis(P) > 0)
		{
			if (Ordinat(P) > 0)
			{
				return 1;
			}
			else
			{
				return 4;
			}
		}
		else
		{
			if (Ordinat(P) > 0)
			{
				return 2;
			}
			else
			{
				return 3;
			}
		}
	}
	else
	{
		return 0;
	}
}


/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P)
{
	/* KAMUS */
	POINT P0;
	
	/* ALGORITMA */
	P0 = P;
	Absis(P0) = Absis(P0) + 1;
	
	return P0;
}
            
POINT NextY (POINT P)
{
	/* KAMUS */
	POINT P0;
	
	/* ALGORITMA */
	P0 = P;
	Ordinat(P0) = Ordinat(P0) + 1;
	
	return P0;
}

POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
	/* KAMUS */
	POINT P0;
	
	/* ALGORITMA */
	P0 = P;
	Absis(P0) = Absis(P0) + deltaX;
	Ordinat(P0) = Ordinat(P0) + deltaY;
	
	return P0;
}

POINT MirrorOf (POINT P, boolean SbX)
{
	/* KAMUS */
	POINT P0;
	
	/* ALGORITMA */
	P0 = P;
	if (SbX)
	{
		Ordinat(P0) = (-(Ordinat(P0)));
	}
	else
	{
		Absis(P0) = (-(Absis(P0)));
	}
	
	return P0;
}

float Jarak0 (POINT P)
{
	/* KAMUS */
	float jarak, x, y;
	
	/* ALGORITMA */
	x = Absis(P);
	y = Ordinat(P);
	jarak = sqrt( (pow(x,2)) + (pow(y,2)) );
	
	return jarak;
}

float Panjang (POINT P1, POINT P2)
{
	/* KAMUS */
	float jarak, x1, x2, y1, y2, dx, dy;
	
	/* ALGORITMA */
	x1 = Absis(P1);
	x2 = Absis(P2);
	y1 = Ordinat(P1);
	y2 = Ordinat(P2);
	dx = x1 - x2;
	dy = y1 - y2;
	jarak = sqrt( (pow(dx,2)) + (pow(dy,2)) );
	
	return jarak;
}

void Geser (POINT *P, float deltaX, float deltaY)
{
	Absis(*P) = Absis(*P) + deltaX;
	Ordinat(*P) = Ordinat(*P) + deltaY;	
}

void GeserKeSbX (POINT *P)
{
	/* KAMUS */
	
	/* ALGORITMA */
	Ordinat(*P) = 0;	
}

void GeserKeSbY (POINT *P)
{
	/* KAMUS */
	
	/* ALGORITMA */
	Absis(*P) = 0;	
}

void Mirror (POINT *P, boolean SbX)
{
	/* KAMUS */
	
	/* ALGORITMA */
	if (SbX)
	{
		Ordinat(*P) = (-(Ordinat(*P)));
	}
	else
	{
		Absis(*P) = (-(Absis(*P)));
	}
}

void Putar (POINT *P, float Sudut)
{
	/* KAMUS */
	float X, Y, Rad;
	
	/* ALGORITMA */
	X = Absis(*P);
	Y = Ordinat(*P);
	Rad = ((-Sudut)*(M_PI))/180;
	Absis(*P) = (cos(Rad))*(X) - (sin(Rad))*(Y);
	Ordinat(*P) = (sin(Rad))*(X) + (cos(Rad))*(Y);
}

