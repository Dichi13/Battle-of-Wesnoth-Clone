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
 
/* Combat Unit */
boolean MissChance(Unit U1, Unit U2, boolean Attacking);
/* Mengembalikan true jika kalkulasi misschance hasilnya true (Serangan unit U1 terhadap U2 miss) */
/* Attacking bernilai true jika Unit U1 memulai combat (bukan retaliate) */
/* Default MissChance adalah 10% */
/* Unit yang retaliate memiliki miss change lebih tinggi (20%) (Mendorong player untuk lebih aktif dan inisiatif) */
/* Unit mendapatkan bonus miss chance berdasarkan petak tempat unit itu berada : 
 * Normal plot : 0%
 * Village : 5%
 * Castle : 10%
 * Tower : 20% */


void AttackUnit(Unit *U1, Unit *U2);
/* I.S. U1 dan U2 terdefinisi */
/* F.S. Melaksanakan serangan dari U1 ke U2 sesuai definisi "serangan" di spesifikasi tugas */
/* Unit yang diserang hanya dapat retaliate jika serangan penyerang tidak miss */
