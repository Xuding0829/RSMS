#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 6031)
#pragma warning(disable : 6031)
#pragma warning(disable : 6385)
#pragma warning(disable : 6054)
#pragma warning(disable : 28182)
#pragma warning(disable : 6011)
#pragma warning(disable : 6308)
#pragma warning(disable : 28183)
#pragma warning(disable : 6387)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <map>
#include <string>
#include <bits/stdc++.h>

int NumOfManager;
int NumOfPassenger;
int NumOfSite;

FILE *fp1; // Manager.txt
FILE *fp2; // Passenger.txt
FILE *fp3; // NumOfManager.txt
FILE *fp4; // NumOfPassenger.txt
FILE *fp5; // Ticket.txt
FILE *fp6; // NumOfSite.txt
FILE *fp7;

int IdOfPassenger;
extern int NumOfManager;
extern int NumOfPassenger;
extern int NumOfSite;

struct manager
{
	char id[50];
	char password[50];
};

struct passenger
{
	char id[50];
	char password[50];
	int NoOfTicket[20];
	int NumOfTicket;
};

struct ticket
{
	int no;
	char start[50];
	char destination[50];
	char StartTime[50];
	char ArriveTime[50];
	int RestOfTicket;
};

void BackStage();
void Ticketing();

void ManagerLog();
void logon();
void login();

void PassengerLog();
void PassengerLogin();
void PassengerLogon();
void ViewMine();
void subscribe();
void cancel();

void site();
void AddSite();
void view();
void modify();
void delet();
void ModifyNum();

void pview();

int main()
{
	system("cls");
	printf("�𾴵��û�����ӭʹ�û�վ����ϵͳ!\n");
	printf("��ѡ������Ҫ�ķ���\n");
	printf("**********************\n");
	printf("***   1.��Ʊ����   ***\n");
	printf("***   2.��̨����   ***\n");
	printf("***    ��esc�˳�   ***\n");
	printf("**********************\n");

	int choose = _getch();
	switch (choose)
	{
	case 49:
	{
		PassengerLog();
		// ����˿�ϵͳ
		break;
	}

	case 50:
	{
		ManagerLog();
		// �������ϵͳ
		break;
	}

	case 27:
	{
		// �˳�ϵͳ 
		system("cls");
		printf("**********************\n");
		printf("***��лʹ�ñ�ϵͳ!***\n");
		printf("**********************\n");
		exit(0);
	}
	}
	return 0;
}

// Ʊ��ϵͳ
void Ticketing() // ��ҳ�˵�
{
	system("cls");
	printf(" ��ѡ������Ҫ�ķ���\n");
	printf("*************************\n");
	printf("***   1.��β�ѯ      ***\n");
	printf("***   2.�鿴�ҵĳ�Ʊ  ***\n");
	printf("***   3.Ԥ����Ʊ    ***\n");
	printf("***   4.�˶���Ʊ    ***\n");
	printf("***   5.������һ��    ***\n");
	printf("***   ��esc�˳�����   ***\n");
	printf("*************************\n");
	int choose = _getch();
	switch (choose)
	{
	case 49:
		pview();
		break;
	case 50:
		ViewMine();
		break;
	case 51:
		subscribe();
		break;
	case 52:
		cancel();
		break;
	case 53:
		main();
		break;
	case 27:
	{
		system("cls");
		printf("**********************\n");
		printf("***��лʹ�ñ�ϵͳ!***\n");
		printf("**********************\n");
		exit(0);
	}
	}
}
void PassengerLog() // Ʊ��ϵͳ��ҳ
{
	system("cls");
	printf("     ��ӭʹ����Ʊϵͳ\n");
	printf("**************************\n");
	printf("***    1.��¼�����˻�  ***\n");
	printf("***    2.ע�����˻�    ***\n");
	printf("***    3.������һ��    ***\n");
	printf("**************************\n");
	int choose = _getch();
	switch (choose)
	{
	case 49:
		PassengerLogin();
		break;
	case 50:
		PassengerLogon();
		break;
	case 51:
		main();
	}
}

