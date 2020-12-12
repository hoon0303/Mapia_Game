#ifndef DARRAYLIST_H
#define DARRAYLIST_H
#include "DotCom.h"

typedef DotCom DListData;

typedef struct DArrayList {
	DListData** dataSet;
	int length;
}DArrayList;

void DinitList(DArrayList* list);
void Dadd(DArrayList* list, DListData* data);
DListData* Dget(DArrayList* list, int index);
void Dremove(DArrayList* list, int index);
int DisEmpty(DArrayList* list);
#endif