#ifndef DOTCOM_H
#define DOTCOM_H
#include <stdio.h>
#include <string.h>
#include "SArrayList.h"
#include<Windows.h>

typedef struct DotCom
{
	SArrayList* locationCells;
	char* name;
	char* pets;
	char* go;
	char* toy;

	int pp;
	int gg;
	int tt;
	int work;
}DotCom;

void initDotCom(DotCom* dotCom, int charicter);
void setLocationCells(DotCom* dotCom, SArrayList* loc);
void setName(DotCom* dotCom, char* n, int k);
char* checkYourself(DotCom* dotCom, char* userInput, int charicter);
#endif