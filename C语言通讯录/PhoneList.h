#pragma once
#define N 200
#include<string.h>
#include<stdlib.h>
typedef struct PhoneList
{
	char  Name[N][15];
	char TeleNum[N][12];
	int Size;//�Ѵ�����
}PL;

void PhoneListInit(PL* pl);//��ʼ��
void PhoneListPush(PL* pl, char **name, char **tele_num,int cal_num);//����
void PhoneListPop(PL* pl,char PopName[]);//ɾ��
void PhoneListPrintf(PL* pl,int begin,int end);//��ӡ
void PhoneListFind(PL* pl,char FindName[]);//����
void PhonrListSaveAs(PL* pl);//���Ϊ
void PhoneListImport(PL* pl);//�����ļ�����