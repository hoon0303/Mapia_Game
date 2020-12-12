#ifndef SARRAYLIST_H
#define SARRAYLIST_H

typedef char* SListData;

typedef struct SArrayList {
	SListData** dataSet;
	int length;
}SArrayList;

void SinitList(SArrayList* list);
void Sadd(SArrayList* list, SListData* data);
SListData* Sget(SArrayList* list, int index);
void Sremove(SArrayList* list, int index);
int SisEmpty(SArrayList* list);
int SindexOf(SArrayList* list, char* userInput);
#endif
