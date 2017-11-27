/**
Filename: queue_driver.c (driver of queue.h)
Description: ADT Queue dengan Tipe Element Player
**/

#include "boolean.h"
#include "queue.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	Queue Q;
	Player P;
	
	/* ALGORITMA */
	printf("CreateEmptyQueue(&Q, 10) : \n");
	CreateEmptyQueue(&Q, 10);
	printf("IsEmptyQueue (Q) : ");
	if(IsEmptyQueue (Q)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("NBElmtQueue(Q) : %d\n", NBElmtQueue(Q));
	printf("\n");
	
	printf("AddQueue player 1 dan player 2 : \n");
	AddQueue(&Q, CreatePlayer(1));
	AddQueue(&Q, CreatePlayer(2));
	printf("IsEmptyQueue (Q) : ");
	if(IsEmptyQueue (Q)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("NBElmtQueue(Q) : %d\n", NBElmtQueue(Q));
	printf("\n");
	
	
	printf("DelQueue Sekali : \n");
	DelQueue(&Q, &P);
	printf("IsEmptyQueue (Q) : ");
	if(IsEmptyQueue (Q)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("NBElmtQueue(Q) : %d\n", NBElmtQueue(Q));
	printf("PlayerNo dari Hasil Del : %d\n", PlayerNo(P));
	printf("\n");
	
	printf("DelQueue Sekali Lagi (Queue Kosong Setelah Del) : \n");
	DelQueue(&Q, &P);
	printf("IsEmptyQueue (Q) : ");
	if(IsEmptyQueue (Q)){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("NBElmtQueue(Q) : %d\n", NBElmtQueue(Q));
	printf("PlayerNo dari Hasil Del : %d\n", PlayerNo(P));
	printf("\n");	
	
	return 0;	
}
