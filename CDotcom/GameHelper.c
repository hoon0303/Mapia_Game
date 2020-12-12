#include "GameHelper.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void initGameHelper(GameHelper* gameHelper)
{
	int index = 0;
	gameHelper->gridLength = 7;//��ġ���� x,y��
	gameHelper->gridSize = 49;//��ü����
	gameHelper->grid = (int*)malloc(sizeof(int)*(gameHelper->gridSize));//��ġ��������迭
	for (index = 0; index < gameHelper->gridSize; index++) 
	{
		gameHelper->grid[index] = 0;
	}
	
	gameHelper->comCount = 0;//������ �Է¼��� ī��Ʈ
}

char* getUserInput(GameHelper* gameHelper, char* prompt)
{
	char inputLine[5];
	char* temp;
	printf("%s ", prompt);
	
	inputLine[0] = getche();
	inputLine[1] = getche();
	inputLine[2] = '\0';
	printf("\n");
	if (strlen(inputLine) == 0)
		return NULL;

	UppertoLower(inputLine);
	temp = (char*)malloc(sizeof(inputLine) + 1);
	strcpy_s(temp, sizeof(inputLine)+1, inputLine);

	return temp;
}

SArrayList* placeDotCom(GameHelper* gameHelper, int comSize)
{
	SArrayList* alphaCells = (SArrayList*)malloc(sizeof(SArrayList));
	SinitList(alphaCells);
	char* temp;
	
	int* coords = (int*)malloc(sizeof(int)*comSize);
	int attempts = 0;
	bool success = false;
	int location = 0;//���� ������ġ
	
	gameHelper->comCount++;
	int incr = 1;//����������� ������ų�� ����
	if ((gameHelper->comCount % 2) == 1)//Ȧ����° ������ ��� �������� ��ġ
	{
		incr = gameHelper->gridLength;//������������ ������ų�� ����(7 ����)
	}
	srand(time(NULL)); //seed ��
	while (!success & attempts++ < 200) //200������ �õ��ϸ鼭 ��ġ��������
	{
		location = (int)(((double)rand() / RAND_MAX) * (gameHelper->gridSize));
		int x = 0;
		success = true;
		while (success && x < comSize)
		{
			if (gameHelper->grid[location] == 0)//��ġ�����迭�� Location��°���� ���� ������
			{
				coords[x++] = location;//��ġ�迭�� Location����
				location += incr;//Location�� incr�� �÷���
				if (location >= gameHelper->gridSize)//���� ��������ġ�� ������������ũ��
				{
					success = false;//��ġ�缳�������� success�� false��
				}
				if (x > 0 & (location % gameHelper->gridLength == 0))
				{
					success = false;
				} //���ι�ġ�϶� ��ǥ���� �Ѿ��� 
			}
			else
			{
				success = false;
			}
		}
	}

	int x = 0;
	int row = 0;
	int column = 0;

	while (x < comSize)
	{
		temp = (char*)malloc(3);
		gameHelper->grid[coords[x]] = 1;
		row = (int)(coords[x] / gameHelper->gridLength);
		column = coords[x] % gameHelper->gridLength;
		temp[0] = alphabet[column];
		temp[1] = '\0';

		char* tempString = (char*)malloc(2);

		_itoa_s(row, tempString,2, 10); //int row�� ���ڿ��� tempString�� ����

		strcat_s(temp, 3, tempString); //���ڿ� temp + tempString
		Sadd(alphaCells, temp);
		x++;
	}
	return alphaCells;
}

void UppertoLower(char* string)//A ���� Z ���� ���ڿ� 32���� �ҹ��ڷ� �ٲ�
{
	int index = 0;
	for (index = 0; index < strlen(string); index++)
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] = string[index] + 32;
	}
}