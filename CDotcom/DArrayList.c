#include "DArrayList.h"
#include <stdlib.h>
#define LIST_MAXLENGTH 10

void DinitList(DArrayList* list)//����Ʈ�� ���θ����
{
	list->dataSet = (DListData**)malloc(sizeof(DListData*)*LIST_MAXLENGTH);
	list->length = 0;
}

void Dadd(DArrayList* list, DListData* data)//���� ���������
{
	list->dataSet[list->length] = data;
	list->length++;
}

DListData* Dget(DArrayList* list, int index)//�־��� index �Ű����� ��ġ�� �ִ� ��ü�� ����
{
	return list->dataSet[index];
}

void Dremove(DArrayList* list, int index)//��Ͽ� �ִ°��� ����
{
	int i = 0;
	for (i = index; i < list->length - 1; i++)
	{
		list->dataSet[i] = list->dataSet[i + 1];
	}
	list->length--;
}

int DisEmpty(DArrayList* list)//����� ������� Ȯ���� ������� 1�� ���� �ƴϸ� 0���� ����
{
	if (list->length == 0)
		return 1;
	else
		return 0;

}

