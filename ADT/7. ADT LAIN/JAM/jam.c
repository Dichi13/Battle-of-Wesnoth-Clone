/* NIM				: 13516033 */
/* Nama				: Abner Adhiwijna */
/* Tanggal			: 31 Agustus 2017 */
/* Topik praktikum	: Pra-Praktikum 02 */

/* File : jam.c */
/* Deskripsi : Primitif ADT Jam */
/* Isi : realisasi/ kode program dari semua prototype Jam */
/* yg didefinisikan pada Jam.h */
/* Untuk sebuah mesin akan mengandung deklarasi variabel */
/* state dari mesin tsb */

#include "jam.h"
#include <math.h>
#include <stdio.h>
#include "boolean.h"

/* Realisasi ADT JAM */


/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
{
	return ((H <= 23) && (H >= 0) && (M <= 59) && (M >= 0) && (S <=59) && (S >= 0));
}

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int HH, int MM, int SS)
{
	/* KAMUS */
	JAM J;
	
	/* ALGORITMA */
	Hour(J) = HH;
	Minute(J) = MM;
	Second(J) = SS;
	
	return J;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
{
	/* KAMUS */
	int H, M, S;
	
	/* ALGORITMA */
	scanf("%d %d %d", &H, &M, &S);
	while ( !(IsJAMValid (H, M, S)) )
	{
		printf("Jam tidak valid\n");
		scanf("%d %d %d\n", &H, &M, &S);
	}
	
	*J = MakeJAM(H, M, S);
	
}


void TulisJAM (JAM J)
{
	printf("%02d:%02d:%02d", Hour(J), Minute(J), Second(J));
}

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */

long JAMToDetik (JAM J)
{
	/* KAMUS */
	long jam, menit, detik;
	
	/* ALGORITMA */
	jam  = Hour(J);
	menit = Minute(J);
	detik = Second(J);
	detik = 3600*jam + 60*menit + detik;
	
	return detik;
}

JAM DetikToJAM (long N)
{
	/* KAMUS */
	JAM J;
	long N1;
	
	/* ALGORITMA */
	N1 = N%86400;
	Hour(J) = N1/3600;
	Minute(J) = (N1%3600)/60;
	Second(J) = (N1%60);
	
	return J;
}

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
{
	return ( (Hour(J1) == Hour(J2)) && (Minute(J1) == Minute(J2)) && (Second(J1) == Second(J2)) );
}

boolean JNEQ (JAM J1, JAM J2)
{
	return ( (Hour(J1) != Hour(J2)) || (Minute(J1) != Minute(J2)) || (Second(J1) != Second(J2)) );
}

boolean JLT (JAM J1, JAM J2)
{
	return 	(JAMToDetik(J1) < JAMToDetik(J2));
}

boolean JGT (JAM J1, JAM J2)
{
	return (JAMToDetik(J1) > JAMToDetik(J2));
}

/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
{
	return DetikToJAM(JAMToDetik(J) + 1);
}

JAM NextNDetik (JAM J, int N)
{
	return DetikToJAM(JAMToDetik(J) + N);
}
	
JAM PrevDetik (JAM J)
{
	if ((JAMToDetik(J) - 1) < 0)
	{
		return DetikToJAM(JAMToDetik(J) - 1 + 86400);
	}
	else
	{
		return DetikToJAM(JAMToDetik(J) - 1);
	}
}

JAM PrevNDetik (JAM J, int N)
{
	/* KAMUS */
	int count;
	
	/* ALGORITMA */
	count = 0;
	while ((JAMToDetik(J) - N + 86400*count) < 0)
	{
		count += 1;
	}
	return DetikToJAM(JAMToDetik(J) - N + 86400*count);
}

/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh)
{
	/* KAMUS */
	long d1, d2, hasil;
	
	/* ALGORITMA */
	d1 = JAMToDetik(JAw);
	d2 = JAMToDetik(JAkh);
	
	hasil = d2 - d1;
	
	if (hasil < 0)
	{
		hasil = hasil + 86400;
	}
	
	return hasil;
}

