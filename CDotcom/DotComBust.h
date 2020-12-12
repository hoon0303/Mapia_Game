#ifndef DOTCOMBUST_H
#define DOTCOMBUST_H
#include <stdio.h>
#include <stdlib.h>
#include "GameHelper.h"
#include "DotCom.h"
#include "DArrayList.h"
#include <Windows.h>

typedef struct DotComBust {
	GameHelper* helper;
	DArrayList* dotComList;
	int numOfGuesses;
	int charicter;
}DotComBust;

typedef struct rank {
	char name[20];
	int numOfGuesses;
	int score;
	char sdate[32];
	char stime[32];
}rank;

void initDotComBust(DotComBust* dotComBust);
void setUpGame(DotComBust* dotComBust, int savenumber);
void startPlaying(DotComBust* dotComBust,int savenumber);
void checkUserGuess(DotComBust* dotComBust, char* userGuess);
void finishGame(DotComBust* dotComBust);
#endif DOTCOMBUST_H