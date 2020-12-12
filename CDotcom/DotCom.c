#include "DotCom.h"

void initDotCom(DotCom* dotCom,int charicter)
{
	if (charicter == 0)
	{
		dotCom->pets = "���Ǿ�";
		dotCom->go = "�����ΰ�";
		dotCom->toy = "������";
	}
	else
	{
		dotCom->pets = "����";
		dotCom->go = "�ǻ�";
		dotCom->toy = "��ġ��";
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

char* checkYourself(DotCom* dotCom, char* userInput, int charicter)//�Է��� ���̶� ������ Ȯ���ϴ� �κ�
{
	char* status = "miss";
	char* savename;
	int index = SindexOf(dotCom->locationCells, userInput);//����ڰ� �Է��� ���� arraylist�� �ִ��� Ȯ��
	if (index >= 0)
	{
		FILE* killdata;
		fopen_s(&killdata, "killdata.txt", "at");
		fprintf(killdata,"%s ", userInput);
		fclose(killdata);
		Sremove(dotCom->locationCells , index);//index�� 0�̻��̸� ����ڰ� ������ǥ�� �������Ƿ� ��Ͽ��� ����
		if (SisEmpty(dotCom->locationCells))
			status = "kill";
		if (charicter == 0)
		{
			if (dotCom->work == 1)
				savename = "���Ǿ�";
			else if (dotCom->work == 2)
				savename = "�����ΰ�";
			else
				savename = "������";
		}
		else
		{
			if (dotCom->work == 1)
				savename = "����";
			else if (dotCom->work == 2)
				savename = "�ǻ�";
			else
				savename = "��ġ��";
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
