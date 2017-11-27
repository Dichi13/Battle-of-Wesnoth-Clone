#include "unit.h"
#include "map.h"
#include <stdio.h>
#include <math.h>
#include "point.h"
#include "stack.h"
#include "player.h"
#include "turn.h"
#include <math.h>
#include "pcolor.h"

extern boolean EndGame;
extern int Winner;

boolean IsPathClear(POINT src, POINT dest, Unit U);
/* Mengembalikan true jika path dari src menuju dest memiliki jalur yang tidak dihalangi musuh */
/* Dipastikan unit U dapat jalan ke dest dengan move pointnya jika tidak dihalangi */

boolean IsMoveValid(POINT dest, Unit U);
/* Menghasilkan true jika Move Unit U ke koordinat dest valid */

void Move();
/* Menggerakan Unit U berdasarkan input user yang diterima dalam fungsi */

void Undo() ;
/* Mengundo gerakan Move terakhir pada Unit */

void ChangeUnit();
/* Mengganti pilihan Unit */

void NextSelect();
/* Memilih secara automatis suatu unit pada List current player yang masih dapat menyerang atau bergerak */

boolean IsCastleFull();
/* Menghasilkan true jika semua Castle currPlayer memiliki unit */

void Recruit();
/* Merekrut suatu unit */

boolean IsAdjacentEmpty(Unit U, boolean Enemy);
/* Menghasilkan True jika ada Unit untuk tipe Enemy di sekitar unit (Kiri/Atas/Kanan/Bawah) 
 * Mengecek keberadaan Musuh jika Enemy = true, dan sebaliknya */

void ShowAttackTarget(Unit U);
/* Mencetak target-target valid untuk diserang */

void Attack();
/* Mencetak semua Unit yang jarak dengan Unit U = 1 
 * Menunjukan Unit musuh jika Enemy = true, dan sebaliknya */
 
void InfoPetak();
/* Menunjukkan info suatu petak */

void PrintMap();
/* Mencetak keseluruhan map */
/* Map dicetak pada layar dengan format
 * ***** 
 * *​ ​​X ​* 
 * *​ ​​Y ​​* 
 * *   *
 * *****
 * Dengan X adalah jenis petak, dikosongkan jika petak Normal
 * Y adalah jenis unit pada petak, dikosongkan jika tidak ada unit */

void PrintMapMove();
/* Map terdefinisi */
/* Map dicetak pada layar dengan format
 * ***** 
 * *​ ​​X ​* 
 * *​ ​​Y ​​* 
 * *   *
 * *****
 * Dengan X adalah jenis petak, dikosongkan jika petak Normal
 * Y adalah jenis unit pada petak, dikosongkan jika tidak ada unit */
/* Tercetak
 * ***** 
 * *​ ​​X ​* 
 * *​ ​​# ​​*
 * *   * 
 * *****
 * jika petak tersebut valid untuk jalan unit */

