#include "DArrayList.h"
#include <stdlib.h>
#define LIST_MAXLENGTH 10

void DinitList(DArrayList* list)//리스트를 새로만든다
{
	list->dataSet = (DListData**)malloc(sizeof(DListData*)*LIST_MAXLENGTH);
	list->length = 0;
}

void Dadd(DArrayList* list, DListData* data)//값을 집어넣은다
{
	list->dataSet[list->length] = data;
	list->length++;
}

DListData* Dget(DArrayList* list, int index)//주어진 index 매개변수 위치에 있는 객체로 리턴
{
	return list->dataSet[index];
}

void Dremove(DArrayList* list, int index)//목록에 있는것을 제거
{
	int i = 0;
	for (i = index; i < list->length - 1; i++)
	{
		list->dataSet[i] = list->dataSet[i + 1];
	}
	list->length--;
}

int DisEmpty(DArrayList* list)//목록이 비었는지 확인함 비었으면 1로 리턴 아니면 0으로 리턴
{
	if (list->length == 0)
		return 1;
	else
		return 0;

}

