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

/*
void command()
{
  char command[14];
  do
  {
    printf("Your Input: ");
    fgets(command,14,key);
    switch (command) {
      case :
    }
  }
  while (strcmp(command,"EXIT") != 0);
}
*/

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
			  pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
		  }
	  }
	  for(i = 1; i < dy; i++) {
		  Geser(&current, 0, 1);
		  if ((PlotUnit(Petak(M, current))) != Nil) {
			  pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
		  }
	  }
	  if (!pathclear) {
		current = Position(U);
		pathclear = true;
		for(i = 1; i < dy; i++) {
			Geser(&current, 0, 1);
			if ((PlotUnit(Petak(M, current))) != Nil) {
				pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
			}
		}
		for(i = 1; i < dx; i++) {
			Geser(&current, 1, 0);
			if ((PlotUnit(Petak(M, current))) != Nil) {
				pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
			}
		}
	  }	  
  }
  
  return valid && pathclear;
}

void Move()
{
  POINT dest;

  {
    printf("Please​ ​enter​ ​destination​ ​coordinate​ ​x​ ​y (example : 1 1 ) : \n");
    BacaPOINT(&dest);
    printf("\n");
    /* geser sejauh dx,dy */
    if (IsMoveValid(dest, *SelectedUnit)){
		Push(Position(*SelectedUnit));
		MovePoint(*SelectedUnit) -= abs(Absis(dest)-Absis(Position(*SelectedUnit)))+abs(Ordinat(dest)-Ordinat(Position(*SelectedUnit)));
		Position(*SelectedUnit) = dest;
		if((PlotType(Petak(M, dest)) == 'V') && (Owner(Petak(M, dest)) != PlayerNo(*currPlayer))){
			DelVillage(SearchPlayer(Owner(Petak(M, dest))), &dest);
			Income(*SearchPlayer(Owner(Petak(M, dest)))) -= IncomePerVillage;
			AddVillage(currPlayer, dest);
			Income(*currPlayer) += IncomePerVillage;
			SetPlot(dest, 'V', PlayerNo(*currPlayer));
		}
    }
    else
    {
      printf("You can't move there\n");
    }
  }
}

void Undo() 
{
	/* Kamus Lokal */
	Unit undoUnit;
	POINT PosAwal;
	int dist;
	
	/* Algoritma */
	Pop(&PosAwal);
	dist = abs(Absis(Position(undoUnit))-Absis(PosAwal)) + abs(Ordinat(Position(undoUnit))-Ordinat(PosAwal));
	MovePoint(undoUnit) += dist;
	Position(undoUnit) = PosAwal;
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
	
	return found;
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
			printf("Please​ ​select​ ​enemy​ ​you​ ​want​ ​to​ ​attack: \n");
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
			printf("Enemy's %s is damaged by %d.", TypeName(*UAd), Atk(*SelectedUnit));
			if (Health(*UAd) <= 0){
				printf("Enemy's %s died.", TypeName(*UAd));
				if (StrSama(TypeName(*UAd), "King")){
					EndGame = true;
					Winner = OwnerUnit(*UAd);
				}
				SetUnit(Position(*UAd), Nil);
				DelUnit(SearchPlayer(OwnerUnit(*UAd)), UAd);
			}
			else{
				if (CanRetaliate(*SelectedUnit, *UAd)){
					printf("Enemy's %s retaliates.", TypeName(*UAd));
					printf("Your %s is damaged by %d.", TypeName(*SelectedUnit), Atk(*UAd));
					if(Health(*SelectedUnit) <= 0){
						printf("Your %s died.", TypeName(*SelectedUnit));
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
		printf("This unit already attacked or has just been recruited");
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
		printf("Please​ ​enter​ ​cell’s​ ​coordinate​ ​x​ ​y: ");
		BacaPOINT(&P);
		if (IsIdxEff((Peta(M)), Absis(P), Ordinat(P))){
			printf("==​ ​Plot​ ​Info​ ​==\n");
			printf("Plot type of ");
			PrintPlotType(P);
			printf("\n");
			if (Owner(Petak(M, P)) != 0){
				printf("Owned by Player %d\n", Owner(Petak(M, P)));
			}
			else{
				printf("Plot not owned by any player\n");
			}
			printf("==​ ​Unit​ ​Info​ ​==\n");
			if (PlotUnit(Petak(M, P)) != Nil){
				printf("%s\n", TypeName(*PlotUnit(Petak(M, P))));
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
}

/* Input/Output */
void PrintMap()
{
	/* KAMUS LOKAL */
	int i, j;
	POINT P;
	
	/* ALGORITMA */
	for(i = GetFirstIdxBrs(Peta(M)); j <= GetLastIdxBrs(Peta(M)); i++){
		/* Print garis "*****" */
		printf("*");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			printf("****");	
		}
		printf("\n");
		
		/* Print jenis petak */
		printf("* ");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(i, j);
			if (PlotType(Petak(M, P)) != 'N'){
				if (Owner(Petak(M, P)) == 0){
					printf("%c", PlotType(Petak(M, P)));
				}
				if (Owner(Petak(M, P)) == 1){
					print_red(PlotType(Petak(M, P)));
				}
				if (Owner(Petak(M, P)) == 2){
					print_blue(PlotType(Petak(M, P)));
				}
			}
			else{
				printf(" ");
			}
			printf(" *");
		}
		printf("\n");
		
		/* Print Unit */
		printf("* ");
		for(j = GetFirstIdxKol(Peta(M)); j <= GetLastIdxKol(Peta(M)); j++){
			P = MakePOINT(i, j);
			if (PlotUnit(Petak(M, P)) != Nil){
				if (SelectedUnit == PlotUnit(Petak(M, P))){
					print_green(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
				if (Owner(Petak(M, P)) == 1){
					print_red(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
				if (Owner(Petak(M, P)) == 2){
					print_blue(TypeName(*PlotUnit(Petak(M, P)))[0]);
				}
			}
			else{
				printf(" ");
			}
			printf(" *");
		}
		printf("\n");
		
		
	}
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
 * *****
 * Dengan X adalah jenis petak, dikosongkan jika petak Normal
 * Y adalah jenis unit pada petak, dikosongkan jika tidak ada unit */

/*
void end_turn();
void save();

void next_unit();
*/

