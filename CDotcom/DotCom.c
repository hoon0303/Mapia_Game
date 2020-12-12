#include "DotCom.h"

void initDotCom(DotCom* dotCom,int charicter)
{
	if (charicter == 0)
	{
		dotCom->pets = "마피아";
		dotCom->go = "짐승인간";
		dotCom->toy = "스파이";
	}
	else
	{
		dotCom->pets = "경찰";
		dotCom->go = "의사";
		dotCom->toy = "정치인";
	}

	dotCom->pp = 0;
	dotCom->gg = 0;
	dotCom->tt = 0;
}

void setLocationCells(DotCom* dotCom, SArrayList* loc)
{
	dotCom->locationCells = loc;
}

void setName(DotCom* dotcom, char* n, int k)
{
	dotcom->name = n;
	dotcom->work = k;
}

char* checkYourself(DotCom* dotCom, char* userInput, int charicter)//입력한 값이랑 같은지 확인하는 부분
{
	char* status = "miss";
	char* savename;
	int index = SindexOf(dotCom->locationCells, userInput);//사용자가 입력한 값이 arraylist에 있는지 확인
	if (index >= 0)
	{
		FILE* killdata;
		fopen_s(&killdata, "killdata.txt", "at");
		fprintf(killdata,"%s ", userInput);
		fclose(killdata);
		Sremove(dotCom->locationCells , index);//index가 0이상이면 사용자가 추측좌표를 맞췄으므로 목록에서 제거
		if (SisEmpty(dotCom->locationCells))
			status = "kill";
		if (charicter == 0)
		{
			if (dotCom->work == 1)
				savename = "마피아";
			else if (dotCom->work == 2)
				savename = "짐승인간";
			else
				savename = "스파이";
		}
		else
		{
			if (dotCom->work == 1)
				savename = "경찰";
			else if (dotCom->work == 2)
				savename = "의사";
			else
				savename = "정치인";
		}
		printf("You Found [%s] +o+\n", savename);
		if (!strcmp(dotCom->pets, dotCom->name))
		{
			if (dotCom->pp < 2)
			{
				printf("hit\n");
				dotCom->pp++;
			}
			else
			{
				printf("kill\n");
			}
		}
		if (!strcmp(dotCom->go, dotCom->name))
		{
			if (dotCom->gg < 2)
			{
				printf("hit\n");
				dotCom->gg++;
			}
			else
			{
				printf("kill\n");
			}
		}
		if (!strcmp(dotCom->toy, dotCom->name))
		{
			if (dotCom->tt < 2)
			{
				printf("hit\n");
				dotCom->tt++;
			}
			else
			{
				printf("kill\n");
			}
		}
		Sleep(1000);
	}
	else
	{
		status = "Hit";
	}
	return status;
}
