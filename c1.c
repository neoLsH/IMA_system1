#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <windows.h>
/*
        链表思路：
        只设计一条链表，用部门编号进行区分，输出时通过遍历全员，查找数字输出。
        修改时使用一个副本在函数里面修改，改完之后传回main函数中，覆盖原值

*/

/*
        任务：IMA部员管理系统
        部员账号：member		iloveima2333
        部长账号：minister		iamanartical2333
        退出：exit
*/

struct student
{
	char name[20];
	char num[15];
	char tele[15];
	char qq[15];
	int department_num;
}info1, *p1 = &info1;
struct Node
{
	struct student data;
	struct Node* next;
};

//创建链表
struct Node* creatList()
{
	struct Node* List = (struct Node*)malloc(sizeof(struct Node));
	List->next = NULL;
	return List;
}

//创建节点
struct Node* creatNode(struct student data)
{
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->next = NULL;
	return node;
}

//头插法
void insertNode(struct Node* List, struct student data)
{
	struct Node* newNode = creatNode(data);
	newNode->next = List->next;
	List->next = newNode;
}
//打印
void printList( struct Node* List1,int choice,struct student info1)
{
	struct Node* p = List1->next;
	printf("姓名\t\t学号\t\t电话\t\tQQ号\t\t部门编号\n");
	while (p)
	{
		if (choice==(p->data.department_num))
                {
                        printf("%s\t%s\t%s\t%s\t%d\n", p->data.name, p->data.num, p->data.tele, p->data.qq,p->data.department_num);
                }
                p = p->next;
		//现在的问题就是：为什么改了数据之后的List1链表读不出来！！
		//解答：因为在changeNode函数里面最后把指针free掉了，所以不能在函数里面释放指针
	}
	printf("\n");
}
//修改信息
struct Node* changeNode(struct Node* List1, char* posData,struct  student info1, struct student *p1)
{
	int k;
	int change_choice;
	struct Node* p_1 = List1;
	struct Node* posNode1 = List1->next;
	while (strcmp(posNode1->data.name, posData) != 0)
	{
		/*原始方法
		p=p->next;
		posNode=posNode->next;
		*/
		//快捷方法

		p_1 = posNode1;
		posNode1 = p_1->next;
		if (posNode1 == NULL)
		{
			printf("\n\n未找到！！");
			Sleep(1000);
			system("cls");
			//free(p1);
			//free(posNode1);
			return 0;
		}
	}
	change_choice = NULL;
	printf("\n\n已找到%s同学\n", posData);
	printf("1、姓名\n");
	printf("2、学号\n");
	printf("3、电话\n");
	printf("4、QQ\n");
	printf("5、部门编号\n");
	printf("6、返回");
	printf("\n\n请输入您要修改的信息：");
	k = scanf("%d", &change_choice);
	while (1)
	{
		if ((change_choice != 1 && change_choice != 2 && change_choice != 3 && change_choice != 4 && change_choice != 5 && change_choice != 6 && k == 1) || (k != 1))
		{
			if (k != 1)
			{
				getchar();
			}
			printf("您输入的数字有误！！\n\n");
			Sleep(1000);
			system("cls");
		}
		else
		{
			printf("\n\n请稍后....");
			Sleep(1000);
			system("cls");
			break;
		}
		change_choice = NULL;
		printf("1、姓名\n");
		printf("2、学号\n");
		printf("3、电话\n");
		printf("4、Qn\n");
		printf("5、部门编号\n");
                printf("6、返回");
		printf("\n\n请重新输入您要修改的信息：");
		k = scanf("%d", &change_choice);
	}
	switch (change_choice)
	{
	case 1:
		system("cls");
		printf("请输入姓名：");
		info1 = posNode1->data;
		scanf("%s",info1.name);
		//strcpy(info1.name, "黄hh");
		posNode1->data = info1;
		//printf("%s", info1.name);
		printf("\n\n修改成功!!");
		Sleep(1000);
		system("pause");
		system("cls");
		return List1;
		break;
	case 2:
		system("cls");
		printf("请输入学号：");
		info1 = posNode1->data;
		scanf("%s",info1.num);
		posNode1->data = info1;
		//printf("%s", info1.name);
		printf("\n\n修改成功!!");
		Sleep(1000);
		system("pause");
		system("cls");
		return List1;
		break;
	case 3:
		system("cls");
		printf("请输入电话：");
		info1 = posNode1->data;
		scanf("%s",info1.tele);
		//strcpy(info1.name, "黄hh");
		posNode1->data = info1;
		//printf("%s", info1.tele);
		printf("\n\n修改成功!!");
		Sleep(1000);
		system("pause");
		system("cls");
		return List1;
		break;
	case 4:
		system("cls");
		printf("请输入qq：");
		info1 = posNode1->data;
		scanf("%s",info1.qq);
		//strcpy(info1.name, "黄hh");
		posNode1->data = info1;
		//printf("%s", info1.name);
		printf("\n\n修改成功!!");
		Sleep(1000);
		system("pause");
		system("cls");
		return List1;
		break;
	case 5:
                system("cls");
                k=info1.department_num;
                info1 = posNode1->data;
                while(1)
                {
                        printf("请输入新的部门编号：");
                        scanf("%d",&info1.department_num);
                        if (k==info1.department_num)
                        {
                                printf("\n\n该部门为%s同学原来所属部门，请重新输入！！",posData);
                                Sleep(1000);
                        }else
                        {
                                break;
                        }
                        system("cls");
                }
                posNode1->data = info1;
                printf("\n\n修改成功!!");
                Sleep(1000);
                system("pause");
                system("cls");
                return List1;

                break;
	case 6:
		return 0;
		break;
	}
	//free(p1);
	//free(posNode1);
	return List1;
}
//任意位置删除
void deleteNode(struct Node* List, char* posData)
{
	struct Node* p = List;
	struct Node* posNode = List->next;
	while (strcmp(posNode->data.name, posData) != 0)
	{
		/*原始方法
		p=p->next;
		posNode=posNode->next;
		*/
		//快捷方法

		p = posNode;
		posNode = p->next;
		if (posNode == NULL)
		{
			printf("\n\n未找到！！");
			return;
		}
	}
	p->next = posNode->next;
	free(posNode);
	printf("\n\n删除成功！！");
}

