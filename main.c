#include "includeeverything.h"

void PrintTitle () {
	printf("           W  E  L  C  O  M  E   T  O\n");
	printf("            ____        __  __  __   \n");
	printf("           / __ )____ _/ /_/ /_/ /__ \n");
	printf("          / __  / __ `/ __/ __/ / _ \\ \n");
	printf("         / /_/ / /_/ / /_/ /_/ /  __/\n");
	printf("        /_____/\\__,_/\\__/\\__/_/\\___/ \n");
	printf("                       ____\n");
	printf("                ____  / __/\n");
	printf("               / __ \\/ /_  \n");
	printf("              / /_/ / __/  \n");
	printf("              \\____/_/     \n");
	printf("   ____  ____  ____  _______  _______ \n");
	printf("  / __ \\/ /\\ \\/ /  |/  / __ \\/  _/   |\n");
	printf(" / / / / /  \\  / /|_/ / /_/ // // /| |\n");
	printf("/ /_/ / /___/ / /  / / ____// // ___ |\n");
	printf("\\____/_____/_/_/  /_/_/   /___/_/  |_|\n");
}

int main()
{
	/* KAMUS */
	char StringSelection[50];
	int IntSelection;
	int NB, NK;
	Unit K1, K2;
	
	/* ALGORITMA */
	EndGame = false;
	/* Inisialisasi Tipe Unit */
	InitUnitTypeList();
	
	/* Pemilihan NEW GAME/LOAD GAME */
	do{
		PrintTitle();
		printf("WOULD YOU LIKE TO START YOUR JOURNEY ANEW OR LOAD A GAME?\n");
		printf("1. NEW GAME\n");
		printf("2. LOAD GAME\n");
		printf("Your input : ");
		scanf("%d", &IntSelection);
		if((IntSelection != 1) && (IntSelection != 2)){
			printf("Please choose valid option\n");
		}
	}
	while((IntSelection != 1) && (IntSelection != 2));
	
	if (IntSelection == 1){
		/* Inisialisasi Map */
		do{
			printf("Insert map size x y : ");
			scanf("%d %d", &NB, &NK);
			if (NB < 8 || NK < 8 || !IsIdxValid(NB, NK)){
				printf("Please enter a value >8 and <= 100\n");
			}
		}
		while (NB < 8 || NK < 8 || !IsIdxValid(NB, NK));
		
		InitMap(NB, NK);
		
		/* Inisialisasi Player */
		CreateEmptyQueue(&PlayerTurns, 10);
		
		AddQueue(&PlayerTurns, CreatePlayer(1));
		K1 = CreateUnit(0, TowerCoordinate(1), 1);
		AddUnit(SearchPlayer(1), K1);
		
		AddQueue(&PlayerTurns, CreatePlayer(2));
		K2 = CreateUnit(0, TowerCoordinate(2), 2);
		AddUnit(SearchPlayer(2), K2);
		
	}
	else{
		/* FUNGSI LOAD GAME */
	}
	/* Mulai Game */
	CreateEmptyStack();
	SelectedUnit = Nil;
	currPlayer = SearchPlayer(1);
	ChangeTurns();
	
	do{
		printf("Insert starting player : ");
		scanf("%d", &IntSelection);
		if(IntSelection == 1){
			ChangeTurns();
		}
		else if (IntSelection != 2){
			printf("Please enter a valid player number\n");
		}
	}while ((IntSelection != 1) && (IntSelection != 2));
	PrintMap();
	do{
		printf("\nPlayer %d's Turn\n", PlayerNo(*currPlayer));
		PrintInfoPlayer(*currPlayer);
		if (SelectedUnit != Nil){
			printf("Unit : %s (%d,%d) | Health %d/%d | Movement Point(s) : %d | ", TypeName(*SelectedUnit), Absis(Position(*SelectedUnit)), Ordinat(Position(*SelectedUnit)), Health(*SelectedUnit), MaxHP(*SelectedUnit), MovePoint(*SelectedUnit));
			if (CanAtk(*SelectedUnit)){
				printf("Can Attack\n");
			}
			else{
				printf("Can Not Attack\n");
			}
		}
		else{
			printf("You have not selected a unit.\n");
		}
		printf("\n");
		
		printf("Your input : ");
		scanf(" %s", StringSelection);
		printf("\n");
		
		if(StrSama(StringSelection, "MOVE")){
			if(SelectedUnit == Nil){
				printf("You have not selected a unit\n");
			}
			else{
				Move();
			}
		}
		else if(StrSama(StringSelection, "UNDO")){
			if (IsEmptyStack()){
				printf("Your selected Unit has not moved\n");
			}
			else{
				Undo();
			}
		}
		else if(StrSama(StringSelection, "CHANGE_UNIT")){
			ChangeUnit();
			CreateEmptyStack();
		}
		else if(StrSama(StringSelection, "NEXT_UNIT")){
			NextSelect();
			CreateEmptyStack();
		}
		else if(StrSama(StringSelection, "RECRUIT")){
			if(SelectedUnit == Nil){
				printf("You have not selected a unit\n");
			}
			else{
				Recruit();
				CreateEmptyStack();
			}
		}
		else if(StrSama(StringSelection, "ATTACK")){
			if(SelectedUnit == Nil){
				printf("You have not selected a unit\n");
			}
			else{
				Attack();
			}
			CreateEmptyStack();
		}
		else if(StrSama(StringSelection, "INFO")){
			InfoPetak();
		}
		else if(StrSama(StringSelection, "MAP")){
			PrintMap();
		}
		else if(StrSama(StringSelection, "END_TURN")){
			ChangeTurns();
			CreateEmptyStack();
		}
		else if(StrSama(StringSelection, "SAVE")){
			/* FUNGSI SAVE */
		}
		else if(StrSama(StringSelection, "EXIT")){
		}
		else{
			printf("Please enter a valid input\n");
		}
	}
	while(!StrSama(StringSelection, "EXIT") && !(EndGame));
	
	if(EndGame){
		printf("\n");
		PrintMap();
		printf("\nThe battle has come to an end...\n");
		printf("\nPlayer %d wins!!\n", Winner);
	}
	
	printf("\nThanks for playing the game!\n");
	printf("Please play again!\n");
		
	
	return 0;
}
