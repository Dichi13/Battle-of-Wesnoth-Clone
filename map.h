#ifndef MAP_H
#define MAP_H

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"
#include "point.h"
#include "plot.h"
#include "unit.h"


#define Nil NULL

/* Definisi Tipe Petak Peta */

typedef struct MType{
	MATRIKS MMap;
} Map;

/* Variabel global */
extern Map M;

/* Selektor Map */ 
#define Peta(M) (M).MMap

#define MNBrsEff(M) (M).MMap.NBrsEff
#define MNKolEff(M) (M).MMap.NKolEff
#define Petak(M, P) (M).MMap.Mem[Absis(P)][Ordinat(P)]

/* Primitif Map */

/* Operasi Relasional Map */
boolean IsPlotEmpty(Map M, POINT P);
/* Plot pada koordinat P terdefinisi */
/* Mengembalikan true jika tidak ada unit pada Plot dengan koordinat P */
/* Tidak ada unit : PlotUnit(Petak(M, P)) = Nil */

/* Konstruktor Plot */
void SetPlot(POINT P, char PlotType, int Owner);
/* I.S. Petak pada koordinat (X,Y) sembarang dengan koordinat terdefinisi */
/* F.S. Terdefinisi Petak dengan koordinat (X,Y) dengan jenis petak Plottype dan pemilik Owner */

void SetUnit(POINT P, Unit* U);
/* I.S. Terdefinisi jenis dan owner petak pada koordinat P. PlotUnit Sembarang */
/* F.S. Unit pada petak dengan koordinat P menjadi U */

/* Konstruktor Map */
void MakeEmptyMap(int X, int Y);
/* I.S. Map M sembarang */
/* F.S. Terbuat Map kosong dengan ukuran X*Y, koordinat peta terinisiasi */ 

/* Inisialisasi Map */
void MakeNormalPlot();
/* I.S Peta(M) terdefinisi */
/* F.S Terbentuk Map dengan seluruh petaknya berisi petak Normal (N) */
/* Terbentuk Map dengan semua kepemilikan petak tidak ada yang punya, Owner = Nil */
/* Terbentuk Map dengan semua tidak ada unit pada petak */

void MakePlayerPlot();
/* I.S Peta(M) terdefinisi dengan semua petak berjenis normal (N) */
/* F.S Terbentuk Map dengan Petak Castle dan Tower untuk setiap player tanpa King */

void CreateVillage();
/* I.S Map terdefinisi dengan semua jenis petak Normal kecuali petak Tower dan Castle milik pemain */
/* F.S Terbentuk village secara random dengan jumlah 1 per 10 petak normal dengan tidak mempunyai kepemilikan */

void InitMap(int NB, int NK);
/* I.S. Map M sembarang */
/* F.S. Terbentuk Map yang telah terinisiasi semua petaknya */
/* Terinisiasi Tower dan Castle setiap pemain tanpa King */
/* Terbentuk Village secara random */


#endif
