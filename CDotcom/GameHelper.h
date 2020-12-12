#ifndef GAMEHELPER_H
#define GAMEHELPER_H

#include <stdio.h>
#include <stdlib.h>
#include "SArrayList.h"
#include <string.h>
static const char* alphabet = "abcdefg";//위치 지정변수

typedef struct GameHelper {
	int gridLength;
	int gridSize;
	int* grid;
	int comCount;
}GameHelper;

void initGameHelper(GameHelper* gameHelper);
char* getUserInput(GameHelper* gameHelper, char* prompt);
SArrayList* placeDotCom(GameHelper* gameHelper, int comSize, int savenumber);
void UppertoLower(char* string);
#endif