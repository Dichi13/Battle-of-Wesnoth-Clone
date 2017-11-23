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


<<<<<<< HEAD
=======
extern Unit* SelectedUnit; // 
extern int CurrPlayer;    // Ner, gw ubah jadi make yg pointer ya
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79

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
<<<<<<< HEAD
		  if ((PlotUnit(Petak(M, current))) != Nil) {
=======
		  if ((*PlotUnit(Petak(M, current))) != Nil) {
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
			  pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
		  }
	  }
	  for(i = 1; i < dy; i++) {
		  Geser(&current, 0, 1);
<<<<<<< HEAD
		  if ((PlotUnit(Petak(M, current))) != Nil) {
=======
		  if ((*PlotUnit(Petak(M, current))) != Nil) {
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
			  pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
		  }
	  }
	  if (!pathclear) {
		current = Position(U);
		pathclear = true;
		for(i = 1; i < dy; i++) {
			Geser(&current, 0, 1);
<<<<<<< HEAD
			if ((PlotUnit(Petak(M, current))) != Nil) {
=======
			if ((*PlotUnit(Petak(M, current))) != Nil) {
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
				pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
			}
		}
		for(i = 1; i < dx; i++) {
			Geser(&current, 1, 0);
<<<<<<< HEAD
			if ((PlotUnit(Petak(M, current))) != Nil) {
=======
			if ((*PlotUnit(Petak(M, current))) != Nil) {
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
				pathclear = pathclear && OwnerUnit(*PlotUnit(Petak(M, current))) == PlayerNo(*currPlayer);
			}
		}
	  }
<<<<<<< HEAD
  
	}
  
	return valid && pathclear;
=======
	  
  }
  
  return valid && pathclear;
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
}

void Move(Unit U)
{
  POINT dest;

  {
    printf("Please​ ​enter​ ​destination​ ​coordinate​ ​x​ ​y (example : 1 1 ) : \n");
    BacaPOINT(&dest);
    printf("\n");
    /* geser sejauh dx,dy */
    if (IsMoveValid(dest, U)){
		Push(CreateUnitMove(Position(U), &U));
<<<<<<< HEAD
		MovePoint(U) -= abs(Absis(dest)-Absis(Position(U)))+abs(Ordinat(dest)-Ordinat(Position(U)));
=======
		MovePoint(U) -= abs(Absis(dest)-Absis(U))+abs(Ordinat(dest)-Ordinat(U));
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
		Position(U) = dest;
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
	UnitMove Prev;
	Unit undoUnit;
	POINT posawal;
	int dist;
	
	/* Algoritma */
	Pop(&Prev);
	undoUnit = *MovedUnit(Prev);
	posawal = PrevPos(Prev);
<<<<<<< HEAD
	dist = abs(Absis(Position(undoUnit))-Absis(posawal))+abs(Ordinat(Position(undoUnit))-Ordinat(posawal));
=======
	dist = abs(Absis(undoUnit)-Absis(posawal))+abs(Ordinat(undoUnit)-Ordinat(posawal));
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
	MovePoint(undoUnit) += dist;
	Position(undoUnit) = posawal;
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


void recruit()
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
<<<<<<< HEAD
					U = CreateUnit(i, Absis(dest), Ordinat(dest), PlayerNo(*currPlayer));
					AddUnit(currPlayer, U);
					PlotUnit(Petak(M, dest)) = &U;
=======
					AddUnit(currPlayer, CreateUnit(i, Absis(dest), Ordinat(dest), PlayerNo(currPlayer)));
>>>>>>> 35b1a69d1f426c6b58bf86ef7124b5a166736a79
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

void attack();


boolean IsAdjacentEmpty(Unit U, boolean Enemy)
{
	/* KAMUS LOKAL */
	POINT P, P1, P2, P3, P4;
	
	/* ALGORITMA */
	P = Position(U);
	
	P1 = MakePOINT(Absis(P)-1,Ordinat(P)); //Kiri
	P2 = MakePOINT(Absis(P),Ordinat(P)+1); //Atas
	P3 = MakePOINT(Absis(P)+1,Ordinat(P)); //Kanan
	P4 = MakePOINT(Absis(P),Ordinat(P)-1); //Bawah
	
	if (!Enemy){
		return (!((IsPlotInMap(M, P1) && !IsPlotEmpty(M, P1) && OwnerUnit(*PlotUnit(Petak(M, P1))) != PlayerNo(*currPlayer)) ||
		(IsPlotInMap(M, P2) && !IsPlotEmpty(M, P2) && OwnerUnit(*PlotUnit(Petak(M, P2))) != PlayerNo(*currPlayer)) ||
		(IsPlotInMap(M, P3) && !IsPlotEmpty(M, P3) && OwnerUnit(*PlotUnit(Petak(M, P3))) != PlayerNo(*currPlayer)) ||
		(IsPlotInMap(M, P4) && !IsPlotEmpty(M, P4) && OwnerUnit(*PlotUnit(Petak(M, P4))) != PlayerNo(*currPlayer))));
	}
	else{
		return (!((IsPlotInMap(M, P1) && !IsPlotEmpty(M, P1) && OwnerUnit(*PlotUnit(Petak(M, P1))) == PlayerNo(*currPlayer)) ||
		(IsPlotInMap(M, P2) && !IsPlotEmpty(M, P2) && OwnerUnit(*PlotUnit(Petak(M, P2))) == PlayerNo(*currPlayer)) ||
		(IsPlotInMap(M, P3) && !IsPlotEmpty(M, P3) && OwnerUnit(*PlotUnit(Petak(M, P3))) == PlayerNo(*currPlayer)) ||
		(IsPlotInMap(M, P4) && !IsPlotEmpty(M, P4) && OwnerUnit(*PlotUnit(Petak(M, P4))) == PlayerNo(*currPlayer))));
	}
	
}
/* Menghasilkan True jika ada Unit untuk tipe Enemy di sekitar unit (Kiri/Atas/Kanan/Bawah) 
 * Mengecek keberadaan Musuh jika Enemy = true, dan sebaliknya */

void ShowAdjacentUnit(Unit U, boolean Enemy)
{
	/* KAMUS LOKAL */
	POINT P, P1, P2, P3, P4;
	
	/* ALGORITMA */
	P = Position(U);
	
	P1 = MakePOINT(Absis(P)-1,Ordinat(P)); //Kiri
	P2 = MakePOINT(Absis(P),Ordinat(P)+1); //Atas
	P3 = MakePOINT(Absis(P)+1,Ordinat(P)); //Kanan
	P4 = MakePOINT(Absis(P),Ordinat(P)-1); //Bawah
	
	
	if (Enemy) {
		if (IsAdjacentEmpty(U, Enemy)){
			printf("There are no enemies adjacent to selected Unit");
		}
		else{
			if (IsPlotInMap(M, P1) && !IsPlotEmpty(M, P1)){
			
			
}

/* Mencetak semua Unit yang jarak dengan Unit U = 1 
 * Menunjukan Unit musuh jika Enemy = true, dan sebaliknya */
void show_info()
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
				printf("Health %d | ATK %d", Health(*PlotUnit(Petak(M, P))), Atk(*PlotUnit(Petak(M, P))));
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

/*
void end_turn();
void save();

void next_unit();
*/

