#include "unit.h"

#define Nill 0
#define MaxEl 100

typedef int address;
typedef POINT infotype;

typedef struct {
	infotype T[MaxEl+1];
	address TOP;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmpty (Stack *S) {
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
	Top(*S) = Nill;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmpty (Stack S) {
/* Mengirim true jika Stack kosong: lihat definisi di atas */
	return Top(S) == Nill;
}

boolean IsFull (Stack S) {
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
	return Top(S) == MaxEl;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, infotype P) {
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
	Top(*S)++;
	InfoTop(*S) = P;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, infotype* P) {
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	*P = InfoTop(*S);
	Top(*S)--;
}

/* ************ Fungsi yang menggunakan stack ************ */
void UNDO(Unit *U) {
/* Mengembalikan posisi unit ke tempat sebelum dipindahkan */
/* I.S Unit berada pada posisi P2(X2,Y2) */
/* F.S Unit berada pada posisi sebelumnya, yaitu P1(X1,Y1) */
	Stack S;
	POINT P1;
	Pop(&S,&P1);
	MovePoint(*U) += abs(Absis(Position(*U)) - Absis(P1)) + abs(Ordinat(Position(*U)) - Ordinat(P1));
	Position(*U) = P1;
}

void ATTACK() {
	Unit canBeAttacked[5];

	/*int x;
	printf("Please select enemy you want to attack:\n");
	printf("Select enemy you want to attack: "); scanf("%d", &x);
	printf("Enemy's %s", TypeName(x), " ");*/
}