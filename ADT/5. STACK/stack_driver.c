/**
Filename: stack_driver.c (driver of stack.h)
Description: ADT Stack dengan Tipe Element POINT
**/

#include "boolean.h"
#include "stack.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	int i;
	POINT P;
	
	/* MakeMATRIKS */
	printf("CreateEmptyStack() : \n");
	printf("Variabel eksternal MoveStack terbentuk kosong\n");
	CreateEmptyStack();
	printf("Top = %d\n", Top(MoveStack));
	printf("\n");
	
	printf("IsEmptyStack() : ");
	if(IsEmptyStack()){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("IsFullStack() : ");
	if(IsFullStack()){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	printf("\n");
	
	printf("Push Stack 10 kali sampai penuh :\n");
	for (i = 1; i<= 10; i++){
		printf("POINT : ");
		BacaPOINT(&P);
		Push(P);
	}
	printf("\n");
	
	printf("IsFullStack() : ");
	if(IsFullStack()){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	
	printf("Pop Stack 10 kali sampai kosong :\n");
	for (i = 1; i<= 10; i++){
		Pop(&P);
		printf("POINT : ");
		TulisPOINT(P);
		printf("\n");
	}
	printf("\n");
	
	printf("IsEmptyStack() : ");
	if(IsEmptyStack()){
		printf("true\n");
	}
	else{
		printf("false\n");
	}
	return 0;	
}
