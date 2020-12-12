#include "DotComBust.h"

void initDotComBust(DotComBust* dotComBust)
{
	dotComBust->helper = (GameHelper*)malloc(sizeof(GameHelper));
	initGameHelper(dotComBust->helper);
	dotComBust->dotComList = (DArrayList*)malloc(sizeof(DArrayList));
	DinitList(dotComBust->dotComList);
	dotComBust->numOfGuesses = 0;//����ü�� ����Ͽ� ������ ����� �ʱ�ȭ
}

void setUpGame(DotComBust* dotComBust, int savenumber)//���� ������ ����� ��ġ����
{
	int index;
	char*work;
	if (savenumber == 1)
	{
		FILE*wf;
		fopen_s(&wf, "savedata.txt", "rt");
		fscanf_s(wf, "%d ", &dotComBust->charicter);
		fclose(wf);
	}

	if (savenumber != 1)
	{
		srand(time(NULL));
		dotComBust->charicter = rand() % 2;
		printf("����� ������ �����ϰڽ��ϴ�");
		printf("."); Sleep(500); printf("."); Sleep(500); printf(".\n"); Sleep(1000);
		system("cls");
	
	}
	if (dotComBust->charicter == 0)
		work = "����";
	else
		work = "���Ǿ�";
	printf("����� ������ %s�Դϴ�.\n", work);
	DotCom* one = (DotCom*)malloc(sizeof(DotCom));
	DotCom* two = (DotCom*)malloc(sizeof(DotCom));
	DotCom* three = (DotCom*)malloc(sizeof(DotCom));
	initDotCom(one, dotComBust->charicter);
	initDotCom(two, dotComBust->charicter);
	initDotCom(three, dotComBust->charicter);
	if (dotComBust->charicter == 0)
	{
		setName(one, "���Ǿ�",1);
		setName(two, "�����ΰ�",2);
		setName(three, "������",3);
	}
	else
	{
		setName(one, "����",1);
		setName(two, "�ǻ�",2);
		setName(three, "��ġ��",3);
	}
	Dadd(dotComBust->dotComList, one);
	Dadd(dotComBust->dotComList, two);
	Dadd(dotComBust->dotComList, three);//���� ���� 3���� ������� darraylist����

		

	

	for (index = 0; index < dotComBust->dotComList->length; index++)
	{
		SArrayList* newLocation = placeDotCom(dotComBust->helper, 3,savenumber);
		setLocationCells(Dget(dotComBust->dotComList,index), newLocation);//DotCom ������ ��ǥ�� ����
	}
}

void startPlaying(DotComBust* dotComBust,int savenumber)
{
	if (savenumber == 1)
	{
		char result[3] ;
		FILE*qp;
		fopen_s(&qp, "savedata.txt", "rt");
		fscanf_s(qp, "%d ", &dotComBust->charicter);
		fscanf_s(qp, "%d ", &dotComBust->dotComList->length);
		int i, k;
		for (i = 0; i < dotComBust->dotComList->length; i++)
		{
			fscanf_s(qp, "%d ", &dotComBust->dotComList->dataSet[i]->work);//������
			fscanf_s(qp, "%d %d %d ", &dotComBust->dotComList->dataSet[i]->pp, &dotComBust->dotComList->dataSet[i]->gg, &dotComBust->dotComList->dataSet[i]->tt);
			fscanf_s(qp, "%d ", &dotComBust->dotComList->dataSet[i]->locationCells->length);
	
			for (k = 0; k < dotComBust->dotComList->dataSet[i]->locationCells->length; k++)
			{
				fscanf_s(qp, "%s ", &result,sizeof(result));
				strcpy_s(dotComBust->dotComList->dataSet[i]->locationCells->dataSet[k], sizeof(result) + 1, result);
			}
			
		}
		fscanf_s(qp, "%d ", &dotComBust->numOfGuesses);
		fclose(qp);
	}
	while (!DisEmpty(dotComBust->dotComList))
	{
		 printf("����� ��ǥ�� 3���� ����\n");
		if (dotComBust->charicter == 0)
			printf("���Ǿ�, �����ΰ�, ������\n");
		else
			printf("����, �ǻ�, ��ġ��\n");
		printf("��ġ ��ǥ�� �����Ͽ� ���ĵ��� ��� ��ƾ��մϴ�.\n");
		gridearray_printf();
		top_rank();
		work_printf(dotComBust->charicter);
		numOfGuesses_printf(dotComBust->numOfGuesses);
		char* userGuess = getUserInput(dotComBust->helper, "���� ��ǥ �Է� : ");//���� �Է°� �ޱ�
		checkUserGuess(dotComBust, userGuess);//checkuserguess �޼ҵ� ȣ��
			FILE*rp;
			fopen_s(&rp, "savedata.txt", "wt");
			fprintf(rp, "%d ", dotComBust->charicter);
			fprintf(rp, "%d ", dotComBust->dotComList->length);//darraylist ����
			int i, k;
			for (i = 0; i < dotComBust->dotComList->length; i++)
			{
				fprintf(rp, "%d " ,dotComBust->dotComList->dataSet[i]->work);//������ ���� ����
				fprintf(rp, "%d %d %d ", dotComBust->dotComList->dataSet[i]->pp, dotComBust->dotComList->dataSet[i]->gg, dotComBust->dotComList->dataSet[i]->tt);
				fprintf(rp, "%d ", dotComBust->dotComList->dataSet[i]->locationCells->length);//sarraylist ����
				for (k = 0; k < dotComBust->dotComList->dataSet[i]->locationCells->length; k++)
				{
					fprintf(rp, "%s ", dotComBust->dotComList->dataSet[i]->locationCells->dataSet[k]);//��ǥ��
				}
			}
			fprintf(rp, "%d ", dotComBust->numOfGuesses);
			fclose(rp);
			system("cls");
			printf("\n");
	}
	finishGame(dotComBust);//finsifhhame �Լ��� ȣ��
}

