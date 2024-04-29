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
	printf("尊敬的用户，欢迎使用火车站管理系统!\n");
	printf("请选择您需要的服务\n");
	printf("**********************\n");
	printf("***   1.售票服务   ***\n");
	printf("***   2.后台管理   ***\n");
	printf("***    按esc退出   ***\n");
	printf("**********************\n");

	int choose = _getch();
	switch (choose)
	{
	case 49:
	{
		PassengerLog();
		// 进入乘客系统
		break;
	}

	case 50:
	{
		ManagerLog();
		// 进入管理系统
		break;
	}

	case 27:
	{
		// 退出系统 
		system("cls");
		printf("**********************\n");
		printf("***感谢使用本系统!***\n");
		printf("**********************\n");
		exit(0);
	}
	}
	return 0;
}

// 票务系统
void Ticketing() // 首页菜单
{
	system("cls");
	printf(" 请选择您需要的服务\n");
	printf("*************************\n");
	printf("***   1.班次查询      ***\n");
	printf("***   2.查看我的车票  ***\n");
	printf("***   3.预定车票    ***\n");
	printf("***   4.退订车票    ***\n");
	printf("***   5.返回上一级    ***\n");
	printf("***   按esc退出程序   ***\n");
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
		printf("***感谢使用本系统!***\n");
		printf("**********************\n");
		exit(0);
	}
	}
}
void PassengerLog() // 票务系统首页
{
	system("cls");
	printf("     欢迎使用售票系统\n");
	printf("**************************\n");
	printf("***    1.登录已有账户  ***\n");
	printf("***    2.注册新账户    ***\n");
	printf("***    3.返回上一级    ***\n");
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

void PassengerLogon() // 乘客注册
{
	if ((fp4 = fopen("NumOfPassenger.txt", "r")) == NULL)
	{
		fp4 = fopen("NumOfPassenger.txt", "w");
		fclose(fp4);
	}
	fp4 = fopen("NumOfPassenger.txt", "rb");
	fseek(fp4, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp4);
	// 检查文件长度

	fseek(fp4, 0, SEEK_SET);
	// 将文件指针移到文件开头

	if (len == 0)
	// 第一个乘客创建账号
	{
		char key[20];
		// 用于存储再次输入的密码
		system("cls");
		struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger));
		printf("请创建一个账号\n");
		scanf("%s", &passenger[0].id);
		printf("请输入您的密码\n");
		scanf("%s", &passenger[0].password);
		printf("请确认您的密码\n");
		scanf("%s", &key);
		if (strcmp(passenger[0].password, key) != 0)
		// 检验两次输入密码是否相同
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("您输入的两次密码不同，请重新输入密码\n");
				scanf("%s", &passenger[0].password);
				printf("请确认您的密码");
				scanf("%s", key);
				if (strcmp(passenger[0].password, key) == 0)
					flag = 0;
			}
		}
		NumOfPassenger++;
		passenger[0].NumOfTicket = 0;
		fp4 = fopen("NumOfPassenger.txt", "w");
		// 创建NumOfPassenger.txt
		fprintf(fp4, "%d", NumOfPassenger);
		// 将乘客人数写入文件中
		fclose(fp4);
		fp2 = fopen("Passenger.txt", "wb");
		fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
		// 将乘客结构体写入文件
		fclose(fp2);
		free(passenger);
		system("cls");
		printf("创建账户成功\n按任意键返回登录界面");
		_getch(); // 从控制台读取一个字符，但不显示在屏幕上 
		PassengerLog();
	}
	else
	// 后续乘客创建账号
	{
		system("cls");
		fp4 = fopen("NumOfPassenger.txt", "r");
		fscanf(fp4, "%d", &NumOfPassenger);
		// 从文件读取乘客人数
		fclose(fp4);

		struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
		fp2 = fopen("Passenger.txt", "rb");
		fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
		// 从文件中读取乘客结构体
		fclose(fp2);

		passenger = (struct passenger *)realloc(passenger, sizeof(struct passenger) * (NumOfPassenger + 1));
		// 乘客结构体扩容一个单位

		char key[20];
		// 用于存储再次输入的密码
		printf("请创建一个账号\n");
		scanf("%s", &passenger[NumOfPassenger].id);
		for (int i = 0; i < NumOfPassenger; i++)
		{
			if (strcmp(passenger[NumOfPassenger].id, passenger[i].id) == 0)
			{
				int flag = 1;
				while (flag)
				{
					system("cls");
					printf("已有账号，请重新输入");
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
		printf("请输入您的密码\n");
		scanf("%s", &passenger[NumOfPassenger].password);
		printf("请确认您的密码\n");
		scanf("%s", &key);
		if (strcmp(passenger[NumOfPassenger].password, key) != 0)
		// 检验两次输入密码是否相同
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("您输入的两次密码不同，请重新输入密码\n");
				scanf("%s", &passenger[NumOfPassenger].password);
				printf("请确认您的密码");
				scanf("%s", key);
				if (strcmp(passenger[NumOfPassenger].password, key) == 0)
					flag = 0;
			}
		}
		printf("创建账户成功\n按任意键返回登录界面");
		passenger[NumOfPassenger].NumOfTicket = 0;
		NumOfPassenger++;
		fp4 = fopen("NumOfPassenger.txt", "w");
		fprintf(fp4, "%d", NumOfPassenger);
		// 将乘客人数写入文件中
		fclose(fp4);
		fp2 = fopen("Passenger.txt", "wb");
		fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
		// 将人数写入乘客文件中
		fclose(fp2);
		free(passenger);
		_getch();
		system("cls");
		PassengerLog();
	}
}
void PassengerLogin() // 乘客登录
{
	char id[20];
	char password[20];
	system("cls");
	printf("请输入账号\n");
	scanf("%s", &id);
	printf("请输入密码\n");
	scanf("%s", &password);

	if ((fp4 = fopen("NumOfPassenger.txt", "r")) == NULL)
	{
		fp4 = fopen("NumOfPassenger.txt", "w");
		fclose(fp4);
	}
	fp4 = fopen("NumOfPassenger.txt", "rb");
	fseek(fp4, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp4);
	// 检查文件长度
	fseek(fp4, 0, SEEK_SET);
	// 将文件指针移到文件开头
	if (len == 0)
	{
		system("cls");
		printf("您输入的账号或密码有误按任意键重新输入,ESC返回");
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
	// 从文件读取乘客人数
	fclose(fp4);

	struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
	fp2 = fopen("Passenger.txt", "rb");
	fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
	// 从文件中读取乘客结构体
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
			printf("您输入的账号或密码有误\n");
			printf("按任意键重新输入，按ESC返回");
			int esc = _getch();
			if (esc == 27)
				PassengerLog();
			system("cls");
			printf("请输入账号\n");
			scanf("%s", &id);
			printf("请输入密码\n");
			scanf("%s", &password);
		}
	}
	Ticketing();
}
void pview() // 车票查询
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp6);
	// 检查文件长度
	fseek(fp6, 0, SEEK_SET);
	// 将文件指针移到文件开头

	if (len == 0)
	// 未添加站点信息
	{
		system("cls");
		printf("当前没有车次信息\n按任意键返回");
		_getch();
		Ticketing();
	}

	else
	// 已添加站点信息
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);
		if (NumOfSite == 0)
		// 站点数为0
		{
			system("cls");
			printf("当前没有车次信息\n按任意键返回");
			_getch();
			Ticketing();
		}
		else
		// 站点数不为0
		{
			struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
			fp5 = fopen("Ticket.txt", "rb");
			fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// 从文件中读取车票结构体
			fclose(fp5);
			system("cls");
			for (int i = 0; i < NumOfSite; i++)
			{
				printf("NO.%d\n", ticket[i].no);
				printf("起点站：%s\n", ticket[i].start);
				printf("终点站：%s\n", ticket[i].destination);
				printf("发车时间：%s\n", ticket[i].StartTime);
				printf("预计到达时间：%s\n", ticket[i].ArriveTime);
				printf("余票数：%d\n", ticket[i].RestOfTicket);
				printf("                                                 \n");
				printf("-------------------------------------------------\n");
				printf("                                                 \n");
			}
			printf("按任意键返回");
			_getch();
			Ticketing();
		}
	}
}
void subscribe() // 车票预定
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp6);
	// 检查文件长度
	fseek(fp6, 0, SEEK_SET);
	// 将文件指针移到文件开头

	if (len == 0)
	// 未添加站点信息
	{
		system("cls");
		printf("当前没有可预定的车次\n按任意键返回");
		_getch();
		Ticketing();
	}

	else
	// 添加过站点信息
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);

		if (NumOfSite == 0)
		// 站点数为0
		{
			system("cls");
			printf("当前没有车次信息\n按任意键返回");
			_getch();
			BackStage();
		}

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 从文件中读取车票结构体
		fclose(fp5);

		system("cls");
		for (int i = 0; i < NumOfSite; i++)
		{
			printf("NO.%d\n", ticket[i].no);
			printf("起点站：%s\n", ticket[i].start);
			printf("终点站：%s\n", ticket[i].destination);
			printf("发车时间：%s\n", ticket[i].StartTime);
			printf("预计到达时间：%s\n", ticket[i].ArriveTime);
			printf("余票数：%d\n", ticket[i].RestOfTicket);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("请选择要预定的车次编号\n");
		int no;
		scanf("%d", &no);
		int flag = 1;

		for (int i = 0; i < NumOfSite; i++)
		// 寻找对应车次信息
		{
			if (no == ticket[i].no)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("没有找到该车次信息\n");
			printf("按任意键重新输入，按ESC返回");
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
			printf("您确定要预定该车次车票吗？\n");
			printf("NO.%d\n", ticket[no - 1].no);
			printf("起点站：%s\n", ticket[no - 1].start);
			printf("终点站：%s\n", ticket[no - 1].destination);
			printf("发车时间：%s\n", ticket[no - 1].StartTime);
			printf("预计到达时间：%s\n", ticket[no - 1].ArriveTime);
			printf("余票数：%d\n", ticket[no - 1].RestOfTicket);
			printf("\n");
			if (ticket[no - 1].RestOfTicket <= 0)
			{
				system("cls");
				printf("对不起，该车次车票已被预定完\n");
				printf("按任意键返回");
				_getch();
				Ticketing();
			}
			printf("按任意键确认，ESC取消\n");
			int esc = _getch();
			if (esc == 27)
			{
				Ticketing();
			}
			else
			{
				fp4 = fopen("NumOfPassenger.txt", "r");
				fscanf(fp4, "%d", &NumOfPassenger);
				// 从文件读取乘客人数
				fclose(fp4);

				struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
				fp2 = fopen("Passenger.txt", "rb");
				fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
				// 从文件中读取乘客结构体
				fclose(fp2);
				passenger[IdOfPassenger].NoOfTicket[passenger[IdOfPassenger].NumOfTicket] = ticket[no - 1].no;
				passenger[IdOfPassenger].NumOfTicket++;
				ticket[no - 1].RestOfTicket--;
				fp5 = fopen("Ticket.txt", "wb");
				fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
				// 将车票结构体写入文件
				fclose(fp5);
				free(ticket);
				fp2 = fopen("Passenger.txt", "wb");
				fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
				// 将乘客结构体写入文件
				fclose(fp2);
				free(passenger);
				printf("添加完成，按任意键返回");
				Ticketing();
			}
		}
	}
}
void ViewMine() // 乘客车票查询
{
	fp4 = fopen("NumOfPassenger.txt", "r");
	fscanf(fp4, "%d", &NumOfPassenger);
	// 从文件读取乘客人数
	fclose(fp4);

	struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
	fp2 = fopen("Passenger.txt", "rb");
	fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
	// 从文件中读取乘客结构体
	fclose(fp2);

	if (passenger[IdOfPassenger].NumOfTicket == 0)
	{
		system("cls");
		printf("暂未查询到您的车票预定信息\n");
		printf("按任意键返回");
		_getch();
		free(passenger);
		Ticketing();
	}
	else
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 从文件中读取车票结构体
		fclose(fp5);

		system("cls");
		printf("您有%d张预定的车票\n", passenger[IdOfPassenger].NumOfTicket);
		for (int i = 0; i < passenger[IdOfPassenger].NumOfTicket; i++)
		{
			printf("NO.%d\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].no);
			printf("起点站：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].start);
			printf("终点站：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].destination);
			printf("发车时间：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].StartTime);
			printf("预计到达时间：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].ArriveTime);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("按任意键返回");
		free(ticket);
		free(passenger);
		_getch();
		Ticketing();
	}
}
void cancel() // 车票退订
{
	fp4 = fopen("NumOfPassenger.txt", "r");
	fscanf(fp4, "%d", &NumOfPassenger);
	// 从文件读取乘客人数
	fclose(fp4);

	struct passenger *passenger = (struct passenger *)malloc(sizeof(struct passenger) * NumOfPassenger);
	fp2 = fopen("Passenger.txt", "rb");
	fread(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
	// 从文件中读取乘客结构体
	fclose(fp2);

	if (passenger[IdOfPassenger].NumOfTicket == 0)
	{
		system("cls");
		printf("暂未查询到您的车票预定信息\n");
		printf("按任意键返回");
		free(passenger);
		_getch();
		Ticketing();
	}
	else
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 从文件中读取车票结构体
		fclose(fp5);

		system("cls");
		for (int i = 0; i < passenger[IdOfPassenger].NumOfTicket; i++)
		{
			printf("NO.%d\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].no);
			printf("起点站：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].start);
			printf("终点站：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].destination);
			printf("发车时间：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].StartTime);
			printf("预计到达时间：%s\n", ticket[passenger[IdOfPassenger].NoOfTicket[i] - 1].ArriveTime);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("请选择要退订的车次编号");
		int no;
		int index;
		// 记下车次编号储存在NoOfTicket中的位置
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
			printf("对不起，您没有预定该车次\n");
			printf("按任意键重新输入，按ESC返回");
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
			printf("起点站：%s\n", ticket[no - 1].start);
			printf("终点站：%s\n", ticket[no - 1].destination);
			printf("发车时间：%s\n", ticket[no - 1].StartTime);
			printf("预计到达时间：%s\n", ticket[no - 1].ArriveTime);
			printf("\n");
			printf("您确定要删除该车次预定信息吗？\n");
			printf("按任意键确定，按ESC取消\n");
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
			// 将车票结构体写入文件
			fclose(fp5);
			free(ticket);
			fp2 = fopen("Passenger.txt", "wb");
			fwrite(passenger, sizeof(struct passenger), NumOfPassenger, fp2);
			// 将乘客结构体写入文件
			fclose(fp2);
			free(passenger);
			printf("删除成功，按任意键返回");
			_getch();
			Ticketing();
		}
	}
}

// 后台管理系统
void ManagerLog() // 员工登录注册界面
{
	system("cls");
	printf("     欢迎使用后台管理\n");
	printf("**************************\n");
	printf("***    1.登录已有账户  ***\n");
	printf("***    2.注册新账户    ***\n");
	printf("***    3.返回上一级    ***\n");
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
void BackStage() // 后台操作界面
{
	system("cls");
	printf(" 请选择您需要的服务\n");
	printf("************************\n");
	printf("***   1.站点操作     ***\n");
	printf("***   2.票务操作     ***\n");
	printf("***   3.返回上一级   ***\n");
	printf("***   按esc退出程序  ***\n");
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
		printf("***感谢使用本系统!***\n");
		printf("**********************\n");
		exit(0);
	}
	}
}
void logon() 
// 管理员账户注册
{
	if ((fp3 = fopen("NumOfManager.txt", "r")) == NULL)
	{
		fp3 = fopen("NumOfManager.txt", "w");
		fclose(fp3);
	}
	fp3 = fopen("NumOfManager.txt", "rb");
	fseek(fp3, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp3);
	// 检查文件长度
	fseek(fp3, 0, SEEK_SET);
	// 将文件指针移到文件开头
	if (len == 0)
	// 第一个员工创建账号
	{
		char key[20];
		// 用于存储再次输入的密码
		system("cls");
		struct manager *manager = (struct manager *)malloc(sizeof(struct manager));
		printf("请创建一个账号\n");
		scanf("%s", &manager[0].id);
		printf("请输入您的密码\n");
		scanf("%s", &manager[0].password);
		printf("请确认您的密码\n");
		scanf("%s", &key);
		if (strcmp(manager[0].password, key) != 0)
		// 检验两次输入密码是否相同
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("您输入的两次密码不同，请重新输入密码\n");
				scanf("%s", &manager[0].password);
				printf("请确认您的密码");
				scanf("%s", key);
				if (strcmp(manager[0].password, key) == 0)
					flag = 0;
			}
		}
		NumOfManager++;
		fp3 = fopen("NumOfManager.txt", "w");
		// 创建NumOfManager.txt
		fprintf(fp3, "%d", NumOfManager);
		// 将管理人员人数写入文件中
		fclose(fp3);
		fp1 = fopen("Manager.txt", "wb");
		fwrite(manager, sizeof(struct manager), NumOfManager, fp1);
		// 将管理人员结构体写入文件
		fclose(fp1);
		free(manager);
		system("cls");
		printf("创建账户成功\n按任意键返回登录界面");
		_getch();
		ManagerLog();
	}
	else
	// 后续员工创建账号
	{
		system("cls");
		fp3 = fopen("NumOfManager.txt", "r");
		fscanf(fp3, "%d", &NumOfManager);
		// 从文件读取管理人员人数
		fclose(fp3);

		struct manager *manager = (struct manager *)malloc(sizeof(struct manager) * NumOfManager);
		fp1 = fopen("Manager.txt", "rb");
		fread(manager, sizeof(struct manager), NumOfManager, fp1);
		// 从文件中读取管理人员结构体
		fclose(fp1);

		manager = (struct manager *)realloc(manager, sizeof(struct manager) * (NumOfManager + 1));
		// 管理人员结构体扩容一个单位

		char key[20];
		// 用于存储再次输入的密码
		printf("请创建一个账号\n");
		scanf("%s", &manager[NumOfManager].id);
		for (int i = 0; i < NumOfManager; i++)
		{
			if (strcmp(manager[NumOfManager].id, manager[i].id) == 0)
			{
				int flag = 1;
				while (flag)
				{
					system("cls");
					printf("已有账号，请重新输入");
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
		printf("请输入您的密码\n");
		scanf("%s", &manager[NumOfManager].password);
		printf("请确认您的密码\n");
		scanf("%s", &key);
		if (strcmp(manager[NumOfManager].password, key) != 0)
		// 检验两次输入密码是否相同
		{
			int flag = 1;
			while (flag)
			{
				system("cls");
				printf("您输入的两次密码不同，请重新输入密码\n");
				scanf("%s", &manager[NumOfManager].password);
				printf("请确认您的密码");
				scanf("%s", key);
				if (strcmp(manager[NumOfManager].password, key) == 0)
					flag = 0;
			}
		}
		printf("创建账户成功\n按任意键返回登录界面");
		NumOfManager++;
		fp3 = fopen("NumOfManager.txt", "w");
		fprintf(fp3, "%d", NumOfManager);
		// 将管理人员人数写入文件中
		fclose(fp3);
		fp1 = fopen("Manager.txt", "wb");
		fwrite(manager, sizeof(struct manager), NumOfManager, fp1);
		// 将管理人员人数写入文件中
		fclose(fp1);
		free(manager);
		_getch();
		system("cls");
		ManagerLog();
	}
}
void login() 
// 账户登录
{
	char id[20];
	char password[20];
	system("cls");
	printf("请输入账号\n");
	scanf("%s", &id);
	printf("请输入密码\n");
	scanf("%s", &password);

	if ((fp3 = fopen("NumOfManager.txt", "r")) == NULL)
	{
		fp3 = fopen("NumOfManager.txt", "w");
		fclose(fp3);
	}
	fp3 = fopen("NumOfManager.txt", "rb");
	fseek(fp3, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp3);
	// 检查文件长度
	fseek(fp3, 0, SEEK_SET);
	// 将文件指针移到文件开头
	if (len == 0)
	{
		system("cls");
		printf("您输入的账号或密码有误按任意键重新输入,ESC返回");
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
	// 从文件读取管理人员人数
	fclose(fp3);

	struct manager *manager = (struct manager *)malloc(sizeof(struct manager) * NumOfManager);
	fp1 = fopen("Manager.txt", "rb");
	fread(manager, sizeof(struct manager), NumOfManager, fp1);
	// 从文件中读取管理人员结构体
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
			printf("您输入的账号或密码有误\n");
			printf("按任意键重新输入，按ESC返回");
			int esc = _getch();
			if (esc == 27)
				ManagerLog();
			system("cls");
			printf("请输入账号\n");
			scanf("%s", &id);
			printf("请输入密码\n");
			scanf("%s", &password);
		}
	}
	BackStage();
}
void site() // 站点信息
{
	system("cls");
	printf(" 请选择您需要的操作\n");
	printf("************************\n");
	printf("***   1.查看站点     ***\n");
	printf("***   2.添加站点     ***\n");
	printf("***   3.修改站点     ***\n");
	printf("***   4.删除站点     ***\n");
	printf("***   5.返回上一级   ***\n");
	printf("***   按esc退出程序  ***\n");
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
void AddSite() // 增加车次
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp6);
	// 检查文件长度
	fseek(fp6, 0, SEEK_SET);
	// 将文件指针移到文件开头
	if (len == 0)
	// 第一次添加站点
	{
		NumOfSite = 1;
		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		ticket[0].no = NumOfSite;
		system("cls");
		printf("请输入起始站\n");
		scanf("%s", &ticket[0].start);
		printf("请输入终点站\n");
		scanf("%s", &ticket[0].destination);
		printf("请输入出发时间\n");
		scanf("%s", &ticket[0].StartTime);
		printf("请输入到达时间\n");
		scanf("%s", &ticket[0].ArriveTime);
		printf("请输入车票张数\n");
		scanf("%d", &ticket[0].RestOfTicket);
		fp6 = fopen("NumOfSite.txt", "w");
		fprintf(fp6, "%d", NumOfSite);
		// 将站点数写入文件中
		fclose(fp6);
		fp5 = fopen("Ticket.txt", "wb");
		fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 将车票结构体写入文件
		fclose(fp5);
		free(ticket);
		printf("添加完成，按任意键返回\n");
		_getch();
		site();
	}
	else
	// 后续添加站点
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		NumOfSite++;
		fclose(fp6);
		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 从文件中读取车票结构体
		fclose(fp5);
		system("cls");
		ticket[NumOfSite - 1].no = NumOfSite;
		printf("请输入起始站\n");
		scanf("%s", &ticket[NumOfSite - 1].start);
		printf("请输入终点站\n");
		scanf("%s", &ticket[NumOfSite - 1].destination);
		printf("请输入出发时间\n");
		scanf("%s", &ticket[NumOfSite - 1].StartTime);
		printf("请输入到达时间\n");
		scanf("%s", &ticket[NumOfSite - 1].ArriveTime);
		printf("请输入车票张数\n");
		scanf("%d", &ticket[NumOfSite - 1].RestOfTicket);

		fp6 = fopen("NumOfSite.txt", "w");
		fprintf(fp6, "%d", NumOfSite);
		// 将站点数写入文件中
		fclose(fp6);
		fp5 = fopen("Ticket.txt", "wb");
		fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 将车票结构体写入文件
		fclose(fp5);
		free(ticket);
		printf("添加完成，按任意键返回\n");
		_getch();
		site();
	}
}
void view() // 车次查询
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp6);
	// 检查文件长度
	fseek(fp6, 0, SEEK_SET);
	// 将文件指针移到文件开头

	if (len == 0)
	// 未添加站点信息
	{
		system("cls");
		printf("当前没有车次信息\n按任意键返回");
		_getch();
		site();
	}

	else
	// 已添加站点信息
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);
		if (NumOfSite == 0)
		// 站点数为0
		{
			system("cls");
			printf("当前没有车次信息\n按任意键返回");
			_getch();
			site();
		}
		else
		// 站点数不为0
		{
			struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
			fp5 = fopen("Ticket.txt", "rb");
			fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// 从文件中读取车票结构体
			fclose(fp5);
			system("cls");
			for (int i = 0; i < NumOfSite; i++)
			{
				printf("NO.%d\n", ticket[i].no);
				printf("起点站：%s\n", ticket[i].start);
				printf("终点站：%s\n", ticket[i].destination);
				printf("发车时间：%s\n", ticket[i].StartTime);
				printf("预计到达时间：%s\n", ticket[i].ArriveTime);
				printf("余票数：%d\n", ticket[i].RestOfTicket);
				printf("                                                 \n");
				printf("-------------------------------------------------\n");
				printf("                                                 \n");
			}
			free(ticket);
			printf("按任意键返回");
			_getch();
			site();
		}
	}
}
void modify() // 车次修改
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp6);
	// 检查文件长度
	fseek(fp6, 0, SEEK_SET);
	// 将文件指针移到文件开头

	if (len == 0)
	// 未添加站点信息
	{
		system("cls");
		printf("当前没有车次信息\n按任意键返回");
		_getch();
		site();
	}

	else
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);
		if (NumOfSite == 0)
		// 站点数为0
		{
			system("cls");
			printf("当前没有车次信息\n按任意键返回");
			_getch();
			site();
		}
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 从文件中读取车票结构体
		fclose(fp5);

		system("cls");
		printf("请选择要修改的车次编号");
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
			printf("没有找到该车次信息\n");
			printf("按任意键重新输入，按ESC返回");
			int esc = _getch();
			if (esc == 27)
				site();
			else
				modify();
		}
		else // 找到对应车次信息
		{
			system("cls");
			printf("NO.%d\n", ticket[no - 1].no);
			printf("起点站：%s\n", ticket[no - 1].start);
			printf("终点站：%s\n", ticket[no - 1].destination);
			printf("发车时间：%s\n", ticket[no - 1].StartTime);
			printf("预计到达时间：%s\n", ticket[no - 1].ArriveTime);
			printf("余票数：%d\n", ticket[no - 1].RestOfTicket);
			printf("\n");
			printf("请选择要修改的内容\n");
			printf("************************\n");
			printf("***   1.起点站       ***\n");
			printf("***   2.终点站       ***\n");
			printf("***   3.发车时间     ***\n");
			printf("***   4.预计到达时间 ***\n");
			printf("***   5.余票数       ***\n");
			printf("***   6.返回上一级   ***\n");
			printf("************************\n");
			int choose = _getch();
			switch (choose)
			{
			case 49:
				printf("请输入起点站");
				scanf("%s", &ticket[no - 1].start);
				break;
			case 50:
				printf("请输入终点站");
				scanf("%s", &ticket[no - 1].destination);
				break;
			case 51:
				printf("请输入发车时间");
				scanf("%s", &ticket[no - 1].StartTime);
				break;
			case 52:
				printf("请输入预计到达时间");
				scanf("%s", &ticket[no - 1].ArriveTime);
				break;
			case 53:
				printf("请输入余票数");
				scanf("%d", &ticket[no - 1].RestOfTicket);
				break;
			case 54:
				modify();
				break;
			}
			fp5 = fopen("Ticket.txt", "wb");
			fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// 将车票结构体写入文件
			fclose(fp5);
			free(ticket);
			system("cls");
			printf("更改完成，按任意键返回");
			_getch();
			site();
		}
	}
}
void delet() // 删除车次
{
	if ((fp6 = fopen("NumOfSite.txt", "r")) == NULL)
	{
		fp6 = fopen("NumOfSite.txt", "w");
		fclose(fp6);
	}
	fp6 = fopen("NumOfSite.txt", "rb");
	fseek(fp6, 0, SEEK_END);
	// 将文件指针移到文件末尾
	int len = ftell(fp6);
	// 检查文件长度
	fseek(fp6, 0, SEEK_SET);
	// 将文件指针移到文件开头

	if (len == 0)
	// 未添加站点信息
	{
		system("cls");
		printf("当前没有车次信息\n按任意键返回");
		_getch();
		site();
	}

	else
	// 添加过站点信息
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);

		if (NumOfSite == 0)
		// 站点数为0
		{
			system("cls");
			printf("当前没有车次信息\n按任意键返回");
			_getch();
			site();
		}

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 从文件中读取车票结构体
		fclose(fp5);

		system("cls");
		printf("请选择要删除的车次编号\n");
		for (int i = 0; i < NumOfSite; i++)
		{
			printf("NO.%d\n", ticket[i].no);
			printf("起点站：%s\n", ticket[i].start);
			printf("终点站：%s\n", ticket[i].destination);
			printf("发车时间：%s\n", ticket[i].StartTime);
			printf("预计到达时间：%s\n", ticket[i].ArriveTime);
			printf("余票数：%d\n", ticket[i].RestOfTicket);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}

		int no;
		scanf("%d", &no);
		int flag = 1;

		for (int i = 0; i < NumOfSite; i++)
		// 寻找对应车次信息
		{
			if (no == ticket[i].no)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("没有找到该车次信息\n");
			printf("按任意键重新输入，按ESC返回");
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
			printf("起点站：%s\n", ticket[no - 1].start);
			printf("终点站：%s\n", ticket[no - 1].destination);
			printf("发车时间：%s\n", ticket[no - 1].StartTime);
			printf("预计到达时间：%s\n", ticket[no - 1].ArriveTime);
			printf("余票数：%d\n", ticket[no - 1].RestOfTicket);
			printf("\n");
			printf("您确定要删除该车次信息吗？\n");
			printf("按任意键确认，ESC取消\n");
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
				// 删除后重新编号
				{
					ticket[i].no = i + 1;
				}
				fp6 = fopen("NumOfSite.txt", "w");
				fprintf(fp6, "%d", NumOfSite);
				// 将站点数写入文件中
				fclose(fp6);
				fp5 = fopen("Ticket.txt", "wb");
				fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
				// 将车票结构体写入文件
				fclose(fp5);
				free(ticket);
				printf("删除完成，按任意键返回\n");
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
	// 将文件指针移到文件末尾
	int len = ftell(fp6);
	// 检查文件长度
	fseek(fp6, 0, SEEK_SET);
	// 将文件指针移到文件开头

	if (len == 0)
	// 未添加站点信息
	{
		system("cls");
		printf("当前没有车次信息\n按任意键返回");
		_getch();
		BackStage();
	}

	else
	// 添加过站点信息
	{
		fp6 = fopen("NumOfSite.txt", "r");
		fscanf(fp6, "%d", &NumOfSite);
		// 从文件读取车票数
		fclose(fp6);

		if (NumOfSite == 0)
		// 站点数为0
		{
			system("cls");
			printf("当前没有车次信息\n按任意键返回");
			_getch();
			BackStage();
		}

		struct ticket *ticket = (struct ticket *)malloc(sizeof(struct ticket) * NumOfSite);
		fp5 = fopen("Ticket.txt", "rb");
		fread(ticket, sizeof(struct ticket), NumOfSite, fp5);
		// 从文件中读取车票结构体
		fclose(fp5);

		system("cls");
		for (int i = 0; i < NumOfSite; i++)
		{
			printf("NO.%d\n", ticket[i].no);
			printf("起点站：%s\n", ticket[i].start);
			printf("终点站：%s\n", ticket[i].destination);
			printf("发车时间：%s\n", ticket[i].StartTime);
			printf("预计到达时间：%s\n", ticket[i].ArriveTime);
			printf("余票数：%d\n", ticket[i].RestOfTicket);
			printf("                                                 \n");
			printf("-------------------------------------------------\n");
			printf("                                                 \n");
		}
		printf("请选择要操作的车次编号\n");

		int no;
		scanf("%d", &no);
		int flag = 1;

		for (int i = 0; i < NumOfSite; i++)
		// 寻找对应车次信息
		{
			if (no == ticket[i].no)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			printf("没有找到该车次信息\n");
			printf("按任意键重新输入，按ESC返回");
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
			printf("请输入修改的车票数目\n");
			scanf("%d", &ticket[no - 1].RestOfTicket);
			fp5 = fopen("Ticket.txt", "wb");
			fwrite(ticket, sizeof(struct ticket), NumOfSite, fp5);
			// 将车票结构体写入文件
			fclose(fp5);
			free(ticket);
			system("cls");
			printf("更改完成，按任意键返回");
			_getch();
			BackStage();
		}
	}
}
