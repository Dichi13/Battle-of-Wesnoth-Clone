/* Command */

#include "command.h"
#include "unit.h"
#include "map.h"
#include <stdio.h>
#include <math.h>
#include "point.h"
#include "stackMove.h"
#include "player.h"
#include "turn.h"
#include <math.h>
#include "pcolor.h"

boolean EndGame;
int Winner;

boolean IsMoveValid(POINT dest, Unit U)
{
  /* KAMUS LOKAL */
  int dx, dy, i;
  POINT current;
  boolean valid, pathclear;
  
  /* ALGORITMA */
  current = Position(U);
  dx = abs(Absis(current) - Absis(dest));
  dy = abs(Ordinat(current) - Ordinat(dest));
  valid = ((dx + dy) <= MovePoint(U));
  
  if (valid) {
	  if(PlotUnit(Petak(M, dest)) != Nil){
		  valid = false;
	  }
	  
	  pathclear = true;		//perlu dicek perjalanan ke petak itu dihalangi musuh atau tidak
	  for(i = 1; i < dx; i++) {
		  Geser(&current, 1, 0);
		  if ((PlotUnit(Petak(M, current))) != Nil) {
			  pathclear = OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
		  }
	  }
	  for(i = 1; i < dy; i++) {
		  Geser(&current, 0, 1);
		  if ((PlotUnit(Petak(M, current))) != Nil) {
			  pathclear = OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
		  }
	  }
	  if (!pathclear) {
		current = Position(U);
		pathclear = true;
		for(i = 1; i < dy; i++) {
			Geser(&current, 0, 1);
			if ((PlotUnit(Petak(M, current))) != Nil) {
				pathclear = OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
			}
		}
		for(i = 1; i < dx; i++) {
			Geser(&current, 1, 0);
			if ((PlotUnit(Petak(M, current))) != Nil) {
				pathclear = OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
			}
		}
	  }	  
  }
  
  return valid && pathclear;
}

void Move()
{
	POINT dest;
	
	PrintMapMove();
	printf("Please enter destination coordinate x y (example : 1 1 ) : \n");
	BacaPOINT(&dest);
	printf("\n");
	/* geser sejauh dx,dy */
	if (IsMoveValid(dest, *SelectedUnit)){
		Push(Position(*SelectedUnit));
		SetUnit(Position(*SelectedUnit), Nil);
		MoveUnit(SelectedUnit, Absis(dest) - Absis(Position(*SelectedUnit)), Ordinat(dest) - Ordinat(Position(*SelectedUnit)));
		SetUnit(dest, SelectedUnit);
		
		/* Pengambilan Village */
		if((PlotType(Petak(M, dest)) == 'V') && (Owner(Petak(M, dest)) != PlayerNo(*currPlayer))){
			DelVillage(SearchPlayer(Owner(Petak(M, dest))), &dest);
			Income(*SearchPlayer(Owner(Petak(M, dest)))) -= IncomePerVillage;
			AddVillage(currPlayer, dest);
			Income(*currPlayer) += IncomePerVillage;
			SetPlot(dest, 'V', PlayerNo(*currPlayer));
		}
		
		/* Mengubah CanAtk menjadi false jika tidak ada unit musuh disekitar untuk pemilihan NEXT_UNIT */
		if ((MovePoint(*SelectedUnit) == 0) && (IsAdjacentEmpty(*SelectedUnit, true))){
			CanAtk(*SelectedUnit) = false;
		}
	}
	else
	{
		printf("You can't move there\n");
	}
}