//全局变量：
char t1[100] = "暂无";
char t2[100] = "暂无";
char t3[100] = "暂无";
char t4[100] = "暂无";
char t5[100] = "暂无";
char t6[100] = "暂无";


//函数声明：
int judge(char *, char *);                                       //判断输入是否正确
void task(int, int);                                              //近期任务函数
void t_text1(char*);                                                 //移动部临时任务文件
void t_text2(char*);                                                 //游戏部临时任务文件
void t_text3(char*);                                                 //硬件部临时任务文件
void t_text4(char*);                                                 //设计部临时任务文件
void t_text5(char*);                                                 //运营部临时任务文件
void t_text6(char*);                                                 //产品部临时任务文件

void t_text1(char* t1)
{
	printf("\n%s\n", t1);
	if (system("pause"))
	{
		system("cls");
	}
	system("cls");
}
void t_text2(char* t2)
{
	printf("\n%s\n", t2);
	if (system("pause"))
	{
		system("cls");
	}
	system("cls");
}
void t_text3(char* t3)
{
	printf("\n%s\n", t3);
	if (system("pause"))
	{
		system("cls");
	}
	system("cls");
}
void t_text4(char* t4)
{
	printf("\n%s\n", t4);
	if (system("pause"))
	{
		system("cls");
	}
	system("cls");
}
void t_text5(char* t5)
{
	printf("\n%s\n", t5);
	if (system("pause"))
	{
		system("cls");
	}
	system("cls");
}
void t_text6(char* t6)
{
	printf("\n%s\n", t6);
	if (system("pause"))
	{
		system("cls");
	}
	system("cls");
}





//任务储存
void task(int choice, int num)
{
	switch (choice)
	{
	case 1:
		if (num == 1)
		{
			printf("移动互联网部的近期任务为：\n");
			t_text1(t1);
		}
		break;
	case 2:
		if (num == 1)
		{
			printf("游戏部的近期任务为：\n");
			t_text2(t2);
		}
		break;
	case 3:
		if (num == 1)
		{
			printf("硬件部的近期任务为：\n");
			t_text3(t3);
		}
		break;
	case 4:
		if (num == 1)
		{
			printf("设计部的近期任务为：\n");
			t_text4(t4);
		}
		break;
	case 5:
		if (num == 1)
		{
			printf("运营部的近期任务为：\n");
			t_text5(t5);
		}
		break;
	case 6:
		if (num == 1)
		{
			printf("产品部的近期任务为：\n");
			t_text6(t6);
		}
		break;
	}

}

