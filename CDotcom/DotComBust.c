#include "DotComBust.h"

void initDotComBust(DotComBust* dotComBust)
{
	dotComBust->helper = (GameHelper*)malloc(sizeof(GameHelper));
	initGameHelper(dotComBust->helper);
	dotComBust->dotComList = (DArrayList*)malloc(sizeof(DArrayList));
	DinitList(dotComBust->dotComList);
	dotComBust->numOfGuesses = 0;//구조체를 사용하여 변수를 만들고 초기화
}

void setUpGame(DotComBust* dotComBust, int savenumber)//닷컴 변수를 만들고 위치지정
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
		printf("당신의 직업을 선발하겠습니다");
		printf("."); Sleep(500); printf("."); Sleep(500); printf(".\n"); Sleep(1000);
		system("cls");
	
	}
	if (dotComBust->charicter == 0)
		work = "경찰";
	else
		work = "마피아";
	printf("당신의 직업은 %s입니다.\n", work);
	DotCom* one = (DotCom*)malloc(sizeof(DotCom));
	DotCom* two = (DotCom*)malloc(sizeof(DotCom));
	DotCom* three = (DotCom*)malloc(sizeof(DotCom));
	initDotCom(one, dotComBust->charicter);
	initDotCom(two, dotComBust->charicter);
	initDotCom(three, dotComBust->charicter);
	if (dotComBust->charicter == 0)
	{
		setName(one, "마피아",1);
		setName(two, "짐승인간",2);
		setName(three, "스파이",3);
	}
	else
	{
		setName(one, "경찰",1);
		setName(two, "의사",2);
		setName(three, "정치인",3);
	}
	Dadd(dotComBust->dotComList, one);
	Dadd(dotComBust->dotComList, two);
	Dadd(dotComBust->dotComList, three);//닷컴 변수 3개를 만든것을 darraylist저장

		

	

	for (index = 0; index < dotComBust->dotComList->length; index++)
	{
		SArrayList* newLocation = placeDotCom(dotComBust->helper, 3,savenumber);
		setLocationCells(Dget(dotComBust->dotComList,index), newLocation);//DotCom 변수에 좌표값 저장
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
			fscanf_s(qp, "%d ", &dotComBust->dotComList->dataSet[i]->work);//잡을것
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
		 printf("당신의 목표는 3개의 닷컴\n");
		if (dotComBust->charicter == 0)
			printf("마피아, 짐승인간, 스파이\n");
		else
			printf("경찰, 의사, 정치인\n");
		printf("위치 좌표를 추측하여 닷컴들을 모두 잡아야합니다.\n");
		gridearray_printf();
		top_rank();
		work_printf(dotComBust->charicter);
		numOfGuesses_printf(dotComBust->numOfGuesses);
		char* userGuess = getUserInput(dotComBust->helper, "추측 좌표 입력 : ");//추측 입력값 받기
		checkUserGuess(dotComBust, userGuess);//checkuserguess 메소들 호출
			FILE*rp;
			fopen_s(&rp, "savedata.txt", "wt");
			fprintf(rp, "%d ", dotComBust->charicter);
			fprintf(rp, "%d ", dotComBust->dotComList->length);//darraylist 길이
			int i, k;
			for (i = 0; i < dotComBust->dotComList->length; i++)
			{
				fprintf(rp, "%d " ,dotComBust->dotComList->dataSet[i]->work);//직업에 대한 정보
				fprintf(rp, "%d %d %d ", dotComBust->dotComList->dataSet[i]->pp, dotComBust->dotComList->dataSet[i]->gg, dotComBust->dotComList->dataSet[i]->tt);
				fprintf(rp, "%d ", dotComBust->dotComList->dataSet[i]->locationCells->length);//sarraylist 길이
				for (k = 0; k < dotComBust->dotComList->dataSet[i]->locationCells->length; k++)
				{
					fprintf(rp, "%s ", dotComBust->dotComList->dataSet[i]->locationCells->dataSet[k]);//좌표값
				}
			}
			fprintf(rp, "%d ", dotComBust->numOfGuesses);
			fclose(rp);
			system("cls");
			printf("\n");
	}
	finishGame(dotComBust);//finsifhhame 함수를 호출
}

void checkUserGuess(DotComBust* dotComBust, char* userGuess)
{
	int index = 0;
	dotComBust->numOfGuesses++;//사용자가 추측한 횟수증가
	char* result = "miss";//바뀌지 않으면 miss
	for (index = 0; index < dotComBust->dotComList->length; index++)
	{
		result = checkYourself(Dget(dotComBust->dotComList, index), userGuess,dotComBust->charicter);//닷컴객체 값과 추측입력값이랑 같은지 확인
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
	printf("모든 닷컴들이 잡혔습니다.\n");
	printf("%d번의 추측.\n", dotComBust->numOfGuesses);//게임 결과 출력
	printf("플레이어의 이름을 입력하시오:");
	scanf_s("%s", player.name, sizeof(player.name));
	//gets(player.name);
	player.numOfGuesses = dotComBust->numOfGuesses;
	player.score = 100 + 9 - (dotComBust->numOfGuesses);
	_strdate(player.sdate);  // 현재 일자를 문자열로 저장해 줌
	_strtime(player.stime);  // 현재 시각을 문자열에 저장해 줌
	printf("게임플레이 시간:%s %s\n", player.sdate, player.stime);
	//
	int i, k;
	if (access("ranking.bin", 0) == 0)//랭킹에 대한 데이터 파일이 있을 때 저장
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
		//정렬
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
		fclose(lp);//랭킹 데이터가 존재하지 않을 때 랭킹저장 부분

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
		printf("이어서 게임을 진행하겠습니까?(재시작 1번/새로시작 아무키나 누르시오)");
		scanf_s("%d", &savenumber);
		if(savenumber!=1)
			remove("killdata.txt");
	}
		initDotComBust(game);
		setUpGame(game, savenumber);//게임객체에 설정하는 명령내림
		startPlaying(game, savenumber);//순환문을 돌려 추측값을 물어보고 그위치를 확인함
		free(game);
	return 0;
}