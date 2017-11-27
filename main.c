#include "includeeverything.h"
#include "jam.h"
#include <time.h>

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

void Save()
{
	/* KAMUS LOKAL */
	FILE *f;
	char filename[100];
	addressPoint V;
	addressUnit U;
	int i, j;
	POINT P;
	

	/* ALGORITMA */	
	printf("Masukan nama file : ");
	scanf(" %s", filename);
	
	f = fopen(filename, "w");
	
	
	/* State MAP */
	fprintf(f, "Map \n");
	fprintf(f, "%d %d \n", MNBrsEff(M), MNKolEff(M));
	
	fprintf(f, "Village \n");
	for(i = 1; i <= MNBrsEff(M); i++){
		for(j = 1; j <= MNKolEff(M); j++){
			P = MakePOINT(i, j);
			if (PlotType(Petak(M, P)) == 'V'){
				fprintf(f, "%d %d \n", Absis(P), Ordinat(P));
			}
		}
	}
	
	/* State Player yang sedang dalam turnnya */
	fprintf(f, "Player \n");
	fprintf(f, "%d %d %d %d \n", PlayerNo(InfoHead(PlayerTurns)), Gold(InfoHead(PlayerTurns)), Income(InfoHead(PlayerTurns)), Upkeep(InfoHead(PlayerTurns)));
	fprintf(f, "Unit \n");
	U = FirstUnit(ListUnit(InfoHead(PlayerTurns)));
	while (U != Nil){
		fprintf(f, "%d %d %d %d %d %d %d \n", TypeID(InfoUnit(U)), OwnerUnit(InfoUnit(U)), Health(InfoUnit(U)), MovePoint(InfoUnit(U)), CanAtk(InfoUnit(U)), Absis(Position(InfoUnit(U))), Ordinat(Position(InfoUnit(U))));
		U = NextUnit(U);
	}
	
	fprintf(f, "Village \n");
	V = FirstVillage(ListVillage(InfoHead(PlayerTurns)));
	while(V != Nil){
		fprintf(f, "%d %d \n", Absis(InfoVillage(V)), Ordinat(InfoVillage(V)));
		V = NextVillage(V);
	}
	
	/* State Player yang lain */
	fprintf(f, "Player \n");
	fprintf(f, "%d %d %d %d \n", PlayerNo(InfoTail(PlayerTurns)), Gold(InfoTail(PlayerTurns)), Income(InfoTail(PlayerTurns)), Upkeep(InfoTail(PlayerTurns)));
	fprintf(f, "Unit \n");
	U = FirstUnit(ListUnit(InfoTail(PlayerTurns)));
	while (U != Nil){
		fprintf(f, "%d %d %d %d %d %d %d \n", TypeID(InfoUnit(U)), OwnerUnit(InfoUnit(U)), Health(InfoUnit(U)), MovePoint(InfoUnit(U)), CanAtk(InfoUnit(U)), Absis(Position(InfoUnit(U))), Ordinat(Position(InfoUnit(U))));
		U = NextUnit(U);
	}
	
	fprintf(f, "Village \n");
	V = FirstVillage(ListVillage(InfoTail(PlayerTurns)));
	while(V != Nil){
		fprintf(f, "%d %d \n", Absis(InfoVillage(V)), Ordinat(InfoVillage(V)));
		V = NextVillage(V);
	}
	
	fprintf(f, "END \n");
	fprintf(f, ".");
	
	fclose(f);	
}