void PassengerLogon() // �˿�ע��
{
	if ((fp4 = fopen("NumOfPassenger.txt", "r")) == NULL)
	{
		fp4 = fopen("NumOfPassenger.txt", "w");
		fclose(fp4);
	}
	fp4 = fopen("NumOfPassenger.txt", "rb");
	fseek(fp4, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp4);
	// ����ļ�����

	fseek(fp4, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ

	if (len == 0)
	// ��һ���˿ʹ����˺�
	{
		char key[20];
		// ���ڴ洢�ٴ����������
		system("cls");
		struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger));
		printf("�봴��һ���˺�\n");
		scanf("%s", &passenger[0].id);
		printf("��������������\n");
		scanf("%s", &passenger[0].password);
		printf("��ȷ����������\n");
		scanf("%s", &key);
		if (strcmp(passenger[0].password, key) != 0)
		// �����������������Ƿ���ͬ
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("��������������벻ͬ����������������\n");
				scanf("%s", &passenger[0].password);
				printf("��ȷ����������");
				scanf("%s", key);
				if (strcmp(passenger[0].password, key) == 0)
					flag = 0;
			}
		}
		NumOfPassenger++;
		passenger[0].NumOfTicket = 0;
		fp4 = fopen("NumOfPassenger.txt", "w");
		// ����NumOfPassenger.txt
		fprintf(fp4, "%d", NumOfPassenger);
		// ���˿�����д���ļ���
		fclose(fp4);
		fp2 = fopen("Passenger.txt", "wb");
		fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
		// ���˿ͽṹ��д���ļ�
		fclose(fp2);
		free(passenger);
		system("cls");
		printf("�����˻��ɹ�\n����������ص�¼����");
		_getch(); // �ӿ���̨��ȡһ���ַ���������ʾ����Ļ�� 
		PassengerLog();
	}
	else
	// �����˿ʹ����˺�
	{
		system("cls");
		fp4 = fopen("NumOfPassenger.txt", "r");
		fscanf(fp4, "%d", &NumOfPassenger);
		// ���ļ���ȡ�˿�����
		fclose(fp4);

		struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
		fp2 = fopen("Passenger.txt", "rb");
		fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
		// ���ļ��ж�ȡ�˿ͽṹ��
		fclose(fp2);

		passenger = (struct passenger *)realloc(passenger, sizeof(struct passenger) * (NumOfPassenger + 1));
		// �˿ͽṹ������һ����λ

		char key[20];
		// ���ڴ洢�ٴ����������
		printf("�봴��һ���˺�\n");
		scanf("%s", &passenger[NumOfPassenger].id);
		for (int i = 0; i < NumOfPassenger; i++)
		{
			if (strcmp(passenger[NumOfPassenger].id, passenger[i].id) == 0)
			{
				int flag = 1;
				while (flag)
				{
					system("cls");
					printf("�����˺ţ�����������");
					scanf("%s", &passenger[NumOfPassenger].id);
					for (int n = 0; n < NumOfPassenger; n++)
					{
						if (strcmp(passenger[NumOfPassenger].id, passenger[n].id) == 0)
							break;
						if (n == NumOfPassenger - 1)
							flag = 0;
					}
				}
				break;
			}
		}
		printf("��������������\n");
		scanf("%s", &passenger[NumOfPassenger].password);
		printf("��ȷ����������\n");
		scanf("%s", &key);
		if (strcmp(passenger[NumOfPassenger].password, key) != 0)
		// �����������������Ƿ���ͬ
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("��������������벻ͬ����������������\n");
				scanf("%s", &passenger[NumOfPassenger].password);
				printf("��ȷ����������");
				scanf("%s", key);
				if (strcmp(passenger[NumOfPassenger].password, key) == 0)
					flag = 0;
			}
		}
		printf("�����˻��ɹ�\n����������ص�¼����");
		passenger[NumOfPassenger].NumOfTicket = 0;
		NumOfPassenger++;
		fp4 = fopen("NumOfPassenger.txt", "w");
		fprintf(fp4, "%d", NumOfPassenger);
		// ���˿�����д���ļ���
		fclose(fp4);
		fp2 = fopen("Passenger.txt", "wb");
		fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
		// ������д��˿��ļ���
		fclose(fp2);
		free(passenger);
		_getch();
		system("cls");
		PassengerLog();
	}
}
void PassengerLogin() // �˿͵�¼
{
	char id[20];
	char password[20];
	system("cls");
	printf("�������˺�\n");
	scanf("%s", &id);
	printf("����������\n");
	scanf("%s", &password);

	if ((fp4 = fopen("NumOfPassenger.txt", "r")) == NULL)
	{
		fp4 = fopen("NumOfPassenger.txt", "w");
		fclose(fp4);
	}
	fp4 = fopen("NumOfPassenger.txt", "rb");
	fseek(fp4, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp4);
	// ����ļ�����
	fseek(fp4, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ
	if (len == 0)
	{
		system("cls");
		printf("��������˺Ż����������������������,ESC����");
		int esc = _getch();
		if (esc == 27)
		{
			PassengerLog();
		}
		else
		{
			PassengerLogin();
		}
	}

	fp4 = fopen("NumOfPassenger.txt", "r");
	fscanf(fp4, "%d", &NumOfPassenger);
	// ���ļ���ȡ�˿�����
	fclose(fp4);

	struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
	fp2 = fopen("Passenger.txt", "rb");
	fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
	// ���ļ��ж�ȡ�˿ͽṹ��
	fclose(fp2);
	int flag = 1;
	while (flag)
	{
		for (int i = 0; i < NumOfPassenger; i++)
		{
			if (strcmp(id, passenger[i].id) == 0)
			{
				for (int m = 0; m < NumOfPassenger; m++)
				{
					if (strcmp(password, passenger[m].password) == 0)
					{
						flag = 0;
						IdOfPassenger = m;
						break;
					}
				}
				break;
			}
		}
		if (flag == 1)
		{
			system("cls");
			printf("��������˺Ż���������\n");
			printf("��������������룬��ESC����");
			int esc = _getch();
			if (esc == 27)
				PassengerLog();
			system("cls");
			printf("�������˺�\n");
			scanf("%s", &id);
			printf("����������\n");
			scanf("%s", &password);
		}
	}
	Ticketing();
}
void pview() // ��Ʊ��ѯ
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp6);
	// ����ļ�����
	fseek(fp6, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ

	if (len == 0)
	// δ���վ����Ϣ
	{
		system("cls");
		printf("��ǰû�г�����Ϣ\n�����������");
		_getch();
		Ticketing();
	}

	else
	// �����վ����Ϣ
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);
		if (NumOfSite == 0)
		// վ����Ϊ0
		{
			system("cls");
			printf("��ǰû�г�����Ϣ\n�����������");
			_getch();
			Ticketing();
		}
		else
		// վ������Ϊ0
		{
			struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
			fp5 = fopen("Ticket.txt", "rb");
			fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// ���ļ��ж�ȡ��Ʊ�ṹ��
			fclose(fp5);
			system("cls");
			for (int i = 0; i < NumOfSite; i++)
			{
				printf("NO.%d\n", ticket[i].no);
				printf("���վ��%s\n", ticket[i].start);
				printf("�յ�վ��%s\n", ticket[i].destination);
				printf("����ʱ�䣺%s\n", ticket[i].StartTime);
				printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[i].ArriveTime);
				printf("��Ʊ����%d\n", ticket[i].RestOfTicket);
				printf("                                                 \n");
				printf("-------------------------------------------------\n");
				printf("                                                 \n");
			}
			printf("�����������");
			_getch();
			Ticketing();
		}
	}
}
void subscribe() // ��ƱԤ��
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp6);
	// ����ļ�����
	fseek(fp6, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ

	if (len == 0)
	// δ���վ����Ϣ
	{
		system("cls");
		printf("��ǰû�п�Ԥ���ĳ���\n�����������");
		_getch();
		Ticketing();
	}

	else
	// ��ӹ�վ����Ϣ
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);

		if (NumOfSite == 0)
		// վ����Ϊ0
		{
			system("cls");
			printf("��ǰû�г�����Ϣ\n�����������");
			_getch();
			BackStage();
		}

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ���ļ��ж�ȡ��Ʊ�ṹ��
		fclose(fp5);

		system("cls");
		for (int i = 0; i < NumOfSite; i++)
		{
			printf("NO.%d\n", ticket[i].no);
			printf("���վ��%s\n", ticket[i].start);
			printf("�յ�վ��%s\n", ticket[i].destination);
			printf("����ʱ�䣺%s\n", ticket[i].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[i].ArriveTime);
			printf("��Ʊ����%d\n", ticket[i].RestOfTicket);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("��ѡ��ҪԤ���ĳ��α��\n");
		int no;
		scanf("%d", &no);
		int flag = 1;

		for (int i = 0; i < NumOfSite; i++)
		// Ѱ�Ҷ�Ӧ������Ϣ
		{
			if (no == ticket[i].no)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("û���ҵ��ó�����Ϣ\n");
			printf("��������������룬��ESC����");
			int esc = _getch();
			if (esc == 27)
				Ticketing();
			else
			{
				subscribe();
			}
		}
		else
		{
			system("cls");
			printf("��ȷ��ҪԤ���ó��γ�Ʊ��\n");
			printf("NO.%d\n", ticket[no - 1].no);
			printf("���վ��%s\n", ticket[no - 1].start);
			printf("�յ�վ��%s\n", ticket[no - 1].destination);
			printf("����ʱ�䣺%s\n", ticket[no - 1].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[no - 1].ArriveTime);
			printf("��Ʊ����%d\n", ticket[no - 1].RestOfTicket);
			printf("\n");
			if (ticket[no - 1].RestOfTicket <= 0)
			{
				system("cls");
				printf("�Բ��𣬸ó��γ�Ʊ�ѱ�Ԥ����\n");
				printf("�����������");
				_getch();
				Ticketing();
			}
			printf("�������ȷ�ϣ�ESCȡ��\n");
			int esc = _getch();
			if (esc == 27)
			{
				Ticketing();
			}
			else
			{
				fp4 = fopen("NumOfPassenger.txt", "r");
				fscanf(fp4, "%d", &NumOfPassenger);
				// ���ļ���ȡ�˿�����
				fclose(fp4);

				struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
				fp2 = fopen("Passenger.txt", "rb");
				fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
				// ���ļ��ж�ȡ�˿ͽṹ��
				fclose(fp2);
				passenger[IdOfPassenger].NoOfTicket[passenger[IdOfPassenger].NumOfTicket] = ticket[no - 1].no;
				passenger[IdOfPassenger].NumOfTicket++;
				ticket[no - 1].RestOfTicket--;
				fp5 = fopen("Ticket.txt", "wb");
				fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
				// ����Ʊ�ṹ��д���ļ�
				fclose(fp5);
				free(ticket);
				fp2 = fopen("Passenger.txt", "wb");
				fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
				// ���˿ͽṹ��д���ļ�
				fclose(fp2);
				free(passenger);
				printf("�����ɣ������������");
				Ticketing();
			}
		}
	}
}
void ViewMine() // �˿ͳ�Ʊ��ѯ
{
	fp4 = fopen("NumOfPassenger.txt", "r");
	fscanf(fp4, "%d", &NumOfPassenger);
	// ���ļ���ȡ�˿�����
	fclose(fp4);

	struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
	fp2 = fopen("Passenger.txt", "rb");
	fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
	// ���ļ��ж�ȡ�˿ͽṹ��
	fclose(fp2);

	if (passenger[IdOfPassenger].NumOfTicket == 0)
	{
		system("cls");
		printf("��δ��ѯ�����ĳ�ƱԤ����Ϣ\n");
		printf("�����������");
		_getch();
		free(passenger);
		Ticketing();
	}
	else
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ���ļ��ж�ȡ��Ʊ�ṹ��
		fclose(fp5);

		system("cls");
		printf("����%d��Ԥ���ĳ�Ʊ\n", passenger[IdOfPassenger].NumOfTicket);
		for (int i = 0; i < passenger[IdOfPassenger].NumOfTicket; i++)
		{
			printf("NO.%d\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].no);
			printf("���վ��%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].start);
			printf("�յ�վ��%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].destination);
			printf("����ʱ�䣺%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].ArriveTime);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("�����������");
		free(ticket);
		free(passenger);
		_getch();
		Ticketing();
	}
}
void cancel() // ��Ʊ�˶�
{
	fp4 = fopen("NumOfPassenger.txt", "r");
	fscanf(fp4, "%d", &NumOfPassenger);
	// ���ļ���ȡ�˿�����
	fclose(fp4);

	struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
	fp2 = fopen("Passenger.txt", "rb");
	fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
	// ���ļ��ж�ȡ�˿ͽṹ��
	fclose(fp2);

	if (passenger[IdOfPassenger].NumOfTicket == 0)
	{
		system("cls");
		printf("��δ��ѯ�����ĳ�ƱԤ����Ϣ\n");
		printf("�����������");
		free(passenger);
		_getch();
		Ticketing();
	}
	else
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ���ļ��ж�ȡ��Ʊ�ṹ��
		fclose(fp5);

		system("cls");
		for (int i = 0; i < passenger[IdOfPassenger].NumOfTicket; i++)
		{
			printf("NO.%d\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].no);
			printf("���վ��%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].start);
			printf("�յ�վ��%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].destination);
			printf("����ʱ�䣺%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].ArriveTime);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("��ѡ��Ҫ�˶��ĳ��α��");
		int no;
		int index;
		// ���³��α�Ŵ�����NoOfTicket�е�λ��
		scanf("%d", &no);
		int flag = 0;
		for (int i = 0; i < passenger[IdOfPassenger].NumOfTicket; i++)
		{
			if (passenger[IdOfPassenger].NoOfTicket[i] == no)
			{
				flag = 1;
				index = i;
				break;
			}
		}
		if (flag == 0)
		{
			system("cls");
			printf("�Բ�����û��Ԥ���ó���\n");
			printf("��������������룬��ESC����");
			int esc = _getch();
			if (esc == 27)
				Ticketing();
			else
				cancel();
		}
		else
		{
			system("cls");
			printf("NO.%d\n", ticket[no - 1].no);
			printf("���վ��%s\n", ticket[no - 1].start);
			printf("�յ�վ��%s\n", ticket[no - 1].destination);
			printf("����ʱ�䣺%s\n", ticket[no - 1].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[no - 1].ArriveTime);
			printf("\n");
			printf("��ȷ��Ҫɾ���ó���Ԥ����Ϣ��\n");
			printf("�������ȷ������ESCȡ��\n");
			int esc = _getch();
			if (esc == 27)
				Ticketing();
			else
			{
				for (int i = index; i < passenger[IdOfPassenger].NumOfTicket - 1; i++)
				{
					passenger[IdOfPassenger].NoOfTicket[i] = passenger[IdOfPassenger].NoOfTicket[i + 1];
				}
				passenger[IdOfPassenger].NumOfTicket--;
				ticket[no - 1].RestOfTicket++;
			}
			fp5 = fopen("Ticket.txt", "wb");
			fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// ����Ʊ�ṹ��д���ļ�
			fclose(fp5);
			free(ticket);
			fp2 = fopen("Passenger.txt", "wb");
			fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
			// ���˿ͽṹ��д���ļ�
			fclose(fp2);
			free(passenger);
			printf("ɾ���ɹ��������������");
			_getch();
			Ticketing();
		}
	}
}

// ��̨����ϵͳ
void ManagerLog() // Ա����¼ע�����
{
	system("cls");
	printf("     ��ӭʹ�ú�̨����\n");
	printf("**************************\n");
	printf("***    1.��¼�����˻�  ***\n");
	printf("***    2.ע�����˻�    ***\n");
	printf("***    3.������һ��    ***\n");
	printf("**************************\n");
	int choose = _getch();
	switch (choose)
	{
	case 49:
		login();
		break;
	case 50:
		logon();
		break;
	case 51:
		main();
	}
}
void BackStage() // ��̨��������
{
	system("cls");
	printf(" ��ѡ������Ҫ�ķ���\n");
	printf("************************\n");
	printf("***   1.վ�����     ***\n");
	printf("***   2.Ʊ�����     ***\n");
	printf("***   3.������һ��   ***\n");
	printf("***   ��esc�˳�����  ***\n");
	printf("************************\n");
	int choose = _getch();
	switch (choose)
	{
	case 49:
		site();
		break;
	case 50:
		ModifyNum();
		break;
	case 51:
		ManagerLog();
		break;
	case 27:
	{
		system("cls");
		printf("**********************\n");
		printf("***��лʹ�ñ�ϵͳ!***\n");
		printf("**********************\n");
		exit(0);
	}
	}
}
void logon() 
// ����Ա�˻�ע��
{
	if ((fp3 = fopen("NumOfManager.txt", "r")) == NULL)
	{
		fp3 = fopen("NumOfManager.txt", "w");
		fclose(fp3);
	}
	fp3 = fopen("NumOfManager.txt", "rb");
	fseek(fp3, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp3);
	// ����ļ�����
	fseek(fp3, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ
	if (len == 0)
	// ��һ��Ա�������˺�
	{
		char key[20];
		// ���ڴ洢�ٴ����������
		system("cls");
		struct manager *manager = (struct manager *)malloc(sizeof(struct manager));
		printf("�봴��һ���˺�\n");
		scanf("%s", &manager[0].id);
		printf("��������������\n");
		scanf("%s", &manager[0].password);
		printf("��ȷ����������\n");
		scanf("%s", &key);
		if (strcmp(manager[0].password, key) != 0)
		// �����������������Ƿ���ͬ
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("��������������벻ͬ����������������\n");
				scanf("%s", &manager[0].password);
				printf("��ȷ����������");
				scanf("%s", key);
				if (strcmp(manager[0].password, key) == 0)
					flag = 0;
			}
		}
		NumOfManager++;
		fp3 = fopen("NumOfManager.txt", "w");
		// ����NumOfManager.txt
		fprintf(fp3, "%d", NumOfManager);
		// ��������Ա����д���ļ���
		fclose(fp3);
		fp1 = fopen("Manager.txt", "wb");
		fwrite(manager, sizeof(struct manager), NumOfManager, fp1);
		// ��������Ա�ṹ��д���ļ�
		fclose(fp1);
		free(manager);
		system("cls");
		printf("�����˻��ɹ�\n����������ص�¼����");
		_getch();
		ManagerLog();
	}
	else
	// ����Ա�������˺�
	{
		system("cls");
		fp3 = fopen("NumOfManager.txt", "r");
		fscanf(fp3, "%d", &NumOfManager);
		// ���ļ���ȡ������Ա����
		fclose(fp3);

		struct manager *manager = (struct manager *)malloc(sizeof(struct manager) * NumOfManager);
		fp1 = fopen("Manager.txt", "rb");
		fread(manager, sizeof(struct manager), NumOfManager, fp1);
		// ���ļ��ж�ȡ������Ա�ṹ��
		fclose(fp1);

		manager = (struct manager *)realloc(manager, sizeof(struct manager) * (NumOfManager + 1));
		// ������Ա�ṹ������һ����λ

		char key[20];
		// ���ڴ洢�ٴ����������
		printf("�봴��һ���˺�\n");
		scanf("%s", &manager[NumOfManager].id);
		for (int i = 0; i < NumOfManager; i++)
		{
			if (strcmp(manager[NumOfManager].id, manager[i].id) == 0)
			{
				int flag = 1;
				while (flag)
				{
					system("cls");
					printf("�����˺ţ�����������");
					scanf("%s", &manager[NumOfManager].id);
					for (int n = 0; n < NumOfManager; n++)
					{
						if (strcmp(manager[NumOfManager].id, manager[n].id) == 0)
							break;
						if (n == NumOfManager - 1)
							flag = 0;
					}
				}
				break;
			}
		}
		printf("��������������\n");
		scanf("%s", &manager[NumOfManager].password);
		printf("��ȷ����������\n");
		scanf("%s", &key);
		if (strcmp(manager[NumOfManager].password, key) != 0)
		// �����������������Ƿ���ͬ
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("��������������벻ͬ����������������\n");
				scanf("%s", &manager[NumOfManager].password);
				printf("��ȷ����������");
				scanf("%s", key);
				if (strcmp(manager[NumOfManager].password, key) == 0)
					flag = 0;
			}
		}
		printf("�����˻��ɹ�\n����������ص�¼����");
		NumOfManager++;
		fp3 = fopen("NumOfManager.txt", "w");
		fprintf(fp3, "%d", NumOfManager);
		// ��������Ա����д���ļ���
		fclose(fp3);
		fp1 = fopen("Manager.txt", "wb");
		fwrite(manager, sizeof(struct manager), NumOfManager, fp1);
		// ��������Ա����д���ļ���
		fclose(fp1);
		free(manager);
		_getch();
		system("cls");
		ManagerLog();
	}
}
void login() 
// �˻���¼
{
	char id[20];
	char password[20];
	system("cls");
	printf("�������˺�\n");
	scanf("%s", &id);
	printf("����������\n");
	scanf("%s", &password);

	if ((fp3 = fopen("NumOfManager.txt", "r")) == NULL)
	{
		fp3 = fopen("NumOfManager.txt", "w");
		fclose(fp3);
	}
	fp3 = fopen("NumOfManager.txt", "rb");
	fseek(fp3, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp3);
	// ����ļ�����
	fseek(fp3, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ
	if (len == 0)
	{
		system("cls");
		printf("��������˺Ż����������������������,ESC����");
		int esc = _getch();
		if (esc == 27)
		{
			ManagerLog();
		}
		else
		{
			login();
		}
	}

	fp3 = fopen("NumOfManager.txt", "r");
	fscanf(fp3, "%d", &NumOfManager);
	// ���ļ���ȡ������Ա����
	fclose(fp3);

	struct manager *manager = (struct manager *)malloc(sizeof(struct manager) * NumOfManager);
	fp1 = fopen("Manager.txt", "rb");
	fread(manager, sizeof(struct manager), NumOfManager, fp1);
	// ���ļ��ж�ȡ������Ա�ṹ��
	fclose(fp1);
	int flag = 1;
	while (flag)
	{
		for (int i = 0; i < NumOfManager; i++)
		{
			if (strcmp(id, manager[i].id) == 0)
			{
				for (int m = 0; m < NumOfManager; m++)
				{
					if (strcmp(password, manager[m].password) == 0)
					{
						flag = 0;
						break;
					}
				}
				break;
			}
		}
		if (flag == 1)
		{
			system("cls");
			printf("��������˺Ż���������\n");
			printf("��������������룬��ESC����");
			int esc = _getch();
			if (esc == 27)
				ManagerLog();
			system("cls");
			printf("�������˺�\n");
			scanf("%s", &id);
			printf("����������\n");
			scanf("%s", &password);
		}
	}
	BackStage();
}
void site() // վ����Ϣ
{
	system("cls");
	printf(" ��ѡ������Ҫ�Ĳ���\n");
	printf("************************\n");
	printf("***   1.�鿴վ��     ***\n");
	printf("***   2.���վ��     ***\n");
	printf("***   3.�޸�վ��     ***\n");
	printf("***   4.ɾ��վ��     ***\n");
	printf("***   5.������һ��   ***\n");
	printf("***   ��esc�˳�����  ***\n");
	printf("************************\n");
	int key = _getch();
	switch (key)
	{
	case 49:
		view();
		break;
	case 50:
		AddSite();
		break;
	case 51:
		modify();
		break;
	case 52:
		delet();
		break;
	case 53:
		BackStage();
		break;
	}
}
void AddSite() // ���ӳ���
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp6);
	// ����ļ�����
	fseek(fp6, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ
	if (len == 0)
	// ��һ�����վ��
	{
		NumOfSite = 1;
		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		ticket[0].no = NumOfSite;
		system("cls");
		printf("��������ʼվ\n");
		scanf("%s", &ticket[0].start);
		printf("�������յ�վ\n");
		scanf("%s", &ticket[0].destination);
		printf("���������ʱ��\n");
		scanf("%s", &ticket[0].StartTime);
		printf("�����뵽��ʱ��\n");
		scanf("%s", &ticket[0].ArriveTime);
		printf("�����복Ʊ����\n");
		scanf("%d", &ticket[0].RestOfTicket);
		fp6 = fopen("NumOfSite.txt", "w");
		fprintf(fp6, "%d", NumOfSite);
		// ��վ����д���ļ���
		fclose(fp6);
		fp5 = fopen("Ticket.txt", "wb");
		fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ����Ʊ�ṹ��д���ļ�
		fclose(fp5);
		free(ticket);
		printf("�����ɣ������������\n");
		_getch();
		site();
	}
	else
	// �������վ��
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		NumOfSite++;
		fclose(fp6);
		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ���ļ��ж�ȡ��Ʊ�ṹ��
		fclose(fp5);
		system("cls");
		ticket[NumOfSite - 1].no = NumOfSite;
		printf("��������ʼվ\n");
		scanf("%s", &ticket[NumOfSite - 1].start);
		printf("�������յ�վ\n");
		scanf("%s", &ticket[NumOfSite - 1].destination);
		printf("���������ʱ��\n");
		scanf("%s", &ticket[NumOfSite - 1].StartTime);
		printf("�����뵽��ʱ��\n");
		scanf("%s", &ticket[NumOfSite - 1].ArriveTime);
		printf("�����복Ʊ����\n");
		scanf("%d", &ticket[NumOfSite - 1].RestOfTicket);

		fp6 = fopen("NumOfSite.txt", "w");
		fprintf(fp6, "%d", NumOfSite);
		// ��վ����д���ļ���
		fclose(fp6);
		fp5 = fopen("Ticket.txt", "wb");
		fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ����Ʊ�ṹ��д���ļ�
		fclose(fp5);
		free(ticket);
		printf("�����ɣ������������\n");
		_getch();
		site();
	}
}
void view() // ���β�ѯ
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp6);
	// ����ļ�����
	fseek(fp6, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ

	if (len == 0)
	// δ���վ����Ϣ
	{
		system("cls");
		printf("��ǰû�г�����Ϣ\n�����������");
		_getch();
		site();
	}

	else
	// �����վ����Ϣ
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);
		if (NumOfSite == 0)
		// վ����Ϊ0
		{
			system("cls");
			printf("��ǰû�г�����Ϣ\n�����������");
			_getch();
			site();
		}
		else
		// վ������Ϊ0
		{
			struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
			fp5 = fopen("Ticket.txt", "rb");
			fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// ���ļ��ж�ȡ��Ʊ�ṹ��
			fclose(fp5);
			system("cls");
			for (int i = 0; i < NumOfSite; i++)
			{
				printf("NO.%d\n", ticket[i].no);
				printf("���վ��%s\n", ticket[i].start);
				printf("�յ�վ��%s\n", ticket[i].destination);
				printf("����ʱ�䣺%s\n", ticket[i].StartTime);
				printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[i].ArriveTime);
				printf("��Ʊ����%d\n", ticket[i].RestOfTicket);
				printf("                                                 \n");
				printf("-------------------------------------------------\n");
				printf("                                                 \n");
			}
			free(ticket);
			printf("�����������");
			_getch();
			site();
		}
	}
}
void modify() // �����޸�
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp6);
	// ����ļ�����
	fseek(fp6, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ

	if (len == 0)
	// δ���վ����Ϣ
	{
		system("cls");
		printf("��ǰû�г�����Ϣ\n�����������");
		_getch();
		site();
	}

	else
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);
		if (NumOfSite == 0)
		// վ����Ϊ0
		{
			system("cls");
			printf("��ǰû�г�����Ϣ\n�����������");
			_getch();
			site();
		}
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ���ļ��ж�ȡ��Ʊ�ṹ��
		fclose(fp5);

		system("cls");
		printf("��ѡ��Ҫ�޸ĵĳ��α��");
		int no;
		scanf("%d", &no);
		int flag = 1;

		for (int i = 0; i < NumOfSite; i++)
		{
			if (no == ticket[i].no)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("û���ҵ��ó�����Ϣ\n");
			printf("��������������룬��ESC����");
			int esc = _getch();
			if (esc == 27)
				site();
			else
				modify();
		}
		else // �ҵ���Ӧ������Ϣ
		{
			system("cls");
			printf("NO.%d\n", ticket[no - 1].no);
			printf("���վ��%s\n", ticket[no - 1].start);
			printf("�յ�վ��%s\n", ticket[no - 1].destination);
			printf("����ʱ�䣺%s\n", ticket[no - 1].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[no - 1].ArriveTime);
			printf("��Ʊ����%d\n", ticket[no - 1].RestOfTicket);
			printf("\n");
			printf("��ѡ��Ҫ�޸ĵ�����\n");
			printf("************************\n");
			printf("***   1.���վ       ***\n");
			printf("***   2.�յ�վ       ***\n");
			printf("***   3.����ʱ��     ***\n");
			printf("***   4.Ԥ�Ƶ���ʱ�� ***\n");
			printf("***   5.��Ʊ��       ***\n");
			printf("***   6.������һ��   ***\n");
			printf("************************\n");
			int choose = _getch();
			switch (choose)
			{
			case 49:
				printf("���������վ");
				scanf("%s", &ticket[no - 1].start);
				break;
			case 50:
				printf("�������յ�վ");
				scanf("%s", &ticket[no - 1].destination);
				break;
			case 51:
				printf("�����뷢��ʱ��");
				scanf("%s", &ticket[no - 1].StartTime);
				break;
			case 52:
				printf("������Ԥ�Ƶ���ʱ��");
				scanf("%s", &ticket[no - 1].ArriveTime);
				break;
			case 53:
				printf("��������Ʊ��");
				scanf("%d", &ticket[no - 1].RestOfTicket);
				break;
			case 54:
				modify();
				break;
			}
			fp5 = fopen("Ticket.txt", "wb");
			fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// ����Ʊ�ṹ��д���ļ�
			fclose(fp5);
			free(ticket);
			system("cls");
			printf("������ɣ������������");
			_getch();
			site();
		}
	}
}
void delet() // ɾ������
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp6);
	// ����ļ�����
	fseek(fp6, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ

	if (len == 0)
	// δ���վ����Ϣ
	{
		system("cls");
		printf("��ǰû�г�����Ϣ\n�����������");
		_getch();
		site();
	}

	else
	// ��ӹ�վ����Ϣ
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);

		if (NumOfSite == 0)
		// վ����Ϊ0
		{
			system("cls");
			printf("��ǰû�г�����Ϣ\n�����������");
			_getch();
			site();
		}

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ���ļ��ж�ȡ��Ʊ�ṹ��
		fclose(fp5);

		system("cls");
		printf("��ѡ��Ҫɾ���ĳ��α��\n");
		for (int i = 0; i < NumOfSite; i++)
		{
			printf("NO.%d\n", ticket[i].no);
			printf("���վ��%s\n", ticket[i].start);
			printf("�յ�վ��%s\n", ticket[i].destination);
			printf("����ʱ�䣺%s\n", ticket[i].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[i].ArriveTime);
			printf("��Ʊ����%d\n", ticket[i].RestOfTicket);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}

		int no;
		scanf("%d", &no);
		int flag = 1;

		for (int i = 0; i < NumOfSite; i++)
		// Ѱ�Ҷ�Ӧ������Ϣ
		{
			if (no == ticket[i].no)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("û���ҵ��ó�����Ϣ\n");
			printf("��������������룬��ESC����");
			int esc = _getch();
			if (esc == 27)
				site();
			else
			{
				delet();
			}
		}
		else
		{
			system("cls");
			printf("NO.%d\n", ticket[no - 1].no);
			printf("���վ��%s\n", ticket[no - 1].start);
			printf("�յ�վ��%s\n", ticket[no - 1].destination);
			printf("����ʱ�䣺%s\n", ticket[no - 1].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[no - 1].ArriveTime);
			printf("��Ʊ����%d\n", ticket[no - 1].RestOfTicket);
			printf("\n");
			printf("��ȷ��Ҫɾ���ó�����Ϣ��\n");
			printf("�������ȷ�ϣ�ESCȡ��\n");
			int esc = _getch();
			if (esc == 27)
			{
				site();
			}
			else
			{
				for (int i = no - 1; i < NumOfSite - 1; i++)
				{
					ticket[i] = ticket[i + 1];
				}
				ticket = (struct ticket *)realloc(ticket, sizeof(struct ticket) * (NumOfSite - 1));
				NumOfSite--;
				for (int i = 0; i < NumOfSite; i++)
				// ɾ�������±��
				{
					ticket[i].no = i + 1;
				}
				fp6 = fopen("NumOfSite.txt", "w");
				fprintf(fp6, "%d", NumOfSite);
				// ��վ����д���ļ���
				fclose(fp6);
				fp5 = fopen("Ticket.txt", "wb");
				fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
				// ����Ʊ�ṹ��д���ļ�
				fclose(fp5);
				free(ticket);
				printf("ɾ����ɣ������������\n");
				_getch();
				site();
			}
		}
	}
}
void ModifyNum()
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// ���ļ�ָ���Ƶ��ļ�ĩβ
	int len = ftell(fp6);
	// ����ļ�����
	fseek(fp6, 0, SEEK_SET);
	// ���ļ�ָ���Ƶ��ļ���ͷ

	if (len == 0)
	// δ���վ����Ϣ
	{
		system("cls");
		printf("��ǰû�г�����Ϣ\n�����������");
		_getch();
		BackStage();
	}

	else
	// ��ӹ�վ����Ϣ
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// ���ļ���ȡ��Ʊ��
		fclose(fp6);

		if (NumOfSite == 0)
		// վ����Ϊ0
		{
			system("cls");
			printf("��ǰû�г�����Ϣ\n�����������");
			_getch();
			BackStage();
		}

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// ���ļ��ж�ȡ��Ʊ�ṹ��
		fclose(fp5);

		system("cls");
		for (int i = 0; i < NumOfSite; i++)
		{
			printf("NO.%d\n", ticket[i].no);
			printf("���վ��%s\n", ticket[i].start);
			printf("�յ�վ��%s\n", ticket[i].destination);
			printf("����ʱ�䣺%s\n", ticket[i].StartTime);
			printf("Ԥ�Ƶ���ʱ�䣺%s\n", ticket[i].ArriveTime);
			printf("��Ʊ����%d\n", ticket[i].RestOfTicket);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("��ѡ��Ҫ�����ĳ��α��\n");

		int no;
		scanf("%d", &no);
		int flag = 1;

		for (int i = 0; i < NumOfSite; i++)
		// Ѱ�Ҷ�Ӧ������Ϣ
		{
			if (no == ticket[i].no)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("û���ҵ��ó�����Ϣ\n");
			printf("��������������룬��ESC����");
			int esc = _getch();
			if (esc == 27)
				site();
			else
			{
				ModifyNum();
			}
		}
		else
		{
			printf("�������޸ĵĳ�Ʊ��Ŀ\n");
			scanf("%d", &ticket[no - 1].RestOfTicket);
			fp5 = fopen("Ticket.txt", "wb");
			fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// ����Ʊ�ṹ��д���ļ�
			fclose(fp5);
			free(ticket);
			system("cls");
			printf("������ɣ������������");
			_getch();
			BackStage();
		}
	}
}
