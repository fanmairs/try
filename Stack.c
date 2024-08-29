# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define STACK_INIT_SIZE 100
# define STACKINCREMENT 10
typedef struct {
    char *base,*top;
    int stacksize;
}SqStack;
void InitStack(SqStack *S){
    S->base=(char*)malloc(sizeof(char)*STACK_INIT_SIZE);
    if (!(S->base)) exit(EXIT_FAILURE);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
}
void Push(SqStack *S,char c){
    if ((S->top)-(S->base)>=S->stacksize){
        S->base=(char*)realloc(S->base,((S->stacksize)+STACKINCREMENT)*sizeof(char));
        S->stacksize+=STACKINCREMENT;
    }
    *(S->top)=c;
    S->top++;  
}
void Pop(SqStack *S,char *c){
    if (S->base==S->top) exit(EXIT_FAILURE);
    S->top--;
    *c=*(S->top);
}
void GetTop(SqStack S,char *c){
    if (S.base==S.top) exit(EXIT_FAILURE);
    *c=*(--S.top);
}