void ChangeUnit()
{
	/* KAMUS LOKAL */
	int NBUnit, selection;
	addressUnit U;
	
	/* ALGORITMA */
	PrintUnitPlayer(*currPlayer);
	NBUnit = NbElmtListUnit(*currPlayer);
	do {
		printf("Please enter your selection number : ");
		scanf("%d", &selection);
		if ((selection > NBUnit) || (selection <= 0)){
			printf("Please enter a valid number\n");
		}
	} while ((selection > NBUnit) || (selection <= 0));
	
	U = TraversalElmtUnitList(*currPlayer, selection);
	
	SelectedUnit = &InfoUnit(U);
	SetUnit(Position(*SelectedUnit), SelectedUnit);
	
	printf("You are now selecting %s (%d,%d)\n", TypeName(*SelectedUnit), Absis(Position(*SelectedUnit)), Ordinat(Position(*SelectedUnit)));
}

void NextSelect()
{
	/* KAMUS LOKAL */
	UnitList L;
	boolean found;
	Unit U;
	
	/* ALGORITMA */
	L = ListUnit(*currPlayer);
	found = false;
	
	while(L != Nil && !found){
		U = InfoUnit(L);
		found = (MovePoint(U) > 0 || CanAtk(U));
		if (!found){
			L = NextUnit(L);
		}
	}
	
	if (!found){
		printf("None of your units are still able to act\n");
	}
	else{
		*SelectedUnit = U;
		printf("You are now selecting %s (%d,%d)\n", TypeName(*SelectedUnit), Absis(Position(*SelectedUnit)), Ordinat(Position(*SelectedUnit)));
	}
	
}
void Undo() 
{
	/* Kamus Lokal */
	POINT PosAwal;
	int dist;
	
	/* Algoritma */
	Pop(&PosAwal);
	dist = abs(Absis(Position(*SelectedUnit))-Absis(PosAwal)) + abs(Ordinat(Position(*SelectedUnit))-Ordinat(PosAwal));
	MovePoint(*SelectedUnit) += dist;
	SetUnit(Position(*SelectedUnit), Nil);
	Position(*SelectedUnit) = PosAwal;
	SetUnit(PosAwal, SelectedUnit);	
	CanAtk(*SelectedUnit) = true;
}

boolean IsCastleFull()
{
	/* KAMUS LOKAL */
	boolean Full;
	POINT C1, C2, C3, C4;
	
	/* ALGORITMA */
	if(PlayerNo(*currPlayer) == 1){
	/* Inisiasi untuk Player 1 */
		C1 = MakePOINT(GetLastIdxBrs(Peta(M)), GetFirstIdxKol(Peta(M))+1);
		C2 = MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M)));
		C3 = MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M)));
		C4 = MakePOINT(GetLastIdxBrs(Peta(M))-2, GetFirstIdxKol(Peta(M))+1);
	}
	if(PlayerNo(*currPlayer) == 2){
	/* Inisiasi untuk Player 2 */
		C1 = MakePOINT(GetFirstIdxBrs(Peta(M)), GetLastIdxKol(Peta(M))-1);
		C2 = MakePOINT(GetFirstIdxBrs(Peta(M))+1, GetLastIdxKol(Peta(M)));
		C3 = MakePOINT(GetFirstIdxBrs(Peta(M))+1, GetLastIdxKol(Peta(M))-2);
		C4 = MakePOINT(GetFirstIdxBrs(Peta(M))+2, GetLastIdxKol(Peta(M))-1);
	}
	
	Full = ((PlotUnit(Petak(M, C1)) != Nil) && (PlotUnit(Petak(M, C2)) != Nil) && (PlotUnit(Petak(M, C3)) != Nil) && (PlotUnit(Petak(M, C4)) != Nil));
	
	return Full;	
}


