/* NIM				: 13516033 */
/* Nama				: Abner Adhiwijna */
/* Tanggal			: 26 Oktober 2017 */
/* Topik praktikum	: Praktikum 08 */

/* File : listlinier.c */
/* Realisasi ADT list berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "boolean.h"
#include "listlinier.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
	return First(L) == Nil;
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
	First(*L) = Nil;
} 
/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
	/* KAMUS LOKAL */
	address P;
	
	/* ALGORITMA */
	P = (ElmtList *) malloc(sizeof *P);
	if (P != Nil){
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi (address P)
{
	free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
{
	/* KAMUS LOKAL */
	address P;
	boolean found;
	
	/* ALGORITMA */
	P = First(L);
	found = false;
	if (P != Nil){
		while ((P != Nil) && !found){
			if (Info(P) == X){
				found = true;
			}
			else{
				P = Next(P);
			}
		}
	}
	
	if(!found){
		P = Nil;
	}
	
	return P;
}

boolean FSearch (List L, address P)
{
	/* KAMUS LOKAL */
	address PSearch;
	boolean found;
	
	/* ALGORITMA */
	PSearch = First(L);
	found = false;
	if (PSearch != Nil){
		while ((PSearch != Nil) && !found){
			if (PSearch == P){
				found = true;
			}
			else{
				PSearch = Next(PSearch);
			}
		}
	}
	
	return found;
}

address SearchPrec (List L, infotype X)
{
	/* KAMUS LOKAL */
	address P, Prec;
	boolean found;
	
	/* ALGORITMA */
	Prec = Nil;
	found = false;
	if (!IsEmpty(L)){
		P = First(L);
		found = (Info(P) == X);
		while ((Next(P) != Nil) && !found){
			Prec = P;
			P = Next(P);
			found = (Info(P) == X);
		}
	}
	if(!found){
		Prec = Nil;
	}
	
	return Prec;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{
	/* KAMUS LOKAL */
	address P;
	
	/* ALGORITMA */
	P = Alokasi(X);
	if (P != Nil){
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (List *L, infotype X)
{
	/* KAMUS LOKAL */
	address P;
	address PL;
	
	/* ALGORITMA */
	P = Alokasi(X);
	PL = First(*L);
	if (P != Nil){
		if (PL == Nil){
			First(*L) = P;
		}
		else{
			while (Next(PL) != Nil){
				PL = Next(PL);
			}
			Next(PL) = P;
		}
	}
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
{
	/* KAMUS LOKAL */
	address P;
	
	/* ALGORITMA */
	P = First(*L);
	*X = Info(P);
	First(*L) = Next(P);
	Dealokasi(&P);
}

void DelVLast (List *L, infotype *X)
{
	/* KAMUS LOKAL */
	address P;
	address PDel;
	
	/* ALGORITMA */
	P = First(*L);
	PDel = P;
	if (Next(PDel) == Nil){
		First(*L) = Nil;
	}
	else{
		while (Next(PDel) != Nil){
			P = PDel;
			PDel = Next(PDel);
		}
		Next(P) = Nil;
	}
	*X = Info(PDel);
	Dealokasi(&PDel);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec)
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (List *L, address P)
{
	/* KAMUS LOKAL */
	address Prec;
	
	/* ALGORITMA */
	Prec = First(*L);
	Next(P) = Nil;
	if(Prec == Nil){
		First(*L) = P;
	}
	else{
		while (Next(Prec) != Nil){
			Prec = Next(Prec);
		}
		Next(Prec) = P;
	}
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
	*P = First(*L);
	First(*L) = Next(*P);
}

void DelP (List *L, infotype X)
{
	/* KAMUS LOKAL */
	address Prec;
	address PDel;
	boolean found;
	
	/* ALGORITMA */
	Prec = First(*L);
	
	if (Prec != Nil){
		found = false;
		PDel = Nil;
		if (Info(Prec) == X){
			PDel = Prec;
			First(*L) = Next(Prec);
			found = true;
		}
		while ((Next(Prec) != Nil) && !found){
			if (Info(Next(Prec)) == X){
				PDel = Next(Prec);
				found = true;
				Next(Prec) = Next(PDel);
				Next(PDel) = Nil;
			}
			else{
				Prec = Next(Prec);
			}
		}
		
		if (PDel != Nil){
			Dealokasi(&PDel);
		}
	}			
}

void DelLast (List *L, address *P)
{
	/* KAMUS LOKAL */
	address Prec;
	
	/* ALGORITMA */
	*P = First(*L);
	if (Next(*P) == Nil){
		First(*L) = Nil;
	}
	else {
		while (Next(*P) != Nil){
			Prec = *P;
			*P = Next(*P);
		}
		Next(Prec) = Nil;
	}
}

void DelAfter (List *L, address *Pdel, address Prec)
{
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
{
	/* KAMUS LOKAL */
	address P;
	
	/* ALGORITMA */
	printf("[");
	P = First(L);
	if (P != Nil){
		printf("%d", Info(P));
		while (Next(P) != Nil){
			P = Next(P);
			printf(",%d", Info(P));
		}
	}
	printf("]");
}

int NbElmt (List L)
{
	/* KAMUS LOKAL */
	address P;
	int count;
	
	/* ALGORITMA */
	count = 0;
	P = First(L);
	if (P != Nil) {
		count += 1;
		while(Next(P) != Nil){
			count += 1;
			P = Next(P);
		}
	}
	
	return count;
}

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
{
	/* KAMUS LOKAL */
	infotype maks;
	address P;
	
	/* ALGORITMA */
	P = First(L);
	maks = Info(P);
	while (Next(P) != Nil){
		P = Next(P);
		if (Info(P) > maks){
			maks = Info(P);
		}
	}
	
	return maks;
}

address AdrMax (List L)
{
	/* KAMUS LOKAL */
	infotype maks;
	address P, PMaks;
	
	/* ALGORITMA */
	P = First(L);
	PMaks = P;
	maks = Info(P);
	while (Next(P) != Nil){
		P = Next(P);
		if (Info(P) > maks){
			maks = Info(P);
			PMaks = P;
		}
	}
	
	return PMaks;
}

infotype Min (List L)
{
	/* KAMUS LOKAL */
	infotype min;
	address P;
	
	/* ALGORITMA */
	P = First(L);
	min = Info(P);
	while (Next(P) != Nil){
		P = Next(P);
		if (Info(P) < min){
			min = Info(P);
		}
	}
	
	return min;
}

address AdrMin (List L)
{
	/* KAMUS LOKAL */
	infotype min;
	address P, PMin;
	
	/* ALGORITMA */
	P = First(L);
	PMin = P;
	min = Info(P);
	while (Next(P) != Nil){
		P = Next(P);
		if (Info(P) < min){
			min = Info(P);
			PMin = P;
		}
	}
	
	return PMin;
}

float Average (List L)
{
	/* KAMUS LOKAL */
	float avg, sum, count;
	address P;
	
	/* ALGORITMA */
	sum = 0;
	count = 0;
	avg = 0;
	if(!IsEmpty(L)){
		P = First(L);
		sum += Info(P);
			count += 1;
		while (Next(P) != Nil){
			P = Next(P);
			sum += Info(P);
			count += 1;
		}
		avg = sum/count;
	}
		
	return avg;
}
	
/* Mengirimkan nilai rata-rata info(P) */
/****************** PROSES TERHADAP LIST ******************/
void DelAll (List *L)
{
	/* KAMUS LOKAL */
	address P, PDel;
	
	/* ALGORITMA */
	if(!IsEmpty(*L)){
		P = First(*L);
		while (Next(P) != Nil){
			PDel = P;
			P = Next(P);
			Dealokasi(&PDel);
		}
		Dealokasi(&P);
		CreateEmpty(L);
	}
	
}

void InversList (List *L)
{
	/* KAMUS LOKAL */
	address Prec, P, PSucc;
	
	/* ALGORITMA */
	if(!IsEmpty(*L)){
		if(!(NbElmt(*L) == 1)){
			if(NbElmt(*L) == 2){
				P = First(*L);
				PSucc = Next(P);
				Next(PSucc) = P;
				Next(P) = Nil;
				First(*L) = PSucc;
			}
			else {
				Prec = First(*L);
				P = Next(Prec);
				PSucc = Next(P);
				Next(Prec) = Nil;
				while (Next(PSucc) != Nil){
					Next(P) = Prec;
					Prec = P;
					P = PSucc;
					PSucc = Next(PSucc);
				}
				Next(P) = Prec;
				Next(PSucc) = P;
				First(*L) = PSucc;
			}
		}
	}
}

List FInversList (List L)
{
	/* KAMUS LOKAL */
	address P, PNew;
	boolean gagal;
	List LNew;
	
	/* ALGORITMA */
	gagal = false;
	CreateEmpty(&LNew);
	if(!IsEmpty(L)){
		P = First(L);
		PNew = Alokasi(Info(P));
		gagal = (PNew == Nil);
		if (!gagal){
			InsertFirst(&LNew, PNew);
			if (Next(P) != Nil){
				while ((Next(P) != Nil) && !gagal){
					P = Next(P);
					PNew = Alokasi(Info(P));
					gagal = (PNew == Nil);
					if (gagal){
						DelAll(&LNew);
					}
					else{
						InsertFirst(&LNew, PNew);
					}
				}
			}
		}
	}
	
	return LNew;
}

void CopyList (List *L1, List *L2)
{
	/* ALGORITMA */
	CreateEmpty(L2);
	First(*L2) = First(*L1);
}

List FCopyList (List L)
{
	/* KAMUS LOKAL */
	address P1, P2, PNew;
	boolean gagal;
	List LNew;
	
	/* ALGORITMA */
	gagal = false;
	CreateEmpty(&LNew);
	if(!IsEmpty(L)){
		P1 = First(L);
		PNew = Alokasi(Info(P1));
		gagal = (PNew == Nil);
		if (!gagal){
			InsertFirst(&LNew, PNew);
			P2 = PNew;
			if (Next(P1) != Nil){
				while ((Next(P1) != Nil) && !gagal){
					P1 = Next(P1);
					PNew = Alokasi(Info(P1));
					gagal = (PNew == Nil);
					if (gagal){
						DelAll(&LNew);
					}
					else{
						InsertAfter(&LNew, PNew, P2);
						P2 = PNew;
					}
				}
			}
		}
	}
	
	return LNew;
}

void CpAlokList (List Lin, List *Lout)
{
	/* KAMUS LOKAL */
	address P1, P2, PNew;
	boolean gagal;
	
	/* ALGORITMA */
	gagal = false;
	CreateEmpty(Lout);
	if(!IsEmpty(Lin)){
		P1 = First(Lin);
		PNew = Alokasi(Info(P1));
		gagal = (PNew == Nil);
		if (!gagal){
			InsertFirst(Lout, PNew);
			P2 = PNew;
			if (Next(P1) != Nil){
				while ((Next(P1) != Nil) && !gagal){
					P1 = Next(P1);
					PNew = Alokasi(Info(P1));
					gagal = (PNew == Nil);
					if (gagal){
						DelAll(Lout);
					}
					else{
						InsertAfter(Lout, PNew, P2);
						P2 = PNew;
					}
				}
			}
		}
	}
}

void Konkat (List L1, List L2, List * L3)
{
	/* KAMUS LOKAL */
	List LN1, LN2;
	boolean gagal;
	
	/* ALGORITMA */
	CreateEmpty(L3);
	gagal = false;
	if(!IsEmpty(L1)){
		CpAlokList(L1, &LN1);
		gagal = (First(LN1) == Nil);
	}
	if((!IsEmpty(L2)) && !gagal){
		CpAlokList(L2, &LN2);
		gagal = (First(LN2) == Nil);
		if (gagal){
			DelAll(&LN1);
		}
	}
	if(!gagal){
		Konkat1(&LN1, &LN2, L3);
	}
}

void Konkat1 (List *L1, List *L2, List *L3)
{
	/* KAMUS LOKAL */
	address P;
	
	/* ALGORITMA */
	P = First(*L1);
	if (P != Nil){
		First(*L3) = P;
		while(Next(P) != Nil){
			P = Next(P);
		}
		Next(P) = First(*L2);
	}
	else{
		First(*L3) = First(*L2);
	}
	First(*L1) = Nil;
	First(*L2) = Nil;
}

void PecahList (List *L1, List *L2, List L)
{
	/* KAMUS LOKAL */
	List LNew;
	address Prec, P;
	int count, batas;
	
	/* ALGORITMA */
	CpAlokList(L, &LNew);
	batas = (NbElmt(L)/2);
	count = 0;
	P = First(LNew);
	Prec = Nil;
	while (count < batas){
		count += 1;
		Prec = P;
		P = Next(P);
	}
	First(*L1) = First(LNew);
	First(*L2) = P;
	if (Prec != Nil){
		Next(Prec) = Nil;
	}
}
