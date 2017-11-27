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
	}
	InfoTail(*Q) = X;
}

void DelQueue (Queue * Q, Queueinfotype * X)
{
	int i;
	
	*X = InfoHead(*Q);
	if (NBElmtQueue(*Q) == 1){
		Head(*Q) = NilQueue;
		Tail(*Q) = NilQueue;
	}
	else{
		for (i = (Head(*Q))+1; i <= Tail(*Q); i++){
			(*Q).T[i-1] = (*Q).T[i];
		}
		Tail(*Q) -= 1;
	}
}
