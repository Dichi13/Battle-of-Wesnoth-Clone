/* NIM				: 13516033 */
/* Nama				: Abner Adhiwijna */
/* Tanggal			: 06 Oktober 2017 */
/* Topik praktikum	: Pra-Praktikum 06 */

/* File : queue.c */
/* Realisasi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */

#include "boolean.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* Prototype ********* */
boolean IsEmptyQueue (Queue Q)
{
	return (Head(Q) == NilQueue && Tail(Q) == NilQueue);
}

boolean IsFullQueue (Queue Q)
{
	return ((Tail(Q)-Head(Q) == -1) || (Head(Q) == 1 && Tail(Q) == MaxEl(Q)));
}

int NBElmtQueue (Queue Q)
{
	/* KAMUS */
	int jumlah;
	/* ALGORITMA */
	if (Head(Q) == NilQueue && Tail(Q) == NilQueue){
		jumlah = 0;
	}
	else if (Head(Q) <= (Tail(Q))){
		jumlah = Tail(Q) - Head(Q) + 1;
	}
	else {
		jumlah = MaxEl(Q) - Head(Q) + 1 + Tail(Q);
	}
	return jumlah;
}

/* *** Kreator *** */
void CreateEmptyQueue (Queue * Q, int Max)
{
	(*Q).T = (Queueinfotype *)malloc(sizeof(Max + 1));

	if ((*Q).T == 0){
		MaxEl(*Q) = 0;
	}
	else{
		MaxEl(*Q) = Max;
	}
	Head(*Q) = NilQueue;
	Tail(*Q) = NilQueue;
}

/* *** Destruktor *** */
void DeAlokasiQueue(Queue * Q)
{
	MaxEl(*Q) = 0;
	free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void AddQueue (Queue * Q, Queueinfotype X)
{
	if (IsEmptyQueue(*Q)){
		Head(*Q) = 1;
		Tail(*Q) = 1;
	}
	else{
		Tail(*Q) += 1;
		if (Tail(*Q) > MaxEl(*Q)){
			Tail(*Q) = Tail(*Q) % MaxEl(*Q);
		}
	}
	InfoTail(*Q) = X;
}

void DelQueue (Queue * Q, Queueinfotype * X)
{
	*X = InfoHead(*Q);
	if (NBElmtQueue(*Q) == 1){
		Head(*Q) = NilQueue;
		Tail(*Q) = NilQueue;
	}
	else{
		Head(*Q) += 1;
		if (Head(*Q) > MaxEl(*Q)){
			Head(*Q) = Head(*Q) % MaxEl(*Q);
		}
	}
}