void Recruit()
{
	/* KAMUS LOKAL */
	POINT dest;
	boolean valid;
	int i;
	Unit U;
	
	/* ALGORITMA */
	if (strcmp(TypeName(*SelectedUnit),"King") == 0){
		if(PlotType(Petak(M, Position(*SelectedUnit))) == 'T'){
			if(!IsCastleFull()){
				do{
					printf("Enter coordinate of empty castle : ");
					BacaPOINT(&dest);
					valid = true;
					if(PlotType(Petak(M, dest)) != 'C'){
						valid = false;
						printf("Selected coordinate is not a castle!\n");
					}
					else{
						if(Owner(Petak(M, dest)) != PlayerNo(*currPlayer)){
							valid = false;
							printf("That is not your castle!\n");
						}
					}
				} while (!valid);
				printf("========== List of recruitable units ==========\n");
				for (i = 1; i<NbUnitType; i++) {
					printf("%d. %s | Health %d | ATK %d | Cost %dG\n", i, TypeList[i].TypeName, TypeList[i].MaxHP, TypeList[i].Atk, TypeList[i].Cost);
				}
				printf("Enter the index of the unit you want to recruit :");
				scanf("%d", &i);
				if (Gold(*currPlayer) >= TypeList[i].Cost) {
					Gold(*currPlayer) -= TypeList[i].Cost;
					U = CreateUnit(i, dest, PlayerNo(*currPlayer));
					AddUnit(currPlayer, U);
					PlotUnit(Petak(M, dest)) = &U;
					MovePoint(U) = 0;
					CanAtk(U) = false;
					UnreadyUnit(*SelectedUnit);
				} else {
					printf("You don't have enough gold to recruit that unit!\n");
				}
				
			}
			else{
				printf("All castles are full");
			}
		}
		else{
			printf("The King is not in the Tower\n");
		} 
	}
	else{
		printf("You have to select The King to recruit\n");
	}
}

boolean IsAdjacentEmpty(Unit U, boolean Enemy)
{
	/* KAMUS LOKAL */
	boolean found;
	Unit* UAd;
	int i;
	
	/* ALGORITMA */
	if (Enemy){
		i = 0;
		while (i < 4 && !found){
			i++;
			UAd = ChooseAdjacentUnit(U, i);
			found = ((UAd != Nil) && (OwnerUnit(*UAd) != PlayerNo(*currPlayer)));
		}
	}
	else{
		i = 0;
		while (i < 4 && !found){
			i++;
			UAd = ChooseAdjacentUnit(U, i);
			found = ((UAd != Nil) && (OwnerUnit(*UAd) == PlayerNo(*currPlayer)));
		}
	}
	
	return !found;
}
/* Menghasilkan True jika ada Unit untuk tipe Enemy di sekitar unit (Kiri/Atas/Kanan/Bawah) 
 * Mengecek keberadaan Musuh jika Enemy = true, dan sebaliknya */

void ShowAttackTarget(Unit U)
{
	/* KAMUS LOKAL */
	Unit* UAd;
	int i, count;
	
	/* ALGORITMA */
	count = 0;
	for(i = 1; i <= 4; i++){
		UAd = ChooseAdjacentUnit(U, i);
		if (UAd != Nil){
			count += 1;
			printf("%d. ",count);
			printf("%s ", TypeName(*UAd));
			printf("(%d,%d) | Health %d/%d | ATK %d", Absis(Position(*UAd)), Ordinat(Position(*UAd)), Health(*UAd), MaxHP(*UAd), Atk(*UAd));
			if(CanRetaliate(U, *UAd)){
				printf(" (Retaliates)\n");
			}
			else{
				printf(" (Does not Retaliate)\n");
			}
			
		}
	}
}