void checkUserGuess(DotComBust* dotComBust, char* userGuess)
{
	int index = 0;
	dotComBust->numOfGuesses++;//����ڰ� ������ Ƚ������
	char* result = "miss";//�ٲ��� ������ miss
	for (index = 0; index < dotComBust->dotComList->length; index++)
	{
		result = checkYourself(Dget(dotComBust->dotComList, index), userGuess,dotComBust->charicter);//���İ�ü ���� �����Է°��̶� ������ Ȯ��
		if (!strcmp(result, "hit"))
		{
			break;
		}
		if (!strcmp(result, "kill"))
		{
			Dremove(dotComBust->dotComList,index);
			break;
		}
	}

}

void finishGame(DotComBust* dotComBust)
{
	system("cls");
	remove("savedata.txt");
	remove("killdata.txt");
	rank player;
	printf("��� ���ĵ��� �������ϴ�.\n");
	printf("%d���� ����.\n", dotComBust->numOfGuesses);//���� ��� ���
	printf("�÷��̾��� �̸��� �Է��Ͻÿ�:");
	scanf_s("%s", player.name, sizeof(player.name));
	//gets(player.name);
	player.numOfGuesses = dotComBust->numOfGuesses;
	player.score = 100 + 9 - (dotComBust->numOfGuesses);
	_strdate(player.sdate);  // ���� ���ڸ� ���ڿ��� ������ ��
	_strtime(player.stime);  // ���� �ð��� ���ڿ��� ������ ��
	printf("�����÷��� �ð�:%s %s\n", player.sdate, player.stime);
	//
	int i, k;
	if (access("ranking.bin", 0) == 0)//��ŷ�� ���� ������ ������ ���� �� ����
	{
		rank playerlist[6];
		FILE * fp;
		fopen_s(&fp, "ranking.bin", "rb");
		for (i = 0; !feof(fp); i++)
		{
			fread((void*)&playerlist[i], 1, sizeof(playerlist[i]), fp);
		}
		fclose(fp);
		playerlist[i - 1] = player;
		//����
		int j, l=0;
		rank temp;
		//
		for (j = 0; j<i; j++)
		{
			for (k = 0; k<i-1; k++)
			{
				if (playerlist[k].numOfGuesses > playerlist[k + 1].numOfGuesses) 
				{
					temp = playerlist[k];
					playerlist[k] = playerlist[k + 1];
					playerlist[k + 1] = temp;
				}
			}
		}

		FILE * lp;
		fopen_s((void*)&lp, "ranking.bin", "wb");
		for (k = 0; k < i; k++)
		{
			if (k == 5)
				break;
			fwrite((void*)&playerlist[k], 1, sizeof(playerlist[k]), fp);
		}
		fclose(lp);//��ŷ �����Ͱ� �������� ���� �� ��ŷ���� �κ�

	}
	//
	else {
		FILE * fp;
		fopen_s(&fp, "ranking.bin", "wb");
		fwrite((void*)&player, 1, sizeof(player), fp);
		fclose(fp);
	}
	
}

int main(void)
{
	booting();
	system("cls");
	DotComBust* game = (DotComBust*)malloc(sizeof(DotComBust));
	int savenumber = 0;

	if (access("savedata.txt",0)==0)
	{
		printf("�̾ ������ �����ϰڽ��ϱ�?(����� 1��/���ν��� �ƹ�Ű�� �����ÿ�)");
		scanf_s("%d", &savenumber);
		if(savenumber!=1)
			remove("killdata.txt");
	}
		initDotComBust(game);
		setUpGame(game, savenumber);//���Ӱ�ü�� �����ϴ� ��ɳ���
		startPlaying(game, savenumber);//��ȯ���� ���� �������� ����� ����ġ�� Ȯ����
		free(game);
	return 0;
}