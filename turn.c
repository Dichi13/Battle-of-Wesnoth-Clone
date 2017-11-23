#include "player.h"
#include "queue.h"
#include "turn.h"
#include "map.h"

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
		RefreshUnit(&InfoUnit(L));
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
				if ((U != Nil) && OwnerUnit(*U) == PlayerNo(P)){
					Health(*U) += 4;
					if (Health(*U) >= MaxHP(*U)){
						Health(*U) = MaxHP(*U);
					}
				}
			}
		}
		L = NextUnit(L);
	}
}
