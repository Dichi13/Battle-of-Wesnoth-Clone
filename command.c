/* Command */

#include "command.h"
#include "unit.h"
#include "map.h"
#include <stdio.h>
#include "point.h"
#include "stackMove.h"
#include "player.h"

extern Unit* SelectedUnit;

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

boolean can_call_recruit_comm() {
	boolean temp, adakosong;
	POINT P = Position(*SelectedUnit);
	temp = strcmp(TypeName(*SelectedUnit),"King") == 0 && PlotType(Petak(M, P)) == 'T';
	adakosong = false;
	Geser(&P, 0, 1);
	adakosong ||= IsPlotEmpty(M,P);
	Geser(&P, 0, -2);
	adakosong ||= IsPlotEmpty(M,P);
	Geser(&P, 1, 1);
	adakosong ||= IsPlotEmpty(M,P);
	Geser(&P, -2, 0);
	adakosong ||= IsPlotEmpty(M,P);

	return temp && adakosong;
}

void recruit()   // asumsi: ada global variabel Unit* SelectedUnit dan Player* currPlayer, ada primitif AddUnit di ADT player
{
  if (can_call_recruit_comm())
  {
	POINT P;
	int i;
	
	do {
		printf("Enter the coordinate for recruitment : ");
		scanf("%d %d", &Absis(P), &Ordinat(P));
		if (!(IsPlotEmpty(M, P) && PlotType(Petak(M,P)) == 'C')) {
			printf("That castle is occupied!\n");
		}
	}while (!(IsPlotEmpty(M, P) && PlotType(Petak(M,P)) == 'C'));
	printf("========== List of recruitable units ==========\n");
	for (i = 1; i<NbUnitType; i++) {
		printf("%d. %s | Health %d | ATK %d | Cost %dG\n", i, TypeList[i].TypeName, TypeList[i].MaxHP, TypeList[i].Atk, TypeList[i].Cost);
	}
	printf("Enter the index of the unit you want to recruit :");
	scanf("%d", &i);
	if (Gold(*currPlayer) >= TypeList[i].Cost) {
		Gold(*currPlayer) -= TypeList[i].Cost;
		AddUnit(CreateUnit(i, Absis(P), Ordinat(P)), *currPlayer);
	} else {
		printf("You don't have enough gold to recruit that unit!\n");
	}
	
  } else {
	  printf("Only King on a Tower plot with at least one adjacent empty castle can recruit more units!\n");
  }
}
void attack();
void show_map()
{
  PrintMap();
}
void show_info()
{
  do
  {
    printf("Please​ ​enter​ ​cell’s​ ​coordinate​ ​x​ ​y: \n");
    scanf("%d %d", x,y);
    printf("\n");
    if (((x >= 0) && (x < MNBrsEff(M))) && ((y >= 0) && (y < MNKolEff(M))))
    {
      printf("==​ ​Cell​ ​Info​ ​==\n");
      print_jenis_petak(P);
      printf("Owned by Player %d\n", Owner(P));

      printf("==​ ​Unit​ ​Info​ ​==\n");
      printf("%s\n", TypeName(U));
      printf("Health %s | ATK %d | DEF %d ", Health(U), Atk(U), Def(U));
    }
    else
    {
      printf("Your input doesn't exist, please try again \n", );
    }
  }
  while (!can_be_moved(x,y,M,U));
}
void end_turn();
void save();

void next_unit();

/* BANTUAN */
boolean can_be_moved(int x, int y, MATRIKS M, Unit U)
{
  int dx = x - Absis(Position(U));
  int dy = y - Ordinat(Position(U));
  if ((x >= 0) && (x < MNBrsEff(M))) && ((y >= 0) && (y < MNKolEff(M))) && (dx + dy <= MovePoint(U))
  {
    if ()
    {
      /* cek enemy */
    }
  }
}

print_jenis_petak(Plot P)
{

}
