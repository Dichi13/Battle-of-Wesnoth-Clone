#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "matriks.h"
#include "boolean.h"
#include "point.h"
#include "plot.h"
#include "unit.h"
#include "map.h"
#include <stdio.h>

/* Variabel global */
Map M;

/* Primitif Map */

/* Operasi Relasional Map */
boolean IsPlotEmpty(Map M, POINT P)
{
	return PlotUnit(Petak(M, P)) == Nil;
}
/* Plot pada koordinat P terdefinisi */
/* Mengembalikan true jika tidak ada unit pada Plot dengan koordinat P */
/* Tidak ada unit : PlotUnit(Petak(M, P)) = Nil */

boolean IsPlotInMap(Map M, POINT P)
{
	return (IsIdxEff(Peta(M), Absis(P), Ordinat(P)));
}
/* Mengembalikan True jika koordinat P ada di Map */

/* Konstruktor Plot */
void SetPlot(POINT P, char PlotType, int PlayerNo)
{
	PlotType(Petak(M, P)) = PlotType;
	Owner(Petak(M, P)) = PlayerNo;
}
/* I.S. Petak P sembarang dengan koordinat terdefinisi */
/* F.S. Terdefinisi Petak P dengan jenis petak Plottype dan pemilik Owner */

void SetUnit(POINT P, Unit* U)
{
	PlotUnit(Petak(M, P)) = U;
}
/* I.S. Terdefinisi jenis dan owner petak pada koordinat P. PlotUnit Sembarang */
/* F.S. Unit pada petak dengan koordinat P menjadi U */

void MakeEmptyMap(int X, int Y)
{
	/* KAMUS LOKAL */
	int i, j;
	POINT P;
	
	/* ALGORITMA */
	MakeMATRIKS(X, Y, &Peta(M));
	for(i = GetFirstIdxBrs(Peta(M)); i <= GetLastIdxBrs(Peta(M)); i++){
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(i, j);
			Coordinate(Petak(M, P)) = MakePOINT(i, j);
		}
	}
}
/* I.S. Map M sembarang */
/* F.S. Terbuat Map kosong dengan ukuran X*Y, koordinat peta terinisiasi */ 

void MakeNormalPlot()
{
	/* KAMUS LOKAL */
	int i, j;
	POINT P;
	
	/* ALGORITMA */
	for(i = GetFirstIdxBrs(Peta(M)); i <= GetLastIdxBrs(Peta(M)); i++){
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(i, j);
			SetPlot(P, 'N', 0);
			PlotUnit(Petak(M, P)) = Nil;
		}
	}
}
/* Peta(M) terdefinisi */
/* Terbentuk Map dengan seluruh petaknya berisi petak Normal (N) */
/* Terbentuk Map dengan semua kepemilikan petak tidak ada yang punya, Owner = Nil */
/* Terbentuk Map dengan semua tidak ada unit pada petak */

void MakePlayerPlot()
{
	/* KAMUS LOKAL */
	POINT P;
	
	/* ALGORITMA */
	/* Inisiasi untuk Player 1 */
	P = MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M))+1);
	SetPlot(P, 'T', 1);
	P = MakePOINT(GetLastIdxBrs(Peta(M)), GetFirstIdxKol(Peta(M))+1);
	SetPlot(P, 'C', 1);
	P = MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M)));
	SetPlot(P, 'C', 1);
	P = MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M))+2);
	SetPlot(P, 'C', 1);
	P = MakePOINT(GetLastIdxBrs(Peta(M))-2, GetFirstIdxKol(Peta(M))+1);
	SetPlot(P, 'C', 1);
	
	/* Inisiasi untuk Player 2 */
	P = MakePOINT(GetFirstIdxBrs(Peta(M))+1, GetLastIdxKol(Peta(M))-1);
	SetPlot(P, 'T', 2);
	P = MakePOINT(GetFirstIdxBrs(Peta(M)), GetLastIdxKol(Peta(M))-1);
	SetPlot(P, 'C', 2);
	P = MakePOINT(GetFirstIdxBrs(Peta(M))+1, GetLastIdxKol(Peta(M)));
	SetPlot(P, 'C', 2);
	P = MakePOINT(GetFirstIdxBrs(Peta(M))+1, GetLastIdxKol(Peta(M))-2);
	SetPlot(P, 'C', 2);
	P = MakePOINT(GetFirstIdxBrs(Peta(M))+2, GetLastIdxKol(Peta(M))-1);
	SetPlot(P, 'C', 2);
}
/* I.S Peta(M) terdefinisi dengan semua petak berjenis normal (N) */
/* F.S Terbentuk Map dengan Petak Castle dan Tower untuk setiap player dengan King pada petak Tower */

