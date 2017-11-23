#include "player.h"
#include "queue.h"
#include "turn.h"

extern Queue PlayerTurns;
/* Player pada head adalah currPlayer */

void ChangeTurns()
{
	/* KAMUS LOKAL */
	Player P;
	UnitList L;
	
	/* ALGORITMA */
	P = *currPlayer;
	DelQueue(&PlayerTurns, &P);
	AddQueue(&PlayerTurns, P);
	*currPlayer = InfoHead(PlayerTurns);
	SelectedUnit = Nil;
	
	Gold(*currPlayer) += (Income(*currPlayer) - Upkeep(*currPlayer));
	
	L = ListUnit(P);
	while (L != Nil){
		CanAtk(InfoUnit(FirstUnit(L))) = true;
		MovePoint(InfoUnit(FirstUnit(L))) = MaxMove(InfoUnit(FirstUnit(L)));
	}
	
}
/* Berganti turn player */

Player* SearchPlayer(int No)
{
	/* KAMUS LOKAL */
	Queue Q;
	
	/* ALGORITMA */
	Q = PlayerTurns;
	if (PlayerNo(InfoHead(Q)) == No){
		return &InfoHead(Q);
	}
	else{
		return &InfoTail(Q);
	}	
}
/* Mengirimkan pointer ke player yang memiliki nomor player No */
