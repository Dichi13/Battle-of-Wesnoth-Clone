#include <stdio.h>
#include "unit.h"
#include "matriks.h"
#include "map.h"
#include <string.h>

/* Unit */
Unit U;

void command();
/* memanggil fungsi command */

void move();
/* akan menggerakkan unit
    sementara menggunakan input unit, nanti tidak perlu */
void undo();
/* mengembalikan state/kondisi sebelum perintah diberikan */
void change_unit();
/* mengubah unit dalam permainan */
void recruit();
/* merekrut (hanya oleh raja) */
void attack();
/* menyerang musuh
    lebih lengkap baca spek */
void show_map();
/* menunjukkan map, menggunakan fitur printMap */
void show_info();
/* menunjukkan info pemain */
void end_turn();
/* gatau gunanya buat apa, hapus aja klo gapenting */
void save();
/* simpan keadaan permainan, bisa di load saat main lagi */
void exit();
/* keluar dari program */
