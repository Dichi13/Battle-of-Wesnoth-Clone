#include "player.h"
#include "queue.h"
#include "map.h"

extern Queue PlayerTurns;
/* Player pada head adalah currPlayer */

void ChangeTurns();
/* Berganti turn player */

Player* SearchPlayer(int No);
/* Mengirimkan pointer ke player yang memiliki nomor playerNo */

void HealMage (Player P);
/* Menge-heal semua unit disekitar white mage pada pergantian turn jika ada white mage */