void Attack()
{
	/* KAMUS LOKAL */
	int i, count, selection;
	Unit* UAd;
	
	/* ALGORITMA */
	if (CanAtk(*SelectedUnit)){
		if (IsAdjacentEmpty(*SelectedUnit, true)){
				printf("There are no enemies adjacent to selected Unit\n");
		}
		else{
			printf("Please select the enemy unit you want to attack\n");
			ShowAttackTarget(*SelectedUnit);
			do{
				printf("Your selection : ");
				scanf("%d", &selection);
				count = 0;
				i = 0;
				while ((i < 4) || (count != selection)){
					i++;
					UAd = ChooseAdjacentUnit(*SelectedUnit, i);
					if (UAd != Nil){
						count++;
					}
				}
				if(count != selection){
					printf("Please select a valid target\n");
				}
			}while (count != selection);
			AttackUnit(SelectedUnit, UAd);
			printf("Enemy's %s is damaged by %d.\n", TypeName(*UAd), Atk(*SelectedUnit));
			if (Health(*UAd) <= 0){
				printf("Enemy's %s died.\n", TypeName(*UAd));
				if (StrSama(TypeName(*UAd), "King")){
					EndGame = true;
					Winner = OwnerUnit(*UAd);
				}
				SetUnit(Position(*UAd), Nil);
				DelUnit(SearchPlayer(OwnerUnit(*UAd)), UAd);
			}
			else{
				if (CanRetaliate(*SelectedUnit, *UAd)){
					printf("Enemy's %s retaliates.\n", TypeName(*UAd));
					printf("Your %s is damaged by %d.\n", TypeName(*SelectedUnit), Atk(*UAd));
					if(Health(*SelectedUnit) <= 0){
						printf("Your %s died.\n", TypeName(*SelectedUnit));
						SetUnit(Position(*SelectedUnit), Nil);
						DelUnit(currPlayer, SelectedUnit);
						SelectedUnit = Nil;
						if (StrSama(TypeName(*SelectedUnit), "King")){
							EndGame = true;
							Winner = OwnerUnit(*SelectedUnit);
						}
					}
					UnreadyUnit(*SelectedUnit);
				}
			}
		}
	}
	else{
		printf("This unit already attacked or has just been recruited\n");
	}
}


/* Mencetak semua Unit yang jarak dengan Unit U = 1 
 * Menunjukan Unit musuh jika Enemy = true, dan sebaliknya */
void InfoPetak()
{
	/* KAMUS LOKAL */
	POINT P;
	
	/* ALGORITMA */
	do{
		printf("Please enter cell's coordinate x y : ");
		BacaPOINT(&P);
		if (IsIdxEff((Peta(M)), Absis(P), Ordinat(P))){
			printf("== Plot Info ==\n");
			printf("Plot type of ");
			PrintPlotType(P);
			printf("\n");
			if (Owner(Petak(M, P)) != 0){
				printf("Owned by Player %d\n", Owner(Petak(M, P)));
			}
			else{
				printf("Plot not owned by any player\n");
			}
			printf("\n== Unit Info ==\n");
			if (PlotUnit(Petak(M, P)) != Nil){
				printf("%s\n", TypeName(*PlotUnit(Petak(M, P))));
				printf("Owned by Player %d\n", OwnerUnit(*PlotUnit(Petak(M, P))));
				printf("Health %d/%d | ATK %d", Health(*PlotUnit(Petak(M, P))), MaxHP(*PlotUnit(Petak(M, P))), Atk(*PlotUnit(Petak(M, P))));
			}
			else{
				printf("There is no unit inside this plot\n");
			}
		}
		else{
			printf("Invalid plot\n");
		}
	} while (!(IsIdxEff((Peta(M)), Absis(P), Ordinat(P))));
	printf("\n");
}

