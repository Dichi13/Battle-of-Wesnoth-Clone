#include "player.h"
#include "queue.h"

extern Queue PlayerTurns;
/* Player pada head adalah currPlayer */

void ChangeTurns();
/* Berganti turn player */

Player* SearchPlayer(int No);
/* Mengirimkan pointer ke player yang memiliki nomor playerNo */
