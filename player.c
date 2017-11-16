#include "player.h"

/* Primitif-primitif Player */

void CreatePlayer(Player *P) {
/* Membuat player*/
	Gold(*P) = InitGold;
	Income(*P) = 0;
	Upkeep(*P) = 0;
	ListUnit(*P) = Nil;
	ListVillage(*P) = Nil;
}

void PrintUnitPlayer(Player P) {
/* Mencetak unit yang dimiliki player */
	int count = 1;
	addressUnit U;

	if (!IsEmptyList(ListUnit(P)))
	{
		U = FirstUnit(ListUnit(P));
		while (U != Nil){
			printf("%d. %s (%d,%d) | Health %d/%d\n", count, TypeName(InfoUnit(U)), Absis(Position(InfoUnit(U))), Ordinat(Position(InfoUnit(U))), Health(InfoUnit(U)), MaxHP(InfoUnit(U)));
			U = NextUnit(U);
		};
	};
}