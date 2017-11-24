#include "unit.h"
#include "map.h"
#include <stdio.h>
#include <math.h>
#include "point.h"
#include "stackMove.h"
#include "player.h"
#include "turn.h"
#include <math.h>
#include "pcolor.h"

extern boolean EndGame;
extern int Winner;

/*
void command()
{
  char command[14];
  do
  {
    printf("Your Input: ");
    fgets(command,14,key);
    switch (command) {
      case :
    }
  }
  while (strcmp(command,"EXIT") != 0);
}
*/

boolean IsMoveValid(POINT dest, Unit U);
/* Menghasilkan true jika Move Unit U ke koordinat dest valid */

void Move();
/* Menggerakan Unit U berdasarkan input user yang diterima dalam fungsi */

void Undo() ;
/* Mengundo gerakan Move terakhir pada Unit */

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

