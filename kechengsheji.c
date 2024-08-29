# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "LinkList.h"
# include "Stack.h"
# include "Queue.h"
# include "Tree.h"
# include "Graph.h"

void LinkList_(){
int n;
LinkList L;
char c;
int i;
LRUCache* cache = NULL;
int cacheCapacity;
do{
printf("\n");
printf("**************单链表的基本操作及应用***************\n");
printf("* 1  创建                                         *\n");
printf("* 2  插入                                         *\n");
printf("* 3  删除                                         *\n");
printf("* 4  查找                                         *\n");
printf("* 5  显示                                         *\n");
printf("* 6  应用                                        *\n");
printf("* 7  退出                                         *\n");
printf("***************************************************\n");
printf("请选择：");
scanf("%d",&n);
getchar();
switch(n){
case 1:
	printf("--------创建单链表---------");
	printf("请输入链表长度：");
	scanf("%d",&i);
	getchar();
	Create_LinkList(&L,i);
    break;
case 2:
	printf("--------插入元素-------");
	printf("请输入插入位置：");
	scanf("%d",&i);
	getchar();
	printf("请输入插入字符：");
	scanf("%c",&c);
	getchar();
	ListInsert(&L,i,c);
	break;
case 3:
	printf("--------删除元素-------");
	printf("请输入删除字符位置：");
	scanf("%d",&i);
	List_Delete(&L,i,&c);
	printf("删除的字符为：%c",c);
	break;
case 4:
	printf("--------查找元素-------");
	printf("请输入查找的字符：");
	scanf("%c",&c);
	List_Search(L,c,&i);
	if (i!=0) printf("该字符是第%d个字符",i);
	else printf("该字符不存在");
	break;
case 5:
	printf("--------显示链表-------");
	List_Xianshi(L);
	break;
case 6:
    printf("--------应用---------");
	printf("--------应用---------\n");
                printf("请输入LRU缓存的容量：");
                scanf("%d", &cacheCapacity);
                getchar();
                cache = createCache(cacheCapacity);
                int lruChoice, data;
                do {
                    printf("\n**************LRU缓存操作***************\n");
                    printf("* 1  插入数据                             *\n");
                    printf("* 2  访问数据                             *\n");
                    printf("* 3  显示缓存                             *\n");
                    printf("* 4  退出                                 *\n");
                    printf("*****************************************\n");
                    printf("请选择：");
                    scanf("%d", &lruChoice);
                    getchar();
                    switch (lruChoice) {
                        case 1:
                            printf("请输入插入的数据：");
                            scanf("%d", &data);
                            getchar();
                            insert(cache, data);
                            break;
                        case 2:
                            printf("请输入访问的数据：");
                            scanf("%d", &data);
                            getchar();
                            accessData(cache, data);
                            break;
                        case 3:
                            printf("--------显示缓存-------\n");
                            printCache(cache);
                            break;
                        case 4:
                            break;
                        default:
                            printf("ERROR!\n");
                            break;
                    }
                } while (lruChoice != 4);
                break;
case 7: break;
default:
	printf("ERROR!");break;		
}
}while(n!=7);
}

void Stack(){ 
int n,j;
SqStack S;
InitStack(&S);
char c;
do{
printf("\n");
printf("****************栈的基本操作及应用*****************\n");
printf("* 1  进栈                                         *\n");
printf("* 2  出栈                                         *\n");
printf("* 3  取栈顶元素                                   *\n");
printf("* 4  退出                                         *\n");
printf("***************************************************\n");
printf("请选择：");
scanf("%d",&n);
getchar();
switch(n){
case 1:
	printf("--------进栈-------");
	printf("请输入进栈的字符：");
	scanf("%c",&c);
	Push(&S,c);
	break;
case 2:
	printf("--------出栈-------");
	Pop(&S,&c);
	printf("出栈的元素是%c",c);
	break;
case 3:
	printf("--------取栈顶元素-------");
	GetTop(S,&c);
	printf("栈顶元素是%c",c);
	break;
case 4:break;
default:
	printf("ERROR!");break;
}
}while(n!=4);
}
 
void Queue(){
int n;
char c;
SqQueue Q;
InitQueue(&Q);
do{
printf("\n");
printf("*************队列的基本操作及应用**************\n");
printf("* 1 入列 									  *\n");
printf("* 2 出列                                      *\n");
printf("* 3 取队头元素                                *\n");
printf("* 4 取队尾元素                                *\n");
printf("* 5 退出 *\n");
printf("***********************************************\n");
printf("请选择：");
scanf("%d",&n);
getchar();
switch(n){
case 1:
printf("---------入列-------");
printf("请输入入列的字符：");
c=getchar();getchar();
EnQueue(&Q,c);
break;
case 2:
printf("---------出列-------");
DeQueue(&Q,&c);
printf("出列的字符是：%c",c);
break;
case 3:
printf("---------取队头元素-------");
Get_F_Queue(Q,&c);
printf("队头字符是：%c",c);
break;
case 4:
printf("---------取队尾元素-------");
Get_R_Queue(Q,&c);
printf("队尾元素是：%c",c);
break;
case 5:break;
default:
printf("ERROR!");break;
}
}while(n!=5);
}

