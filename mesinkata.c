/* Nama: David Timothy Panjaitan
 * NIM: 13516075
 * Topik: Mesin Kata  
 */
 
#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"

/* Pendefinisian variable */
boolean EndKata;
Kata CKata;

/* Fungsi */

void IgnoreBlank()  
{
	while ((CC == BLANK || CC == '\n')&&(CC != MARK )) {
		ADV();
	}
}

void STARTKATA(const char *filename) 
{
	START(filename);
	IgnoreBlank();
	if (CC == MARK) {
		EndKata = true;
	} else {
		EndKata = false;
		SalinKata();
	}
}	
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA() {

	IgnoreBlank();
	if (CC == MARK) {
		EndKata = true;
	} else {
		SalinKata();
		if (CC == MARK) {
			EndKata = true;
		}

	}
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata() {
		int i = 0;
		while ((CC != MARK)&&(CC != BLANK)&&(CC != '\n')&&(i <= NMax)) {
			i++;
			CKata.TabKata[i] = CC;
			ADV();
		}
		CKata.Length = (i <= NMax) ? i : NMax;	
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

int KataInt(Kata kat) {
/* mengubah Kata menjadi integer */
	int res = 0, i = 1;
	while (i <= kat.Length) {
		res *= 10;
		char *numstr = kat.TabKata;
		res += (numstr[i] == '1') ? 1 : (numstr[i] == '2') ? 2 : (numstr[i] == '3') ? 3 : (numstr[i] == '4') ? 4 : (numstr[i] == '5') ? 5 : 
		(numstr[i] == '6') ? 6 :(numstr[i] == '7') ? 7 :(numstr[i] == '8') ? 8 :(numstr[i] == '9') ? 9 : 0;
		i++;
	}
	return res;
}

char *KataStr(Kata kat) {
/* mengubah Kata menjadi string */
	char *temp;
	int i;
	
	temp = (char *) malloc(kat.Length*sizeof(char)+1);
	for(i = 0; i < kat.Length; i++) {
		temp[i] = kat.TabKata[i+1];
	}
	temp[i] = '\0';
	return temp;
}

boolean StrSama (char *str1, char *str2) {
	/* Kamus Lokal */
	int i = 0;
	boolean sama;
	
	/* Algoritma */
	sama = true;
	while (str1[i] != '\0' && str2[i] != '\0' && sama) {
		sama = str1[i] == str2[i];
		i++;
	}
	
	return sama;
}
