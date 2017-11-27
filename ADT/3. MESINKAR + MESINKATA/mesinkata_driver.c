/**
Filename: mesinkata_driver.c (driver of matriks.h)
Description: ADT Mesin Kata
**/

#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>

int main()
{
	/* KAMUS */
	boolean Sama;
	int count;
	char* Word;
	
	/* ALGORITMA */	
	printf("Mulai membaca dari pitakar.txt\n");
	STARTKATA("pitakar.txt");
	if (!EndKata)
	{
		printf("StrSama (Untuk test ini cek apakah kata pertama sama dengan 'DICHI' : \n");
		
		Word = KataStr(CKata);
		Sama = StrSama(Word, "DICHI");
		printf("StrSama = ");
		if(Sama){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
		printf("\nPrint semua kata yang dibaca dipisah oleh spasi : \n");
		
		while (!EndKata)
		{
			count = 0;
			while (count < CKata.Length){
				count++;
				printf("%c", CKata.TabKata[count]);
			}
			printf(" ");

			ADVKATA();
		}
		printf(".\n");
	}
	else
	{
		printf("pitakar kosong\n");
	}
}
