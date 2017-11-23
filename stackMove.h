/* File : stackMove.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackMove_H
#define stackMove_H

#include "boolean.h"
#include "unit.h"
#include "point.h"

#define NilStack 0
#define MaxElStack 20
/* Nil adalah stack dengan elemen kosong . */
/* Karena indeks dalam bhs C dimulai 0 maka tabel dg indeks 0 tidak dipakai */

typedef struct tUnitMove{
	POINT PreviousPosition;
	Unit* MovedUnit;
} UnitMove;

typedef UnitMove infostack;
typedef int address;   /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
	infostack T[MaxElStack+1]; /* tabel penyimpan elemen */
	address TOP;  /* alamat TOP: elemen puncak */
} UnitMovementStack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define MovedUnit(UM) (UM).MovedUnit
#define PrevPos(UM) (UM).PreviousPosition

extern UnitMovementStack MoveStack;
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
UnitMove CreateUnitMove (POINT Prev, Unit* U);
/* Menghasilkan tipe data UnitMove dengan PreviousPosisition = Prev dan MovedUnit = U */

void CreateEmptyStack ();
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack ();
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack ();
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (infostack X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (infostack* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

#endif
