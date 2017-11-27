#include "player.h"
#include "stdlib.h"
#include "map.h"

Player* currPlayer;
Unit* SelectedUnit;

/* Primitif-primitif Player */
Player CreatePlayer(int No)
{
	/* KAMUS LOKAL */
	Player P;
	
	/* Algoritma */
	PlayerNo(P) = No;
	Gold(P) = InitGold;
	Income(P) = 0;
	Upkeep(P) = 0;
	CreateEmptyListUnit(&ListUnit(P));
	CreateEmptyListVillage(&ListVillage(P));
	
	return P;
}

void PrintInfoPlayer(Player P)
{
	printf("Cash: %dG | Income: %dG | Upkeep: %dG\n", Gold(P), Income(P), Upkeep(P));
}

void PrintUnitPlayer(Player P) 
{
/* Mencetak unit yang dimiliki player dengan format 
 * No. [Jenis Unit] [Koordinat Unit] | [Health Unit] */
	/* KAMUS LOKAL */
	addressUnit U;
	int count;
	
	/* ALGORITMA */
	printf("== List of Units ==\n");
	
	count = 0;
	U = FirstUnit(ListUnit(P));
	while (U != Nil){
		count += 1;
		printf("%d. %s (%d,%d) | Health %d/%d\n", count, TypeName(InfoUnit(U)), Absis(Position(InfoUnit(U))), Ordinat(Position(InfoUnit(U))), Health(InfoUnit(U)), MaxHP(InfoUnit(U)));
		U = NextUnit(U);
	}
}

boolean IsEmptyUnit(Player P) 
{
	return (IsEmptyUnitList(ListUnit(P)));
}

void AddUnit(Player *P, Unit X) 
{
	/* KAMUS LOKAL */
	addressUnit U;
	
	/* ALGORITMA */
	U = AlokUnit(X);
	NextUnit(U) = FirstUnit(ListUnit(*P));
	FirstUnit(ListUnit(*P)) = U;
	SetUnit(Position(InfoUnit(U)), &InfoUnit(U));
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

int NbElmtListUnit(Player P)
{
	/* KAMUS LOKAL */
	int count;
	UnitList L;
	
	/* ALGORITMA */
	count = 0;
	L = ListUnit(P);
	
	while (L != Nil){
		count += 1;
		L = NextUnit(L);
	}
	
	return count;
}

addressUnit TraversalElmtUnitList (Player P, int i)
{
	/* KAMUS LOKAL */
	UnitList U;
	int count;
	
	/* ALGORITMA */
	U = ListUnit(P);
	count = i;
	while (count > 1){
		U = NextUnit(U);
		count -= 1;
	}
	
	return U;		
}
/* Mengembalikan Unit ke-i jika dihitung dari depan dari ListUnit Player P */
/* Elemen ke-i ada di ListUnit */


boolean IsEmptyVillage(Player P)
{
	return (IsEmptyVillageList(ListVillage(P)));
}
/* Mengirimkan True jika Player P tidak memiliki Village apapun */

void AddVillage(Player *PL, POINT P)
{
	InsertFirstVillage(&ListVillage(*PL), P);
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

