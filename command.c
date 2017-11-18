/* Command */

#include "command.h"
#include "unit.h"
#include "map.h"
#include <stdio.h>
#include "point.h"
#include "stackMove.h"
#include "player.h"

extern Unit* SelectedUnit;
extern int CurrPlayer;

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
  int dx, dy;
  POINT current;
  boolean valid;
  
  /* ALGORITMA */
  current = Position(U);
  dx = Absis(current) - Absis(dest);
  dy = Ordinat(current) - Ordinat(dest);
  valid = ((dx + dy) <= MovePoint(U));
  
  if (valid) {
	  if(PlotUnit(Petak(M, dest)) != Nil){
		  valid = false;
	  }
  }
  
  return valid;
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
		Position(U) = dest;
    }
    else
    {
      printf("You can't move there\n");
    }
  }
}

boolean IsCastleFull()
{
	/* KAMUS LOKAL */
	boolean Full;
	POINT C1, C2, C3, C4;
	
	/* ALGORITMA */
	if(CurrPlayer == 1){
	/* Inisiasi untuk Player 1 */
		C1 = MakePOINT(GetLastIdxBrs(Peta(M)), GetFirstIdxKol(Peta(M))+1);
		C2 = MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M)));
		C3 = MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M)));
		C4 = MakePOINT(GetLastIdxBrs(Peta(M))-2, GetFirstIdxKol(Peta(M))+1);
	}
	if(CurrPlayer == 2){
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
						if(Owner(Petak(M, dest)) != CurrPlayer){
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
					AddUnit(currPlayer, CreateUnit(i, Absis(dest), Ordinat(dest)));
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

/*
void show_map()
{
  PrintMap();
}
* */


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

