#include "player.h"
#include "queue.h"
#include "turn.h"
#include "map.h"

Queue PlayerTurns;
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
		RefreshUnit(&InfoUnit(L));
		L = NextUnit(L);
	}
}
/* Berganti turn player */

Player* SearchPlayer(int No)
{
	/* KAMUS LOKAL */
	
	/* ALGORITMA */
	if (PlayerNo(InfoHead(PlayerTurns)) == No){
		return &InfoHead(PlayerTurns);
	}
	else{
		return &InfoTail(PlayerTurns);
	}	
}
/* Mengirimkan pointer ke player yang memiliki nomor player No */

void HealMage (Player P)
{
	/* KAMUS LOKAL */
	Unit* U;
	UnitList L;
	int i;
	
	/* ALGORITMA */	
	L = ListUnit(P);
	
	while(L != Nil){
		if (StrSama(TypeName(InfoUnit(L)), "White_Mage")){
			for(i = 1; i <= 4; i++){
				U = ChooseAdjacentUnit(InfoUnit(L), i);
				if (OwnerUnit(*U) == PlayerNo(P)){
					HealUnit(U, 3);
				}
			}
		}
		L = NextUnit(L);
	}
}
