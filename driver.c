
#include "unit.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	Unit U;
	//~ TypeList = (UnitType *) malloc(sizeof(UnitType));
	//~ NbUnitType = 1;
	//~ TypeList[0] = {"king", 
	InitUnitTypeList();
	printf("test1driver\n");
		
	U = CreateUnit(0, 0, 0);
	
	printf("test2driver\n");
		
	printf("%s\n", TypeName(U));
	printf("test3driver\n");
	
	
	MoveUnit(&U, 1, 2);
	printf("test4driver\n");
	
	
	TulisPOINT(Position(U));printf("\n");
	return 0;
}

