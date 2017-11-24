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
	Unit U;
	
	/* ALGORITMA */
	EndGame = false;
	/* Inisialisasi Tipe Unit */
	InitUnitTypeList();
	
	/* Pemilihan NEW GAME/LOAD GAME */
	do{
		PrintTitle();
		printf("WOULD YOU LIKE TO START YOUR JOURNEY ANEW OR LOAD A GAME?");
		printf("1. NEW GAME\n");
		printf("2. LOAD GAME\n");
		scanf("%d ", &IntSelection);
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
			if (NB < 3 || NK < 3 || !IsIdxValid(NB, NK)){
				printf("Please enter a value >3 and <= 100\n");
			}
		}
		while (NB < 3 || NK < 3 || !IsIdxValid(NB, NK));
		
		InitMap(NB, NK);
		
		/* Inisialisasi Player */
		AddQueue(&PlayerTurns, CreatePlayer(1));
		U = CreateUnit(0, MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M))+1), 1);
		SetUnit(MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M))+1), &U);
		AddUnit(SearchPlayer(1), U);
		
		AddQueue(&PlayerTurns, CreatePlayer(2));
		U = CreateUnit(0, MakePOINT(GetFirstIdxBrs(Peta(M))+1, GetLastIdxKol(Peta(M))-1), 2);
		SetUnit(MakePOINT(GetLastIdxBrs(Peta(M))-1, GetFirstIdxKol(Peta(M))+1), &U);
		AddUnit(SearchPlayer(2), U);
	}
	else{
		/* FUNGSI LOAD GAME */
	}
	
	/* Mulai Game */
	PrintMap();
	SelectedUnit = Nil;
	currPlayer = SearchPlayer(1);
	do{
		printf("\nPlayer %d's Turn\n", PlayerNo(*currPlayer));
		printf("Money : %dG | Income : %dG | Upkeep : %dG", Gold(*currPlayer), Income(*currPlayer), Upkeep(*currPlayer));
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
		
		scanf(" %s", StringSelection);
		
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
			/* FUNGSI CHANGE UNIT */
			/* FUNGSI CLEAR STACK*/
		}
		else if(StrSama(StringSelection, "NEXT_UNIT")){
			/* FUNGSI NEXT_UNIT */
			/* FUNGSI CLEAR STACK*/
		}
		if(StrSama(StringSelection, "RECRUIT")){
			Recruit();
			/* FUNGSI CLEAR STACK */
		}
		if(StrSama(StringSelection, "ATTACK")){
			if(SelectedUnit == Nil){
				printf("You have not selected a unit\n");
			}
			else{
				Attack();
			}
			/* FUNGSI CLEAR STACK*/
		}
		if(StrSama(StringSelection, "MAP")){
			PrintMap();
		}
		if(StrSama(StringSelection, "INFO")){
			InfoPetak();
		}
		if(StrSama(StringSelection, "END_TURN")){
			ChangeTurns();
			/* FUNGSI CLEAR STACK */
		}
		if(StrSama(StringSelection, "SAVE")){
			/* FUNGSI SAVE */
		}
		if(StrSama(StringSelection, "EXIT")){
		}
		else{
			printf("Please enter a valid input\n");
		}
	}
	while(!StrSama(StringSelection, "EXIT") && !(EndGame));
	
	if(EndGame){
		/* Pesan Game Selesai */
	}
	
	printf("\nThanks for playing the game!\n");
	printf("Please play again!\n");
		
	
	return 0;
}
