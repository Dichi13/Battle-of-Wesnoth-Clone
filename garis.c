//NIM : 13516033
//Nama : Abner Adhiwijna
//Tanggal : 31 Agustus 2017
//Topik praktikum : Praktikum 02
//Deskripsi : Realisasi ADT Garis

/* File: garis.h */
/* Tanggal: 31 Agustus 2017 */
/* Definisi ADT GARIS, menggunakan ADT point */

/* *** ADT LAIN YANG DIPAKAI *** */
#include "garis.h"
#include "boolean.h"
#include "point.h"
#include <math.h>
#include <stdio.h>

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */ 
/* ***************************************************************** */
/* *** Konstruktor membentuk GARIS *** */
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
{
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

/* ***************************************************************** */
/* KELOMPOK INTERAKSI DENGAN I/O DEVICE, BACA/TULIS                  */
/* ***************************************************************** */
void BacaGARIS (GARIS * L)
{
	/* KAMUS */
	POINT P1, P2;
	
	/* ALGORITMA */
	BacaPOINT(&P1);
	BacaPOINT(&P2);
	while (EQ(P1, P2))
	{
		printf("Garis tidak valid\n");
		BacaPOINT(&P1);
		BacaPOINT(&P2);
	}
	PAwal(*L) = P1;
	PAkhir(*L) = P2;
}

void TulisGARIS (GARIS L)
{
	printf("(");
	TulisPOINT(PAwal(L));
	printf(",");
	TulisPOINT(PAkhir(L));
	printf(")");
}

/* *** Kelompok operasi garis *** */
float PanjangGARIS (GARIS L)
{
	/* KAMUS */
	float length;
	POINT PAw, PAkh;
	
	/* ALGORITMA */
	PAw = PAwal(L);
	PAkh = PAkhir(L);
	length = Panjang(PAw, PAkh);
	
	return length;
}

float Gradien (GARIS L)
{
	/* KAMUS */
	float dx, dy, grad;
	POINT PAw, PAkh;
	
	/* ALGORITMA */
	PAw = PAwal(L);
	PAkh = PAkhir(L);
	dx = Absis(PAkh) - Absis(PAw);
	dy = Ordinat(PAkh) - Ordinat(PAw);
	grad =  (dy)/(dx);
	
	return grad;
}

void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
	Geser(&PAwal(*L), deltaX, deltaY);
	Geser(&PAkhir(*L), deltaX, deltaY);
}

/* *** Kelompok predikat *** */
boolean IsTegakLurus (GARIS L1, GARIS L2)
{
	return ( (Gradien(L1)*Gradien(L2)) == -1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
{
	return ( (Gradien(L1)) == (Gradien(L2)) );
}
/* Menghasilkan true jika L "sejajar" terhadap L1 */
/* Dua garis saling sejajar jika memiliki gradien yang sama */

