#include "boolean.h"
#include "matriks.h"
#include "map.h"
#include <stdio.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
{
	NBrsEff(*M) = NB;
	NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
{
	return (i >= BrsMin-1 && i <= BrsMax-1 && j >= KolMin-1 && j <= KolMax-1);
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
{
	return BrsMin-1;
}

indeks GetFirstIdxKol (MATRIKS M)
{
	return KolMin-1;
}

indeks GetLastIdxBrs (MATRIKS M)
{
	return BrsMin + NBrsEff(M) -  1;
}

indeks GetLastIdxKol (MATRIKS M)
{
	return KolMin + NKolEff(M) -  1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
{
	return (i >= BrsMin-1 && i <= NBrsEff(M)-1 && j >= KolMin-1 && j <= NKolEff(M)-1);
}

ElType GetElmtDiagonal (MATRIKS M, indeks i)
{
	return Elmt(M, i, i);
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
{
	return (NBrsEff(M)*NKolEff(M));
}
