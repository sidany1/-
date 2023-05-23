#include"PhoneList.h"
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int main() {

	int ON_OFF = 1;//开关

	PL *pl= (PL*)malloc(sizeof(PL));//初始化结构体指针
	PhoneListInit(pl);

	PhoneListImport(pl);//导入文件数据

	char** name;
	char** tele_num;
	int len = 4;
	const int Twidth = 13, Nwidth = 15;
	name = (char**)malloc(sizeof(char*) * len);
	tele_num = (char**)malloc(sizeof(char*) * len);
	for (int i = 0; i < len; i++) {//二维指针行列初始化
		name[i] = (char*)malloc(sizeof(char) * Nwidth);
		tele_num[i] = (char*)malloc(sizeof(char) * Twidth);
	}

	int OP=0;

	int cal_num = 1;//2.新建计数
	char PopName[Nwidth];//3.删除姓名
	int numBegin, numEnd;//4.打印区间
	char FindName[Nwidth];//5.查找姓名

	do{


	printf("请输入你要进行的操作：\n");
	printf("-------------------------\n");
	printf("-\t1.清空\t\t-\n-\t2.新建\t\t-\n-\t3.删除\t\t-\n-\t");
		printf("4.打印通讯录\t-\n-\t5.查找\t\t-\n-\t6.添加入文件\t-\n-\t7.退出\t\t-\n");
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
				P_name = (char**)realloc(*name,sizeof(char*) * len);//二维指针行列初始化
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

			printf("请输入'姓名' '电话'：\n");
			printf("%d.",cal_num);

			scanf_s("%s %s", name[cal_num - 1],Nwidth,tele_num[cal_num-1],Twidth);
//在scanf_s("%s"，数组名，数组长度)中是需要添加数组长度的，否则会访问冲突，引发异常。而scanf是不需要的
			getchar();//吸收缓存区残留的\n
			printf("按E退出\n");
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
		for (int i = 0; i < len; i++) {//二维指针行列初始化
			name[i] = (char*)malloc(sizeof(char) * Nwidth);
			tele_num[i] = (char*)malloc(sizeof(char) * Twidth);
		}
		break;





	case 3:


		printf("请输入您要删除的姓名：\n");
		scanf_s("%s",PopName,Nwidth);
		PhoneListPop(pl,PopName);
		break;




	case 4:


		printf("请输入打印的区间：\n");
		scanf_s("%d %d", &numBegin, &numEnd);
		PhoneListPrintf(pl,  numBegin,  numEnd);
		break;





	case 5:
		

		printf("请输入您要查找的姓名：\n");
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
		printf("输入错误，请重试\n");
}

	} while(ON_OFF);
}