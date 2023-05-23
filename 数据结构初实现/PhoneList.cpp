#include"PhoneList.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void PhoneListInit(PL* pl) {
	memset(pl->Name, 0, sizeof(pl->Name));
	memset(pl->TeleNum , 0, sizeof(pl->TeleNum ));
	pl->Size = 0;

}//��ʼ��

void PhoneListPush(PL* pl,char **name, char **tele_num,int cal_num) {
	for (int j = 0; j < cal_num; j++) {
		strcpy_s(pl->Name[pl->Size], name[j]);
		strcpy_s(pl->TeleNum[pl->Size], tele_num[j]);
		pl->Size++;
	}
}//����

void PhoneListPop(PL* pl,char PopName[]) {

	int num=0;
	do {
		if (PopName == pl->Name[num]) {
			goto out;
		}
		num++;
	} while (num<pl->Size );
	printf("��ѯʧ��\n");
	return ;
	out:
	for (int i = num; i < pl->Size; i++) {
		strcpy_s(pl->Name[i - 1],pl->Name[i]);
		strcpy_s(pl->TeleNum[ i - 1], pl->TeleNum [i]);
	}
		
		pl->Size--;
}//ɾ��

void PhoneListPrintf(PL* pl, int numBegin, int numEnd) {
	if (numEnd<numBegin) {
		printf("�����������\n");
		return;
	}
	else if (numEnd > pl->Size) {
		numEnd = pl->Size;
	}
	else if (numBegin < 0||numEnd < 0) {
		printf("begin�������\n");
		return;
	}
	else if (numBegin > pl->Size) {
		numBegin = pl->Size;
	}

	for (int j = numBegin; j < numEnd; j++) {
		printf("%d.", j+1);
		printf("%s\t", pl->Name[j]);
		printf("%s\n", pl->TeleNum[j]);
	}
}//��ӡ



void PhoneListFind(PL*pl,char FindName[],int Nwidth) {
	int num = 0;
	for (num = 0;num<pl->Size ; num++) {//C����������������֮�����޷�ֱ���ж���ȵ�
		for (int i = 0; i < Nwidth; i++) {
			if (FindName[i] != pl->Name[num][i]) 
				break;
			
			if (i ==(Nwidth - 1)) 
				goto out;
			
		}

	}
	printf("��ѯʧ��\n");
	return;
out:
	printf("%s\t", pl->Name[num]);
	printf("%s\n", pl->TeleNum[num]);

}//����



void PhonrListSaveAs(PL* pl) {
	FILE* fp;
	fopen_s(&fp,"PhoneList.txt", "w");
	if (fp == NULL) {
		printf("�ļ�����/��ʧ��\n");
		return ;
	}
	for (int i = 0; i < pl->Size; i++) {
	fprintf(fp, "%s\t", pl->Name[i]);
	fprintf(fp, "%s\n", pl->TeleNum[i]);
	}

	fclose(fp);
}//���Ϊ

void PhoneListImport(PL* pl){//�����ļ�����
	FILE* fp;
	int place;//�ļ����ֽ���
	char a;
	fopen_s(&fp, "PhoneList.txt", "r");
	if (fp == NULL) {
		printf("�ļ���ʧ��");
		return;
	}

	fseek(fp, 0l, SEEK_END);//�ѹ���Ƶ��ļ�ĩβ
	place = ftell(fp);//�õ��ļ����ֽ�������ǰλ�ã�
	fseek(fp, 0l, SEEK_SET);//�ƻ���



while (place!=ftell(fp)){//��������绰�ֱ���������
		
		for (int j = 0; a = fgetc(fp)!= '\t'; j++) {
			if (a < 0) {
				pl->Name[pl->Size][j] = a;
				pl->Name[pl->Size][j++] = fgetc(fp);
			}
			printf("%s",pl->Name[pl->Size]);
			pl->Name[pl->Size][j] = a;
			a = fgetc(fp);
		}
		a = fgetc(fp);
		for (int j = 0; a != '\n',a!=EOF; j++) {
			pl->TeleNum[pl->Size][j] = a;
			a = fgetc(fp);
		}
		pl->Size++;
	}

	fclose(fp);
}