# ifndef STACK_H
# define STACK_H

typedef struct {
    char *base,*top;
    int stacksize;
}SqStack;
void InitStack(SqStack *S);
void Push(SqStack *S,char c);
void Pop(SqStack *S,char *c);
void GetTop(SqStack S,char *c);

#endif