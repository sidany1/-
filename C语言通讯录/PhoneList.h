#pragma once
#define N 200
#include<string.h>
#include<stdlib.h>
typedef struct PhoneList
{
	char  Name[N][15];
	char TeleNum[N][12];
	int Size;//已存数量
}PL;

void PhoneListInit(PL* pl);//初始化
void PhoneListPush(PL* pl, char **name, char **tele_num,int cal_num);//插入
void PhoneListPop(PL* pl,char PopName[]);//删除
void PhoneListPrintf(PL* pl,int begin,int end);//打印
void PhoneListFind(PL* pl,char FindName[]);//查找
void PhonrListSaveAs(PL* pl);//另存为
void PhoneListImport(PL* pl);//导入文件数据