void Load()
{
	/* KAMUS LOKAL */
	char filename[100];
	int NB, NK;
	int X, Y;
	POINT P;
	int No, Gold, Income, Upkeep;
	Player PL;
	int Idx, Owner, Health, Move, Action;
	Unit U;
	char *Isi;
	
	/* ALGORITMA */
	printf("Masukan nama file : ");
	scanf(" %s", filename);
	
	STARTKATA(filename);
	ADVKATA();
	/* Ukuran Map */
	NB = KataInt(CKata);
	ADVKATA();
	NK = KataInt(CKata);
	ADVKATA();
	
	MakeEmptyMap(NB, NK);
	MakeNormalPlot();
	MakePlayerPlot();
	
	ADVKATA();
	Isi = KataStr(CKata);
	/* Pembacaan Village */
	while (!StrSama(Isi, "Player")){
		X = KataInt(CKata);
		ADVKATA();
		Y = KataInt(CKata);
		ADVKATA();
		P = MakePOINT(X, Y);
		
		Isi = KataStr(CKata);
		SetPlot(P, 'V', 0);
	}
	
	/* Pembacaan Player Pertama */
	ADVKATA();
	No = KataInt(CKata);
	ADVKATA();
	Gold = KataInt(CKata);
	ADVKATA();
	Income = KataInt(CKata);
	ADVKATA();
	Upkeep = KataInt(CKata);
	ADVKATA();
	PL = CreatePlayer(No);
	
	Gold(PL) = Gold;
	Income(PL) = Income;
	Upkeep(PL) = Upkeep;
	
	
	ADVKATA();
	Isi = KataStr(CKata);
	
	while (!StrSama(Isi, "Village")){
		Idx = KataInt(CKata);
		ADVKATA();
		Owner = KataInt(CKata);
		ADVKATA();
		Health = KataInt(CKata);
		ADVKATA();
		Move = KataInt(CKata);
		ADVKATA();
		Action = KataInt(CKata);
		ADVKATA();
		X = KataInt(CKata);
		ADVKATA();
		Y = KataInt(CKata);
		ADVKATA();
		P = MakePOINT(X, Y);
		Isi = KataStr(CKata);
		
		U = CreateUnit(Idx, P, Owner);
		Health(U) = Health;
		MovePoint(U) = Move;
		CanAtk(U) = Action;
		
		AddUnit(&PL, U);
	}
	
	ADVKATA();
	Isi = KataStr(CKata);
	while (!StrSama(Isi, "Player")){
		X = KataInt(CKata);
		ADVKATA();
		Y = KataInt(CKata);
		ADVKATA();
		P = MakePOINT(X, Y);
		Isi = KataStr(CKata);
		
		
		AddVillage(&PL, P);
		SetPlot(P, 'V', PlayerNo(PL));
	}
	
	AddQueue(&PlayerTurns, PL);
	/* Pembacaan Player Kedua */
	ADVKATA();
	No = KataInt(CKata);
	ADVKATA();
	Gold = KataInt(CKata);
	ADVKATA();
	Income = KataInt(CKata);
	ADVKATA();
	Upkeep = KataInt(CKata);
	ADVKATA();
	PL = CreatePlayer(No);
	
	Gold(PL) = Gold;
	Income(PL) = Income;
	Upkeep(PL) = Upkeep;
	ADVKATA();
	Isi = KataStr(CKata);
	
	
	while (!StrSama(Isi, "Village")){
		Idx = KataInt(CKata);
		ADVKATA();
		Owner = KataInt(CKata);
		ADVKATA();
		Health = KataInt(CKata);
		ADVKATA();
		Move = KataInt(CKata);
		ADVKATA();
		Action = KataInt(CKata);
		ADVKATA();
		X = KataInt(CKata);
		ADVKATA();
		Y = KataInt(CKata);
		ADVKATA();
		P = MakePOINT(X, Y);
		Isi = KataStr(CKata);
		
		U = CreateUnit(Idx, P, Owner);
		Health(U) = Health;
		MovePoint(U) = Move;
		CanAtk(U) = Action;
		
		AddUnit(&PL, U);
	}
	
	ADVKATA();
	Isi = KataStr(CKata);
	while ((!EndKata) && (!StrSama(Isi, "END"))){
		X = KataInt(CKata);
		ADVKATA();
		Y = KataInt(CKata);
		ADVKATA();
		Isi = KataStr(CKata);
		
		P = MakePOINT(X, Y);
		AddVillage(&PL, P);
		SetPlot(P, 'V', PlayerNo(PL));
	}
	AddQueue(&PlayerTurns, PL);
	currPlayer = SearchPlayer(PlayerNo(InfoHead(PlayerTurns)));
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
		
		CreateEmptyStack();
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
	}
	else{
		CreateEmptyQueue(&PlayerTurns, 10);
		Load();
	}
	/* Mulai Game */
	SelectedUnit = Nil;
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
				/* Mengubah CanAtk menjadi false jika tidak ada unit musuh disekitar agar pemilihan NEXT_UNIT lebibh berguna */
				if ((MovePoint(*SelectedUnit) == 0) && (IsAdjacentEmpty(*SelectedUnit, true))){
					CanAtk(*SelectedUnit) = false;
				}
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
			Save();
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
