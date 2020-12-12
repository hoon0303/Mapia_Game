#include<Windows.h>
#include<stdio.h>
#include"DotComBust.h"
void draw_menu();
void draw_ranking();
void draw_guide();
void drawxy(int x, int y);
void drawxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void booting()
{
	system("mode con:cols=80 lines=30");
	Sleep(1000);
	system("color 70");
	system("cls");

	printf("��"); Sleep(100);
	printf("��"); Sleep(100);
	printf("��"); Sleep(100);
	printf("��"); Sleep(100);
	printf("��"); Sleep(100);
	printf("��"); Sleep(100);
	printf("."); Sleep(100);
	printf("."); Sleep(100);
	printf("."); Sleep(2000);
	system("cls");
	draw_menu();
}
void draw_menu()
{

	system("cls");
	int i, j;
	char mouth;
	i = 18, j = 6;
	while (1)
	{
		drawxy(i, j + 0);  printf("       ��                ��             ��     ");
		drawxy(i, j + 1);  printf("���� ��      �����  ��     ���    ��     ");
		drawxy(i, j + 2);  printf("��  �� ���     ��  ��   ��    ��  ��   ���   ");
		drawxy(i, j + 3);  printf("���� ��      �����  ��     ���    ��     ");
		drawxy(i, j + 4);  printf("       ��                ��             ��     ");
		//___________________________

		drawxy(26, 15); printf("��������    game menu   ��������\n");
		drawxy(26, 16); printf("��                            ��\n");
		drawxy(26, 17); printf("��                            ��\n");
		drawxy(26, 18); printf("��       1. ���� ����         ��\n");
		drawxy(26, 19); printf("��                            ��\n");
		drawxy(26, 20); printf("��       2. ���� ����         ��\n");
		drawxy(26, 21); printf("��                            ��\n");
		drawxy(26, 22); printf("��       3. ��ŷ              ��\n");
		drawxy(26, 23); printf("��                            ��\n");
		drawxy(26, 24); printf("��       4. ���� ����         ��\n");
		drawxy(26, 25); printf("��                            ��\n");
		drawxy(26, 26); printf("��������������������������������\n");

		drawxy(50, 28);
		printf("�����ȣ�� �Է��ϼ���:");
		mouth = getch();
		if (mouth == '1')
			break;
		else if (mouth == '2')
			draw_guide();
		else if (mouth == '3')
			draw_ranking();
		else if (mouth == '4')
			exit(0);
	}

}
void draw_ranking()
{
	int i, k;
	int numOfGuesses;
	system("cls");
	printf("\n\n");
	printf("-------------------------- R A N K I N G -----------------------------\n");
	printf("======================================================================\n");
	printf("%5s%10s%10s%10s%10s%15s\n", "No", "ID", "����Ƚ��", "����", "��¥", "��:��:��");
	if (access("ranking.bin", 0) == 0)
	{
		rank player[6];
		FILE * fp;
		fopen_s(&fp, "ranking.bin", "rb");
		for (i = 0; !feof(fp); i++)
		{
			fread((void*)&player[i], 1, sizeof(player[i]), fp);
		}
		fclose(fp);
		for (k=0; k < i - 1; k++)
		{
			printf("%5d %10s %10d %10d %10s %10s\n", k + 1, player[k].name, player[k].numOfGuesses, player[k].score, player[k].sdate, player[k].stime);
		}
		
	}
	//
	//
	printf("�ƹ�Ű�� �Է��ϼ���:");
	getch();
	system("cls");
}
void draw_guide()
{
	system("cls");
	drawxy(26, 15); printf("��������    ���� ����   ��������\n");
	drawxy(26, 16); printf("��                            ��\n");
	drawxy(26, 17); printf("��                            ��\n");
	drawxy(26, 18); printf("��   ������ �����ϸ� �����   ��\n");
	drawxy(26, 19); printf("��      ������ �����˴ϴ�     ��\n");
	drawxy(26, 20); printf("��                            ��\n");
	drawxy(26, 21); printf("��  ������ ���� �� �� ����  ��\n");
	drawxy(26, 22); printf("�� ���� 3���� ��ġ�� �����Ͽ� ��\n");
	drawxy(26, 23); printf("��       ��Ƴ��� �˴ϴ�.     ��\n");
	drawxy(26, 24); printf("��                            ��\n");
	drawxy(26, 25); printf("��                            ��\n");
	drawxy(26, 26); printf("��������������������������������\n");
	drawxy(50, 28);
	printf("�ƹ�Ű�� �Է��ϼ���:");
	getch();
}
void gridearray_printf()
{
	int i,k,j;
	int array[7][7] = { 0 };
	char alphabet[7] = "abcdefg";
	char number[7] = "0123456";
	char temp[3];
	int w=0;
	
	if (access("killdata.txt",0) == 0)
	{
		FILE* killread;
		fopen_s(&killread, "killdata.txt", "rt");
		while(w!=EOF)
		{
			w = fscanf_s(killread, "%s ", temp,sizeof(temp));
			for (i = 0; i < 7; i++)
				if (temp[0]==alphabet[i])
					break;
			for (k = 0; k < 7; k++)
				if (temp[1]==number[k])
					break;
			array[i][k] = 1;
		}
		fclose(killread);
	}
	char a = 'A';
	printf("\n");
	 printf("  ������ grid  �迭 ������\n");
	 printf("  ��                    ��\n");
	 printf("  ��    ");
	for (i = 0; i < 7; i++)
		printf("%d ", i);
	printf("  ��\n");
	for (i = 0; i < 7; i++)
	{
		printf("  ��  %c ", a);
		a++;
		for (k = 0; k < 7; k++)
		{
			if (array[i][k] == 1)
				printf("��");
			else
				printf("��");
		}
		printf("  ��\n");
	}
	printf("  ��                    ��\n");
	printf("  ������������������������\n");
}
void top_rank()
{
	rank player;
	drawxy(45, 7); printf("��������    ���� 1��    ��������");
	drawxy(45, 8); printf("��                            ��");
	drawxy(45, 9); printf("��  �̸�   ����Ƚ��    ����   ��");
	drawxy(45, 10); printf("��============================��");
	drawxy(45, 11); printf("��                            ��");
	drawxy(45, 12); printf("��                            ��");
	drawxy(45, 13); printf("��������������������������������\n");
	if (access("ranking.bin", 0) == 0)
	{
		FILE * fp;
		fopen_s(&fp, "ranking.bin", "rb");
		fread((void*)&player, 1, sizeof(player), fp);
		fclose(fp);
		drawxy(48, 11); printf(" %s      %d       %d", player.name, player.numOfGuesses,player.score);
	}
	else
	{
		drawxy(48, 11);
		printf("��ŷ�� ���� ������ �����ϴ�");
	}
}
void work_printf(int charicter)
{
	drawxy(45, 15); printf("����������    ����    ����������");
	drawxy(45, 16); printf("��                            ��");
	if (charicter == 0)
	{
		drawxy(45, 17); printf("��            ����            ��");
	}
	else
	{
		drawxy(45, 17); printf("��           ���Ǿ�           ��");
	}
	drawxy(45, 18); printf("��                            ��");
	drawxy(45, 19); printf("��������������������������������\n");
}
void numOfGuesses_printf(int numOfGuesses)
{
	drawxy(45, 21); printf("��������    ����Ƚ��    ��������");
	drawxy(45, 22); printf("��                            ��");
	drawxy(45, 23); printf("��                            ��");
	drawxy(45, 24); printf("��                            ��");
	drawxy(45, 25); printf("��������������������������������\n");
	drawxy(59, 23); printf("%d ȸ", numOfGuesses);
	drawxy(5, 23);
}
