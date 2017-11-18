#include "player.h"
#include "stdlib.h"

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
	addressUnit U;

	printf("Unit: ");
	if (!IsEmptyList(ListUnit(P)))
	{
		U = FirstUnit(ListUnit(P));
		while (U != Nil){
			printf("%s (%d,%d) | Health %d/%d | Movement Point: %d | Can Attack: ", TypeName(InfoUnit(U)), Absis(Position(InfoUnit(U))), Ordinat(Position(InfoUnit(U))), Health(InfoUnit(U)), MaxHP(InfoUnit(U)), MovePoint(U));
			U = NextUnit(U);
		};
	} else {
		printf("Don't have any unit yet.\n");
	}
}

boolean IsEmptyUnit(Player P) {
	return (FirstUnit(ListUnit(P)) == Nil);
}

void AddUnit(Player *P, Unit X) {
	addressUnit U = AlokUnit(X);
	NextUnit(U) = FirstUnit(ListUnit(*P));
	FirstUnit(ListUnit(*P)) = U;
}

void DelUnit(Player *P, Unit U) {
	addressUnit AddrU,PrecAddrU,temp;
	boolean bFound = false;
	if (!IsEmptyUnit(ListUnit(*P))) {
		AddrU = FirstUnit(ListUnit(*P));
		PrecAddrU = Nil;
		if (NextUnit(AddrU) != Nil) && (AddrU != U) {
			while ((AddrU != Nil) && (!bFound)) {
				if (AddrU == U) {
					bFound = true;
				} else {
					PrecAddrU = AddrU;
					AddrU = NextUnit(AddrU);
				}
			}
			if (bFound) {
				NextUnit(PrecAddrU) = NextUnit(AddrU);
				Dealokasi(AddrU);
			}
		} else {
			if (AddrU == U) {
				temp = FirstUnit(ListUnit(*P));
				FirstUnit(ListUnit(*P)) = Next(temp);
				Dealokasi(temp);
			}
		}
	}
}

void PrintInfoPlayer(Player P){
	printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", Gold(P), Income(P), Upkeep(P));
	PrintUnitPlayer(P);
}

addressUnit AlokUnit(infounit X) {
	addressUnit U;

	U = (addressUnit) malloc (sizeof(ElmtUnitList));
	if (U != Nil) {
		InfoUnit(U) = X;
		NextUnit(U) = Nil;
	}

	return U;
}

void DealokUnit(addressUnit U) {
	free(U);
}