/* Input/Output */
void PrintMap()
{
	/* KAMUS LOKAL */
	int i, j;
	POINT P;
	
	/* ALGORITMA */
	printf("==-");
	for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
		printf("-%d--",j);	
	}
	printf("\n");
	for(i = GetFirstIdxBrs(Peta(M)); i <= GetLastIdxBrs(Peta(M)); i++){
		/* Print garis "*****" */
		printf("| *");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			printf("****");	
		}
		printf("\n");
		
		/* Print jenis petak */
		printf("| *");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(j, i);
			if (PlotType(Petak(M, P)) != 'N'){
				printf(" ");
				if (Owner(Petak(M, P)) == 0){
					printf("%c", PlotType(Petak(M, P)));
				}
				if (Owner(Petak(M, P)) == 1){
					print_red(PlotType(Petak(M, P)));
				}
				if (Owner(Petak(M, P)) == 2){
					print_cyan(PlotType(Petak(M, P)));
				}
			}
			else{
				printf("  ");
			}
			printf(" *");
		}
		printf("\n");
		
		/* Print Unit */
		printf("%d *", i);
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(j, i);
			if (PlotUnit(Petak(M, P)) != Nil){
				printf(" ");
				if (SelectedUnit == PlotUnit(Petak(M, P))){
					print_green(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
				else if (OwnerUnit(*PlotUnit(Petak(M, P))) == 1){
					print_red(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
				else if (OwnerUnit(*PlotUnit(Petak(M, P))) == 2){
					print_cyan(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
			}
			else{
				printf("  ");
			}
			printf(" *");
		}
		printf("\n");
		
		printf("| *");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			printf("   *");	
		}
		printf("\n");
		
	}
	printf("| *");
	for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
		printf("****");	
	}
	printf("\n");
}	
/* Map terdefinisi */
/* Map dicetak pada layar dengan format
 * ***** 
 * *​ ​​X ​* 
 * *​ ​​Y ​​* 
 * *   *
 * *****
 * Dengan X adalah jenis petak, dikosongkan jika petak Normal
 * Y adalah jenis unit pada petak, dikosongkan jika tidak ada unit */


void PrintMapMove()
{
	/* KAMUS LOKAL */
	int i, j;
	POINT P;
	
	/* ALGORITMA */
	printf("==-");
	for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
		printf("-%d--",j);	
	}
	printf("\n");	
	for(i = GetFirstIdxBrs(Peta(M)); i <= GetLastIdxBrs(Peta(M)); i++){
		/* Print garis "*****" */
		printf("| *");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			printf("****");	
		}
		printf("\n");
		
		/* Print jenis petak */
		printf("| *");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(j, i);
			if (PlotType(Petak(M, P)) != 'N'){
				printf(" ");
				if (Owner(Petak(M, P)) == 0){
					printf("%c", PlotType(Petak(M, P)));
				}
				if (Owner(Petak(M, P)) == 1){
					print_red(PlotType(Petak(M, P)));
				}
				if (Owner(Petak(M, P)) == 2){
					print_cyan(PlotType(Petak(M, P)));
				}
			}
			else{
				printf("  ");
			}
			printf(" *");
		}
		printf("\n");
		
		/* Print Unit */
		printf("%d *", i);
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(j, i);
			if (PlotUnit(Petak(M, P)) != Nil){
				printf(" ");
				if (SelectedUnit == PlotUnit(Petak(M, P))){
					print_green(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
				else if (OwnerUnit(*PlotUnit(Petak(M, P))) == 1){
					print_red(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
				else if (OwnerUnit(*PlotUnit(Petak(M, P))) == 2){
					print_cyan(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
			}
			else{
				if(IsMoveValid(P, *SelectedUnit)){
					printf(" #");
				}
				else{
					printf("  ");
				}
			}
			printf(" *");
		}
		printf("\n");
		
		printf("| *");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			printf("   *");	
		}
		printf("\n");
		
	}
	printf("| *");
	for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
		printf("****");	
	}
	printf("\n");
}	
/* Map terdefinisi */
/* Map dicetak pada layar dengan format
 * ***** 
 * *​ ​​X ​* 
 * *​ ​​Y ​​* 
 * *   *
 * *****
 * Dengan X adalah jenis petak, dikosongkan jika petak Normal
 * Y adalah jenis unit pada petak, dikosongkan jika tidak ada unit */
/* Tercetak
 * ***** 
 * *​ ​​X ​* 
 * *​ ​​# ​​*
 * *   * 
 * *****
 * jika petak tersebut valid untuk jalan unit */
