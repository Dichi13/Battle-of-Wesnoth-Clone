/* Command */

#include "command.h"

boolean can_be_moved(int x, int y, MATRIKS M, Unit U);

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

void move(Unit U)
{
  int x,y,dx,dy;

  do
  {
    printf("Please​ ​enter​ ​cell’s​ ​coordinate​ ​x​ ​y: \n");
    scanf("%d %d", x,y);
    printf("\n");
    /* geser sejauh dx,dy */
    dx = x - Absis(Position(U));
    dy = y - Ordinat(Position(U));
    if (can_be_moved(x,y,M,U))
    {
      Push(&S,Position(U));
      MoveUnit(&U,dx,dy);
    }
    else
    {
      printf("You can't move there\n", );
    }
  }
  while (!can_be_moved(x,y,M,U));
}

void undo() /* adam fadhel */
void change_unit()
void recruit()
{
  if (strcmp(TypeName(U),"King") == 0)
  {

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
