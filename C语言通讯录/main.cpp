#include"PhoneList.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int main() {

	int ON_OFF = 1;//����

	PL *pl= (PL*)malloc(sizeof(PL));//��ʼ���ṹ��ָ��
	PhoneListInit(pl);

	PhoneListImport(pl);//�����ļ�����

	char** name;
	char** tele_num;
	int len = 4;
	const int Twidth = 13, Nwidth = 15;
	name = (char**)malloc(sizeof(char*) * len);
	tele_num = (char**)malloc(sizeof(char*) * len);
	for (int i = 0; i < len; i++) {//��άָ�����г�ʼ��
		name[i] = (char*)malloc(sizeof(char) * Nwidth);
		tele_num[i] = (char*)malloc(sizeof(char) * Twidth);
	}

	int OP=0;

	int cal_num = 1;//2.�½�����
	char PopName[Nwidth];//3.ɾ������
	int numBegin, numEnd;//4.��ӡ����
	char FindName[Nwidth];//5.��������

	do{


	printf("��������Ҫ���еĲ�����\n");
	printf("-------------------------\n");
	printf("-\t1.���\t\t-\n-\t2.�½�\t\t-\n-\t3.ɾ��\t\t-\n-\t");
		printf("4.��ӡͨѶ¼\t-\n-\t5.����\t\t-\n-\t6.������ļ�\t-\n-\t7.�˳�\t\t-\n");
	printf("-------------------------\n");

	scanf_s("%d",&OP);
	
	switch (OP) {

	case 1:
		PhoneListInit( pl);
		break;



	case 2:

		char a;



		do {
			if (cal_num > len) {
				int beg_len = len;
				len += 4;
				char** P_name;
				char** P_tele;
				P_name = (char**)realloc(*name,sizeof(char*) * len);//��άָ�����г�ʼ��
				P_tele = (char**)realloc(*tele_num, sizeof(char*) * len);
				if (*P_name!=NULL&& *P_tele != NULL) {
					name = P_name;
					tele_num = P_tele;
					for (int i = beg_len; i < len; i++) {
						name[i] = (char*)calloc(Nwidth ,sizeof(char) );
						tele_num[i] = (char*)calloc(Twidth , sizeof(char) );
					}
				}else {
					exit(-1);

				}

			}

			printf("������'����' '�绰'��\n");
			printf("%d.",cal_num);

			scanf_s("%s %s", name[cal_num - 1],Nwidth,tele_num[cal_num-1],Twidth);
//��scanf_s("%s"�������������鳤��)������Ҫ������鳤�ȵģ��������ʳ�ͻ�������쳣����scanf�ǲ���Ҫ��
			getchar();//���ջ�����������\n
			printf("��E�˳�\n");
			a = getchar();
			if (a == 'E') {
				break;
			}
			cal_num++;
		} while (1);


		PhoneListPush(pl, name,tele_num ,cal_num);
		for (int i = 0; i < len; i++){
			free(name[i]);
			free(tele_num[i]);
		}
		free(name);
		free(tele_num);
		name = (char**)malloc(sizeof(char*) * len);
		tele_num = (char**)malloc(sizeof(char*) * len);
		for (int i = 0; i < len; i++) {//��άָ�����г�ʼ��
			name[i] = (char*)malloc(sizeof(char) * Nwidth);
			tele_num[i] = (char*)malloc(sizeof(char) * Twidth);
		}
		break;





	case 3:


		printf("��������Ҫɾ����������\n");
		scanf_s("%s",PopName,Nwidth);
		PhoneListPop(pl,PopName);
		break;




	case 4:


		printf("�������ӡ�����䣺\n");
		scanf_s("%d %d", &numBegin, &numEnd);
		PhoneListPrintf(pl,  numBegin,  numEnd);
		break;





	case 5:
		

		printf("��������Ҫ���ҵ�������\n");
		scanf_s("%s", FindName,Nwidth);
		PhoneListFind(pl, FindName,Nwidth);
		break;





	case 6:

		PhonrListSaveAs(pl);
		break;
	

	case 7:
		ON_OFF = 0;
		break;




	default:
		printf("�������������\n");
}

	} while(ON_OFF);
}