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
#include <stdio.h>
#include "player.h"


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

boolean IsPlotInMap(Map M, POINT P);
/* Mengembalikan True jika koordinat P ada di Map */

/* Konstruktor Plot */
void SetPlot(POINT P, char PlotType, int PlayerNo);
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

POINT CastleCoordinate(int No);
/* Mengembalikan koordinat castle pemain dengan PlayerNo No */

void MakePlayerPlot();
/* I.S Peta(M) terdefinisi dengan semua petak berjenis normal (N) */
/* F.S Terbentuk Map dengan Petak Castle dan Tower untuk setiap player tanpa King */
/* Village telah terbentuk */

void CreateVillage();
/* I.S Map terdefinisi dengan semua jenis petak Normal kecuali petak Tower dan Castle milik pemain */
/* F.S Terbentuk village secara random dengan jumlah 1 per 10 petak normal dengan tidak mempunyai kepemilikan */

void InitMap(int NB, int NK);
/* I.S. Map M sembarang */
/* F.S. Terbentuk Map yang telah terinisiasi semua petaknya */
/* Terinisiasi Tower dan Castle setiap pemain tanpa King */
/* Terbentuk Village secara random */

void PrintPlotType(POINT P);
/* Map M terdefinisi */
/* Mencetak jenis plot/petak pada koordinat P di Map M */
/* Tercetak :
 * "Castle" untuk type 'C'
 * "Tower" untuk type 'T'
 * "Village" untuk type 'V'
 * "Normal plot" untuk type 'N' */

/* Pemilihan petak pada Map */
Unit* ChooseAdjacentUnit(Unit U, int choice);
/* Mengembalikan pointer unit yang adjacent dari unit U, mengembalikan Nil jika tidak ada */
/* Mengembalikakn unit adjacent berdasarkan pilihan choice
 * untuk choice =
 * 1 : Unit di kiri
 * 2 : Unit di atas
 * 3 : Unit di kanan
 * 4 : Unit di bawah */
 
/* Combat Unit */
boolean MissChance(Unit U1, Unit U2, boolean Attacking);
/* Mengembalikan true jika kalkulasi misschance hasilnya true (Serangan unit U1 terhadap U2 miss) */
/* Attacking bernilai true jika Unit U1 memulai combat (bukan retaliate) */
/* Default MissChance adalah 10% */
/* Unit yang retaliate memiliki miss change lebih tinggi (20%) (Mendorong player untuk lebih aktif dan inisiatif) */
/* Unit mendapatkan bonus miss chance berdasarkan petak tempat unit itu berada : 
 * Normal plot : 0%
 * Village : 5%
 * Castle : 10%
 * Tower : 20% */


void AttackUnit(Unit *U1, Unit *U2);
/* I.S. U1 dan U2 terdefinisi */
/* F.S. Melaksanakan serangan dari U1 ke U2 sesuai definisi "serangan" di spesifikasi tugas */
/* Unit yang diserang hanya dapat retaliate jika serangan penyerang tidak miss */
#endif
