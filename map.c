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
	MakeMATRIKS(Y, X, &Peta(M));
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

POINT CastleCoordinate(int No)
{
	/* KAMUS LOKAL */
	POINT P;
	
	/* ALGORITMA */
	if(No == 1){
		P = MakePOINT(GetFirstIdxKol(Peta(M)) + 1, GetLastIdxBrs(Peta(M)) - 1);
	}
	else{
		P = MakePOINT(GetLastIdxKol(Peta(M)) - 1, GetFirstIdxBrs(Peta(M)) + 1);
	}
	
	return P;
}
/* Mengembalikan koordinat castle pemain dengan PlayerNo No */

void MakePlayerPlot()
{
	/* KAMUS LOKAL */
	POINT P;
	
	/* ALGORITMA */
	/* Inisiasi untuk Player 1 */
	P = CastleCoordinate(1);
	SetPlot(P, 'T', 1);
	P = PlusDelta(P, -1, 0);
	SetPlot(P, 'C', 1);
	P = PlusDelta(P, 1, 1);
	SetPlot(P, 'C', 1);
	P = PlusDelta(P, 1, -1);
	SetPlot(P, 'C', 1);
	P = PlusDelta(P, -1, -1);
	SetPlot(P, 'C', 1);
	
	/* Inisiasi untuk Player 2 */
	P = CastleCoordinate(2);
	SetPlot(P, 'T', 2);
	P = PlusDelta(P, -1, 0);
	SetPlot(P, 'C', 2);
	P = PlusDelta(P, 1, 1);
	SetPlot(P, 'C', 2);
	P = PlusDelta(P, 1, -1);
	SetPlot(P, 'C', 2);
	P = PlusDelta(P, -1, -1);
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

/* Pemilihan petak pada Map */
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
			PAd = PlusDelta(P, -1, 0); //Kiri
		}
		if (choice == 2){
			PAd = PlusDelta(P, 0, 1); //Atas
		}
		if (choice == 3){
			PAd = PlusDelta(P, 1, 0); //Kanan
		}
		if (choice == 4){
			PAd = PlusDelta(P, 0, -1); //Bawah
		}
		
		return (PlotUnit(Petak(M, PAd)));
	}
	else{
		return Nil;
	}
}

/* Combat Unit berdasarkan Petak */
boolean MissChance(Unit U1, Unit U2, boolean Attacking)
{
	/* KAMUS LOKAL */
	int Chance;
	int Random;
	
	/* ALGORITMA */
	Chance = 10;
	if(StrSama(TypeName(U1), "Archer")){
		Chance += 5;
	}
	if(StrSama(TypeName(U1), "King")){
		Chance -= 10;
	}
	if(!Attacking){
		Chance += 10;
	}
	if(PlotType(Petak(M, Position(U2))) == 'V'){
		Chance += 5;
	}
	if(PlotType(Petak(M, Position(U2))) == 'C'){
		Chance += 10;
	}
	if(PlotType(Petak(M, Position(U2))) == 'T'){
		Chance += 15;
	}
	
	Random = rand() % 100;
	
	return (Random < Chance);
}
/* Mengembalikan true jika kalkulasi misschance hasilnya true (Serangan unit U1 terhadap U2 miss) */
/* Attacking bernilai true jika Unit U1 memulai combat (bukan retaliate) */
/* Nilai misschance tiap unit berbeda */
/* Default MissChance adalah 10% */
/* Untuk unit tipe :
 * Archer : 15%
 * King : 0% */
/* Unit yang retaliate memiliki miss change lebih tinggi (20%) (Mendorong player untuk lebih aktif dan inisiatif) */
/* Unit mendapatkan bonus miss chance berdasarkan petak tempat unit itu berada : 
 * Normal plot : 0%
 * Village : 5%
 * Castle : 10%
 * Tower : 15% */

 
void AttackUnit(Unit *U1, Unit *U2) {
	if(!MissChance(*U1, *U2, true)){
		Health(*U2) = Health(*U2) - Atk(*U1);
		if (Health(*U2) > 0) {
			if (CanRetaliate(*U1, *U2)) {
				if(!MissChance(*U2, *U1, false)){
					Health(*U1) = Health(*U1) - Atk(*U2);
				}
			} 
		}
	}
}
/* I.S. U1 dan U2 terdefinisi, U1 memenuhi syarat untuk melakukan serangan ke U2 */
/* F.S. Melaksanakan serangan dari U1 ke U2 sesuai definisi "serangan" di spesifikasi tugas */


