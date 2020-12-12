#include "GameHelper.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void initGameHelper(GameHelper* gameHelper)
{
	int index = 0;
	gameHelper->gridLength = 7;//위치범위 x,y축
	gameHelper->gridSize = 49;//전체범위
	gameHelper->grid = (int*)malloc(sizeof(int)*(gameHelper->gridSize));//위치정보저장배열
	for (index = 0; index < gameHelper->gridSize; index++) 
	{
		gameHelper->grid[index] = 0;
	}
	
	gameHelper->comCount = 0;//닷컴의 입력순서 카운트
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
	int location = 0;//현제 시작위치
	
	gameHelper->comCount++;
	int incr = 1;//수평방향으로 증가시킬값 설정
	if ((gameHelper->comCount % 2) == 1)//홀수번째 닷컴인 경우 수직으로 배치
	{
		incr = gameHelper->gridLength;//수직방향으로 증가시킬값 설정(7 증가)
	}
	srand(time(NULL)); //seed 값
	while (!success & attempts++ < 200) //200번까지 시도하면서 위치정보저장
	{
		location = (int)(((double)rand() / RAND_MAX) * (gameHelper->gridSize));
		int x = 0;
		success = true;
		while (success && x < comSize)
		{
			if (gameHelper->grid[location] == 0)//위치정보배열의 Location번째값에 값이 없으면
			{
				coords[x++] = location;//위치배열에 Location저장
				location += incr;//Location에 incr값 플러스
				if (location >= gameHelper->gridSize)//만약 지정한위치가 지정범위보다크면
				{
					success = false;//위치재설정을위해 success를 false로
				}
				if (x > 0 & (location % gameHelper->gridLength == 0))
				{
					success = false;
				} //가로배치일때 좌표값이 넘어간경우 
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

		_itoa_s(row, tempString,2, 10); //int row를 문자열로 tempString에 저장

		strcat_s(temp, 3, tempString); //문자열 temp + tempString
		Sadd(alphaCells, temp);
		x++;
	}
	return alphaCells;
}

void UppertoLower(char* string)//A 부터 Z 까지 숫자에 32더해 소문자로 바꿈
{
	int index = 0;
	for (index = 0; index < strlen(string); index++)
	{
		if (string[index] >= 'A' && string[index] <= 'Z')
			string[index] = string[index] + 32;
	}
}