int judge(char *name, char *password)
{
	char Minister[10] = "minister";
	char Member[10] = "member";
	char password_min[20] = "iamanartical2333";
	char password_mem[20] = "iloveima2333";
	if ((strcmp(name, Minister) == 0) || (strcmp(name, Member) == 0))
	{
		if ((strcmp(password, password_mem) == 0 && (strcmp(name, Member) == 0)) ||
			(strcmp(password, password_min) == 0) && (strcmp(name, Minister) == 0))
		{
			printf("输入正确！！！\n登录成功\n\n");
			Sleep(1000);
			system("cls");
		}
		else
		{
			printf("您输入的密码有误！！！\n\n");
			Sleep(1000);
			system("cls");
			return 1;
		}
	}
	else
	{
		printf("您输入的账号有误\n");
		Sleep(1000);
		system("cls");
		return 1;
	}
	return 0;
}

int exit_ptrfree(char* name,char* password,struct Node* List1,struct student info1,struct student *p1)
{
        system("cls");
        char result[10]="";
        printf("\n\n是否想要退出？\n");
        scanf("%s",result);
        while(1)
        {
                if (strcmp(result,"yes")==0)
                {
                        free(name);
                        name = NULL;
                        free(password);
                        password = NULL;
                        free(List1);
                        List1=NULL;
                        free(p1->name);
                        free(p1->num);
                        free(p1->tele);
                        free(p1->qq);
                        //free(posData);
                        exit(0);
                        return 1;
                }
                if (strcmp(result,"no")==0)
                {
                        return 0;
                }
        }

}
int main()
{
	struct Node* List1 = creatList();
	//struct student info1;
	//struct student *p1=&info1;
	int choice1;
	int k;                                                  //储存scanf的返回值！！
	int num;                                                //选择部门内的选项序号
	int choice;                                             //选择部门的序号
	int result;                                             //接收返回值
	char *name = NULL;                                        //储存用户名
	name = (char*)malloc(sizeof(char) * 10);
	char *password = NULL;                                    //储存密码
	password = (char*)malloc(sizeof(char) * 20);
	//通过循环来实现重复输入！！
	while (1)
	{
		printf("\n\n欢迎使用IMA部员管理系统\n\n");
		printf("账号：");
		scanf("%s", name);
		while(1)
                {
                        if (strcmp(name,"exit")==0)
                        {
                                result=exit_ptrfree(name,password,List1,info1,p1);
                                system("cls");
                                printf("\n\n欢迎使用IMA部员管理系统\n\n");
                                printf("账号：");
                                scanf("%s", name);
                        }
                        else
                        {
                                break;
                        }
                }
                printf("密码：");
                scanf("%s", password);
                while (1)
                {
                        printf("\n");
                        result = judge(name, password);
                        if (result == 0)
                        {
                                break;
                        }
                        else
                        {
                                printf("\n\n欢迎使用IMA部员管理系统\n\n");
                                printf("账号：");
                                scanf("%s", name);
                                while(1)
                                {
                                        if (strcmp(name,"exit")==0)
                                        {
                                                result=exit_ptrfree(name,password,List1,info1,p1);
                                                system("cls");
                                                printf("\n\n欢迎使用IMA部员管理系统\n\n");
                                                printf("账号：");
                                                scanf("%s", name);
                                        }
                                        else
                                        {
                                                break;
                                        }
                                }
                                //printf("%s",name);
                                printf("密码：");
                                scanf("%s", password);
                        }



                }





		/*              释放空间
		free(name);
		name=NULL;
		free(password);
		password=NULL;
		*/

		//分情况执行：部员和部长

		while (1)
		{
			if (*(name + 1) == 'e')
			{
				//部员
				//部门选择：
				choice = NULL;
				printf("部员登录中...\n\n");
				printf("\n1、移动互联网部\n");
				printf("2、游戏部\n");
				printf("3、硬件部\n");
				printf("4、设计部\n");
				printf("5、运营部\n");
				printf("6、产品部\n");
				printf("7、退出登录");
				printf("\n\n请选择：");
				scanf("%d", &choice);
				while (1)
				{
					if ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5) && (choice != 6) && (choice != 7)/*&&(scanf("%d",&choice)!=1)*/)
					{
						getchar();
						system("cls");
						printf("部员登录中...\n\n");
						printf("\n1、移动互联网部\n");
						printf("2、游戏部\n");
						printf("3、硬件部\n");
						printf("4、设计部\n");
						printf("5、运营部\n");
						printf("6、产品部\n");
						printf("7、退出登录");
						printf("\n\n输入错误！！\n");
						printf("请重新输入：");

						scanf("%d", &choice);
						if ((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4) || (choice == 5) || (choice == 6) || (choice == 7))
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				if (choice == 7)
				{
					Sleep(1000);
					system("cls");
					printf("正在退出，请稍后...");
					Sleep(1000);
					system("cls");
					break;
				}
				while (1)
				{
					switch (choice)
					{
					case 1:
						Sleep(1000);
						system("cls");
						num = NULL;
						printf("移动互联网部：\n\n");
						printf("1、近期任务\n");
						printf("2、返回\n\n");
						printf("请选择：");
						k = scanf("%d", &num);

						while (1)
						{
							if (num == 1 || num == 2)
							{
								printf("\n\n请稍后....");
								Sleep(1000);
								system("cls");
								break;
							}
							else
							{
								if (scanf("%d", &num) != 1)
								{
									getchar();
								}
								printf("您输入的数字有误！！\n\n");
								Sleep(1000);
								system("cls");
							}
							//if (num!=1&&num!=2)
							if ((num != 1 && num != 2 && k == 1) || (k != 1))
								//if( (( (num!=1 && num!=2   ) && (scanf("%d",&num)!=1)))||(scanf("%d",&num)==1&&num!=1&&num!=2) )

							{
								//if ( scanf("%d",&num)==1 )

								//fflush(stdin);
								if (k != 1)
								{
									getchar();
								}

								printf("您输入的数字有误！！\n\n");
								Sleep(1000);
								system("cls");
							}
							else
							{
								printf("\n\n请稍后....");
								Sleep(1000);
								system("cls");
								break;
							}
							num = NULL;
							printf("移动互联网部：\n\n");
							printf("1、近期任务\n");
							printf("2、返回\n\n");
							printf("请重新输入：");
							k = scanf("%d", &num);
						}
						if (num == 1)
						{
							task(choice, num);
						}
						if (num == 2)
						{
							break;
						}
						break;
					case 2:
						Sleep(1000);
						system("cls");
						num = NULL;
						printf("游戏部：\n\n");
						printf("1、近期任务\n");
						printf("2、返回\n\n");
						printf("请选择：");
						k = scanf("%d", &num);
						while (1)
						{
							if ((num != 1 && num != 2 && k == 1) || (k != 1))
							{
								if (k != 1)
								{
									getchar();
								}
								printf("您输入的数字有误！！\n\n");
								Sleep(1000);
								system("cls");
							}
							else
							{
								printf("\n\n请稍后....");
								Sleep(1000);
								system("cls");
								break;
							}
							printf("游戏部：\n\n");
							printf("1、近期任务\n");
							printf("2、返回\n\n");
							printf("请重新输入：");
							k = scanf("%d", &num);
						}
						task(choice, num);
						break;
					case 3:
						Sleep(1000);
						system("cls");
						num = NULL;
						printf("硬件部：\n\n");
						printf("1、近期任务\n");
						printf("2、返回\n\n");
						printf("请选择：");
						k = scanf("%d", &num);
						while (1)
						{
							if ((num != 1 && num != 2 && k == 1) || (k != 1))
							{
								if (k != 1)
								{
									getchar();
								}
								printf("您输入的数字有误！！\n\n");
								Sleep(1000);
								system("cls");
							}
							else
							{
								printf("\n\n请稍后....");
								Sleep(1000);
								system("cls");
								break;
							}
							printf("硬件部：\n\n");
							printf("1、近期任务\n");
							printf("2、返回\n\n");
							printf("请重新输入：");
							k = scanf("%d", &num);
						}
						task(choice, num);
						break;
					case 4:
						Sleep(1000);
						system("cls");
						num = NULL;
						printf("设计部：\n\n");
						printf("1、近期任务\n");
						printf("2、返回\n\n");
						printf("请选择：");
						k = scanf("%d", &num);
						while (1)
						{
							if ((num != 1 && num != 2 && k == 1) || (k != 1))
							{
								if (k != 1)
								{
									getchar();
								}
								printf("您输入的数字有误！！\n\n");
								Sleep(1000);
								system("cls");
							}
							else
							{
								printf("\n\n请稍后....");
								Sleep(1000);
								system("cls");
								break;
							}
							printf("设计部：\n\n");
							printf("1、近期任务\n");
							printf("2、返回\n\n");
							printf("请重新输入：");
							k = scanf("%d", &num);
						}
						task(choice, num);
						break;
					case 5:
						Sleep(1000);
						system("cls");
						num = NULL;
						printf("运营部：\n\n");
						printf("1、近期任务\n");
						printf("2、返回\n\n");
						printf("请选择：");
						k = scanf("%d", &num);
						while (1)
						{
							if ((num != 1 && num != 2 && k == 1) || (k != 1))
							{
								if (k != 1)
								{
									getchar();
								}
								printf("您输入的数字有误！！\n\n");
								Sleep(1000);
								system("cls");
							}
							else
							{
								printf("\n\n请稍后....");
								Sleep(1000);
								system("cls");
								break;
							}
							printf("运营部：\n\n");
							printf("1、近期任务\n");
							printf("2、返回\n\n");
							printf("请重新输入：");
							k = scanf("%d", &num);
						}
						task(choice, num);
						break;
					case 6:
						Sleep(1000);
						system("cls");
						num = NULL;
						printf("产品部：\n\n");
						printf("1、近期任务\n");
						printf("2、返回\n\n");
						printf("请选择：");
						k = scanf("%d", &num);
						while (1)
						{
							if ((num != 1 && num != 2 && k == 1) || (k != 1))
							{
								if (k != 1)
								{
									getchar();
								}
								printf("您输入的数字有误！！\n\n");
								Sleep(1000);
								system("cls");
							}
							else
							{
								printf("\n\n请稍后....");
								Sleep(1000);
								system("cls");
								break;
							}
							printf("产品部：\n\n");
							printf("1、近期任务\n");
							printf("2、返回\n\n");
							printf("请重新输入：");
							k = scanf("%d", &num);
						}
						task(choice, num);
						break;
					default:
						printf("输入的数字有误！！");
						Sleep(1000);
						system("cls");
						break;


					}
					break;
				}


			}
			else
			{
				//部长
				printf("部长登录中..\n\n");
				printf("\n1、移动互联网部\n");
				printf("2、游戏部\n");
				printf("3、硬件部\n");
				printf("4、设计部\n");
				printf("5、运营部\n");
				printf("6、产品部\n");
				printf("7、退出登录");
				printf("\n\n请选择：");
				scanf("%d", &choice);
				while (1)
				{
					if ((choice != 1) && (choice != 2) && (choice != 3) && (choice != 4) && (choice != 5) && (choice != 6) && (choice != 7)/*&&(scanf("%d",&choice)!=1)*/)
					{
						getchar();
						system("cls");
						printf("部员登录中...\n\n");
						printf("\n1、移动互联网部\n");
						printf("2、游戏部\n");
						printf("3、硬件部\n");
						printf("4、设计部\n");
						printf("5、运营部\n");
						printf("6、产品部\n");
						printf("7、退出登录");
						printf("\n\n输入错误！！\n");
						printf("请重新输入：");

						scanf("%d", &choice);

						if ((choice == 1) || (choice == 2) || (choice == 3) || (choice == 4) || (choice == 5) || (choice == 6) || (choice == 7))
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				if (choice == 7)
				{
					Sleep(1000);
					system("cls");
					printf("正在退出，请稍后...");
					Sleep(1000);
					system("cls");
					break;
				}
				while (1)
				{
					switch (choice)
					{
					case 1:
						while (1)
						{
							Sleep(1000);
							system("cls");
							num = NULL;
							printf("移动互联网部：\n\n");
							printf("\n1、查看近期任务\n");
							printf("2、布置任务\n");
							printf("3、部员管理\n");
							printf("4、返回\n\n");
							printf("请选择：");
							k = scanf("%d", &num);
							if (num == 4)
							{
								printf("\n\n请稍候，正在返回...");
								Sleep(1000);
								system("cls");
								break;
							}
							while (1)
							{
								while (1)
								{
									if ((num != 1 && num != 2 && num != 3 && num != 4 && k == 1) || (k != 1))
									{
										if (k != 1)
										{
											getchar();
										}
										printf("您输入的数字有误！！\n\n");
										Sleep(1000);
										system("cls");
									}
									else
									{
										printf("\n\n请稍后....");
										Sleep(1000);
										system("cls");
										break;

									}
									num = NULL;
									printf("移动互联网部：\n\n");
									printf("\n1、查看近期任务\n");
									printf("2、布置任务\n");
									printf("3、部员管理\n");
									printf("4、返回\n\n");
									printf("请重新输入：");
									k = scanf("%d", &num);
									break;
								}
								switch (num)
								{
								case 1:
									task(choice, num);
									break;
								case 2:
									//布置任务：
									printf("请输入任务内容：\n");
									scanf("\t%s", t1);
									printf("\n\n任务已布置！！");
									Sleep(1000);
									system("cls");
									break;
								case 3:
									while (1)
									{
										choice1 = NULL;
										printf("部员管理：\n");
										printf("\n1、新部员加入\n");
										printf("2、部员资料修改\n");
										printf("3、部员删除\n");
										printf("4、查看部门成员\n");
										printf("5、返回\n");
										printf("\n\n请选择：");
										scanf("%d", &choice1);
										while (1)
										{
											if ((choice1 != 1) && (choice1 != 2) && (choice1 != 3) && (choice1 != 4) && (choice1 != 5)/*&&(scanf("%d",&choice)!=1)*/)
											{
												getchar();
												system("cls");
												printf("部员管理：\n");
												printf("\n1、新部员加入\n");
												printf("2、部员资料修改\n");
												printf("3、部员删除\n");
												printf("4、查看部门成员\n");
												printf("5、返回\n");
												printf("\n\n输入错误！！\n");
												printf("请重新输入：");
												scanf("%d", &choice1);
												if ((choice1 == 1) || (choice1 == 2) || (choice1 == 3) || (choice1 == 4) || (choice1 == 5))
												{
													break;
												}
											}
											else
											{
												break;
											}
										}

										if (choice1 == 5)
										{
											break;
										}
										char name_change[20] = "";
										char name[100] = "";
										switch (choice1)
										{
										case 1:
											printf("\n\n请稍候...");
											Sleep(1000);
											system("cls");
											printf("\n请输入新成员的个人信息：\n姓名\t\t学号\t\t电话\t\tQQ\t\t部门编号\n");
											scanf("%s %s %s %s %d", info1.name, info1.num, info1.tele, info1.qq,&info1.department_num);
											insertNode(List1, info1);
											printf("\n\n输入成功！！");
											Sleep(1000);
											system("cls");
											break;
										case 2:
											printf("\n\n请稍候...");
											Sleep(1000);
											system("cls");
											printf("请输入您要修改的成员名称：");
											scanf("%s", name_change);
											List1 = changeNode(List1, name_change, info1, p1);
											break;
										case 3:
											printf("\n\n请稍候...");
											Sleep(1000);
											system("cls");
											printf("请输入您要删除的学生姓名：");
											scanf("%s", name);
											deleteNode(List1, name);
											Sleep(1000);
											system("cls");
											break;
										case 4:
											printf("\n\n请稍候...");
											Sleep(1000);
											system("cls");
											printList(List1,choice,info1);
											printf("\n\n");
											if (system("pause"))
											{
												system("cls");

											}
											system("cls");
											break;
										}
									}
									break;
								case 4:
									break;
								}
								break;
                                                        }
						}
						break;
					case 2:
						Sleep(1000);
						system("cls");
						printf("游戏部：\n\n");
						break;
					case 3:
						Sleep(1000);
						system("cls");
						printf("硬件部：\n\n");
						break;
					case 4:
						Sleep(1000);
						system("cls");
						printf("设计部：\n\n");
						break;
					case 5:
						Sleep(1000);
						system("cls");
						printf("运营部：\n\n");
						break;
					case 6:
						Sleep(1000);
						system("cls");
						printf("产品部：\n\n");
						break;
					default:
						Sleep(1000);
						system("cls");
						printf("您输入的数字有误！！\n\n");
						break;
					}
					break;
				}
			}
		}
	}

	return 0;
}
