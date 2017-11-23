#include "player.h"
#include "stdlib.h"

/* Primitif-primitif Player */

void CreatePlayer(Player *P)
{
	/* Membuat player*/
	Gold(*P) = InitGold;
	Income(*P) = 0;
	Upkeep(*P) = 0;
	ListUnit(*P) = Nil;
	ListVillage(*P) = Nil;
}

void PrintUnitPlayer(Player P) 
{
/* Mencetak unit yang dimiliki player */
	addressUnit U;

	printf("Unit: ");
	if (!IsEmptyUnit(P))
	{
		U = FirstUnit(ListUnit(P));
		while (U != Nil){
			printf("%s (%d,%d) | Health %d/%d | Movement Point: %d | Can Attack: ", TypeName(InfoUnit(U)), Absis(Position(InfoUnit(U))), Ordinat(Position(InfoUnit(U))), Health(InfoUnit(U)), MaxHP(InfoUnit(U)), MovePoint(InfoUnit(U)));
			U = NextUnit(U);
		};
	} else {
		printf("Don't have any unit yet.\n");
	}
}

boolean IsEmptyUnit(Player P) 
{
	return (FirstUnit(ListUnit(P)) == Nil);
}

void AddUnit(Player *P, Unit X) 
{
	addressUnit U = AlokUnit(X);
	NextUnit(U) = FirstUnit(ListUnit(*P));
	FirstUnit(ListUnit(*P)) = U;
}

void DelUnit(Player *P, Unit *U) 
{
	/* KAMUS LOKAL*/
	addressUnit AddrU,PrecAddrU,temp;
	boolean bFound = false;
	
	/* ALGORITMA */
	if (!IsEmptyUnit(*P)) {
		AddrU = FirstUnit(ListUnit(*P));
		PrecAddrU = Nil;
		if ((NextUnit(AddrU) != Nil) && (&InfoUnit(AddrU) != U)) { //jika U tidak di elemen pertama
			while ((AddrU != Nil) && (!bFound)) {
				if (&InfoUnit(AddrU) == U) {
					bFound = true;
				} else {
					PrecAddrU = AddrU;
					AddrU = NextUnit(AddrU);
				}
			}
			if (bFound) {
				NextUnit(PrecAddrU) = NextUnit(AddrU);
				DealokUnit(AddrU);
			}
		} else {
			if (&InfoUnit(AddrU) == U) {  // jika U ditemukan di elemen pertama
				temp = FirstUnit(ListUnit(*P));
				FirstUnit(ListUnit(*P)) = NextUnit(temp);
				DealokUnit(temp);
			}
		}
	}
}

void PrintInfoPlayer(Player P)
{
	printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", Gold(P), Income(P), Upkeep(P));
	PrintUnitPlayer(P);
}

addressUnit AlokUnit(infounit X) 
{
	addressUnit U;

	U = (addressUnit) malloc (sizeof(ElmtUnitList));
	if (U != Nil) {
		InfoUnit(U) = X;
		NextUnit(U) = Nil;
	}

	return U;
}

void DealokUnit(addressUnit U) 
{
	free(U);
}

addressPoint AlokVillage(POINT P)
{
	addressPoint V;

	V = (addressPoint) malloc (sizeof(ElmtVillageList));
	if (V != Nil) {
		InfoVillage(V) = P;
		NextVillage(V) = Nil;
	}

	return V;
}
/* Alokasi unit Village pada POINT P */
void DealokVillage(addressPoint V)
{
	free(V);
}
/* Dealokasi addressPoint V */
boolean IsEmptyVillage(Player P)
{
	return (FirstVillage(ListVillage(P)) == Nil);
}
/* Mengirimkan True jika Player P tidak memiliki Village apapun */

void AddVillage(Player *PL, POINT P)
{
	addressPoint V = AlokVillage(P);
	NextVillage(V) = FirstVillage(ListVillage(*PL));
	FirstVillage(ListVillage(*PL)) = V;
}

void DelVillage(Player *PL, POINT *P)
{
	addressPoint AddrV,PrecAddrV,temp;
	boolean bFound = false;
	if (!IsEmptyVillage(*PL)) {
		AddrV = FirstVillage(ListVillage(*PL));
		PrecAddrV = Nil;
		if ((NextVillage(AddrV) != Nil) && (&InfoVillage(AddrV) != P)) { //jika P tidak di elemen pertama
			while ((AddrV != Nil) && (!bFound)) {
				if (&InfoVillage(AddrV) == P) {
					bFound = true;
				} else {
					PrecAddrV = AddrV;
					AddrV = NextVillage(AddrV);
				}
			}
			if (bFound) {
				NextVillage(PrecAddrV) = NextVillage(AddrV);
				DealokVillage(AddrV);
			}
		} else {
			if (&InfoVillage(AddrV) == P) {  // jika P ditemukan di elemen pertama
				temp = FirstVillage(ListVillage(*PL));
				FirstVillage(ListVillage(*PL)) = NextVillage(temp);
				DealokVillage(temp);
			}
		}
	}
}
/* Menghapus Village pada POINT P ke dalam VillageList Player*/