void BiTree_(){ 
int n,i;
char c,e,c1,c2;
BiTree T;
do{
printf("\n");
printf("**************二叉树的基本操作及应用***************\n");
printf("* 1  创建二叉树                                   *\n");
printf("* 2  遍历二叉树（先/中/后）                       *\n");
printf("* 3  查找双亲                                     *\n");
printf("* 4  查找兄弟                                     *\n");
printf("* 5  查找孩子                                     *\n");
printf("* 6  退出                                         *\n");
printf("***************************************************\n");
printf("请选择：");
scanf("%d",&n);
getchar();
switch(n){
case 1:
	printf("---------创建二叉树--------");
	Create_BiTree(&T);
	break;
case 2:
	printf("---------遍历二叉树-------");
	printf("先，中，后遍历分别为：\n");
    Preorder(T);printf("\n");
	Inorder(T);printf("\n");
	Postorder(T);printf("\n");
	break;
case 3:
	printf("---------查找双亲-------");
	printf("请输入要查找的节点：");
	scanf("%c",&e);
	ShuangQin(T,e,&c);
	if (c=='?') printf("未找到双亲");
	else printf("该节点双亲为%c",c);
	c='\0';
	break;
case 4:
	printf("---------查找兄弟-------");
	printf("请输入要查找的节点：");
	scanf("%c",&e);
	XiongDi(T,e,&c);
	if (c=='?') printf("未找到兄弟");
	else printf("该节点兄弟为%c",c);
	c='\0';
	break;
case 5:
printf("---------查找孩子-------");
    printf("请输入要查找的节点：");
	e=getchar();
	Find_Child(T,e,&c1,&c2);
	printf("%c %c",c1,c2);
    break;

case 6:break;
default:
	printf("ERROR!");break;
}
}while(n!=6);
}

void Graph(){  
int n,i;
int vexnum,arcnum;
char c;
ALGraph G;
do{
printf("\n");
printf("****************图的基本操作及应用*****************\n");
printf("* 1 创建（邻接矩阵/邻接表）                       *\n");
printf("* 2 深度优先遍历                                  *\n");
printf("* 3 广度优先遍历                                  *\n");
printf("* 4 找第一个邻接点                                *\n");
printf("* 5 找下一个邻接点                                *\n");
printf("* 6 退出                                          *\n");
printf("***************************************************\n");
printf("请选择：");
scanf("%d",&n);
getchar();
switch(n){
case 1:
	printf("---------创建(邻接表)-------\n");
	printf("请输入图的类型(1有向图/2有向网/3无向图/4无向网):");
    scanf("%d",&i);getchar();
	printf("请输入点和边的数量：");
	scanf("%d %d",&vexnum,&arcnum);getchar();
	Create_Graph(&G,vexnum,arcnum,i);
	break;
case 2:
    printf("---------深度优先遍历-------");
    DFSTraverse(G);
    break;
case 3:
printf("---------广度优先遍历-------");
    BFTSTraverse(G);
    break;
case 4:
    printf("---------找第一个邻接点-------");
	printf("请输入要查找的字符：");
	c=getchar();
	getchar();
	ArcNode* p=Find_FirstVex(G,c);
	break;
case 5:
    printf("---------找下一个邻接点-------");
	p=Find_NextVex(G,p);
	break;
case 6:break;
default:
	printf("ERROR!");break;
}
}while(n!=6);
}

void ShowMainMenu(){
printf("\n");
printf("*******************算法与数据结构******************\n");
printf("* 1  单链表的基本操作及应用                       *\n");
printf("* 2  栈的基本操作及应用                           *\n");
printf("* 3  队列的基本操作及应用                         *\n");
printf("* 4  树的基本操作及应用                           *\n");
printf("* 5  图的基本操作及应用                           *\n");
printf("* 6  退出                                         *\n");
printf("***************************************************\n");
}

void main(){
int n;
do{
ShowMainMenu();
printf("请选择：");
scanf("%d",&n);getchar();
switch(n){
case 1:LinkList_();break;
case 2:Stack();break;
case 3:Queue();break;
case 4:BiTree_();break;
case 5:Graph();break;
case 6:break;
default:printf("ERROR!");break;
}
}while(n!=6);
}



