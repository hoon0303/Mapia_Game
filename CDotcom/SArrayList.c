#include "SArrayList.h"
#include <stdlib.h>
#include <string.h>
#define LIST_MAXLENGTH 10

void SinitList(SArrayList* list)//����Ʈ�� ���θ����
{
	list->dataSet = (SListData**)malloc(sizeof(SListData*)*LIST_MAXLENGTH);
	list->length = 0;
}

void Sadd(SArrayList* list, SListData* data)//���� ���������
{
	list->dataSet[list->length] = data;
	list->length++;
}

SListData* Sget(SArrayList* list, int index)//�־��� index �Ű����� ��ġ�� �ִ� ��ü�� ����
{
	return list->dataSet[index];
}

void Sremove(SArrayList* list, int index)//��Ͽ� �ִ°��� ����
{
	int i = 0;
	for (i = index; i < list->length - 1; i++)
	{
		list->dataSet[i] = list->dataSet[i + 1];
	}
	list->length--;
}

int SisEmpty(SArrayList* list)//����� ������� Ȯ���� ������� 1�� ���� �ƴϸ� 0���� ����
{
	if (list->length == 0)
		return 1;
	else
		return 0;

}

int SindexOf(SArrayList* list, char* userInput)//�ε����� ã�Ƴ���
{
	int index = 0;
	for (index = 0; index < list->length; index++)
	{
		if (0 == strcmp(list->dataSet[index], userInput))
			return index;
	}

	return -1;
}