/* File : stackMove.c */
/* Realisasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "boolean.h"
#include "stackMove.h"
#include <stdio.h>
#include <stdlib.h>
#include "unit.h"
#include "point.h"

UnitMovementStack MoveStack;

/* ************ Prototype ************ */
void CreateEmptyStack ()
{
	Top(MoveStack) = NilStack;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack ()
{
	return (Top(MoveStack) == NilStack);
}

boolean IsFullStack ()
{
	return (Top(MoveStack) == MaxElStack);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (infostack X)
{
	Top(MoveStack) += 1;
	InfoTop(MoveStack) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (infostack* X)
{
	*X = InfoTop(MoveStack);
	Top(MoveStack) -= 1;
}
