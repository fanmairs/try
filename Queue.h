# ifndef QUEUE_H
# define QUEUE_H
typedef struct{
    char *base;
    int front;
    int rear;
}SqQueue;
void InitQueue(SqQueue *Q);
void EnQueue(SqQueue *Q,char c);
void CreateQueue(SqQueue *Q);
void DeQueue(SqQueue *Q,char *c);
void Get_F_Queue(SqQueue Q,char *c);
void Get_R_Queue(SqQueue Q,char *c);
# endif