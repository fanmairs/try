# include <stdio.h>
# include <stdlib.h>
# define MAXQUEUESIZE 100
typedef struct{
    char *base;
    int front;
    int rear;
}SqQueue;
void InitQueue(SqQueue *Q){
    Q->base=(char*)malloc(sizeof(char)*MAXQUEUESIZE);
    if (!Q->base) exit (EXIT_FAILURE);
    Q->front=Q->rear=0;
}
void EnQueue(SqQueue *Q,char c){
    if ((Q->rear+1)%MAXQUEUESIZE==Q->front) exit(EXIT_FAILURE);
    Q->base[Q->rear]=c;
    Q->rear=(Q->rear+1)%MAXQUEUESIZE;
}
void CreateQueue(SqQueue *Q){
    int n;
    char c;
    InitQueue(Q);
    printf("请输入循环队列的长度：");
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        c=getchar();
        getchar();
        EnQueue(Q,c);
    }
}
void DeQueue(SqQueue *Q,char *c){
    if (Q->front==Q->rear) exit(EXIT_FAILURE);
    *c=Q->base[Q->front];
    Q->front=(Q->front+1)%MAXQUEUESIZE;
}
void Get_F_Queue(SqQueue Q,char *c){
    *c=Q.base[Q.front];
}
void Get_R_Queue(SqQueue Q,char *c){
    *c=Q.base[--Q.rear];
}