void CreateVillage()
{
	/* KAMUS LOKAL */
	int NVillage;
	int i;
	POINT P;
	time_t t;
	
	/* ALGORITMA */
	NVillage = floor(NBElmt(Peta(M))/10);
	
	/* Inisialisasi random number generator */
	srand((unsigned) time(&t));\
	
	for(i = 1; i <= NVillage; i++){
		do{
			Absis(P) = rand() % (MNBrsEff(M)-1);
			Ordinat(P) = rand() % (MNKolEff(M)-1);
		} while (PlotType(Petak(M, P)) != 'N');
		SetPlot(P, 'V', 0);
	}
		
}
/* I.S Map terdefinisi dengan semua jenis petak Normal kecuali petak Tower dan Castle milik pemain, sudah ada King */
/* F.S Terbentuk village secara random dengan jumlah 1 per 10 petak normal dengan tidak mempunyai kepemilikan */

void InitMap(int X, int Y)
{
	MakeEmptyMap(X, Y);
	MakeNormalPlot();
	MakePlayerPlot();
	CreateVillage();
}
/* I.S. Map M sembarang */
/* F.S. Terbentuk Map yang telah terinisiasi semua petaknya */
/* Terinisiasi Tower dan Castle setiap pemain dengan King */
/* Terbentuk Village secara random */

void PrintPlotType(POINT P)
{
	if(PlotType(Petak(M, P)) == 'C'){
		printf("Castle");
	}
	if(PlotType(Petak(M, P)) == 'T'){
		printf("Tower");
	}
	if(PlotType(Petak(M, P)) == 'V'){
		printf("Village");
	}
	if(PlotType(Petak(M, P)) == 'N'){
		printf("Normal plot");
	}
	
	
}
/* Map M terdefinisi */
/* Mencetak jenis plot/petak pada koordinat P di Map M */
/* Tercetak :
 * "Castle" untuk type 'C'
 * "Tower" untuk type 'T'
 * "Village" untuk type 'V'
 * "Normal plot" untuk type 'N' */

Unit* ChooseAdjacentUnit(Unit U, int choice)
/* Mengembalikan pointer unit yang adjacent dari unit U, mengembalikan Nil jika tidak ada */
/* Mengembalikakn unit adjacent berdasarkan pilihan choice
 * untuk choice =
 * 1 : Unit di kiri
 * 2 : Unit di atas
 * 3 : Unit di kanan
 * 4 : Unit di bawah */
{
	/* KAMUS LOKAL */
	POINT P, PAd;
	
	/* ALGORITMA */
	P = Position(U);
	
	if ((choice >= 1) && (choice <= 4)){
		if (choice == 1){
			PAd = MakePOINT(Absis(P)-1,Ordinat(P)); //Kiri
		}
		if (choice == 2){
			PAd = MakePOINT(Absis(P),Ordinat(P)+1); //Atas
		}
		if (choice == 3){
			PAd = MakePOINT(Absis(P)+1,Ordinat(P)); //Kanan
		}
		if (choice == 4){
			PAd = MakePOINT(Absis(P),Ordinat(P)-1); //Bawah
		}
		
		return (PlotUnit(Petak(M, PAd)));
	}
	else{
		return Nil;
	}
}
