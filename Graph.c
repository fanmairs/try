# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "Queue.h"
typedef enum {DG=1,DN,UDG,UDN} GraphKind;

typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
    int *info;
}ArcNode;
typedef struct VNode{
    char data;
    struct ArcNode *firstarc;
}VNode,*AdjList;
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
    int kind;
}ALGraph;

void Addarc(ALGraph *G,int info,GraphKind K){
    char c1,c2;
    int i,j,w=0;
    if (info) {scanf("%c %c %d",&c1,&c2,&w);getchar();}
    else {scanf("%c %c",&c1,&c2);getchar();}
    ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
    p->info=(int *)malloc(sizeof(int));
    for(int t=0;t<G->vexnum;t++){
        if (G->vertices[t].data==c1) i=t;
        if (G->vertices[t].data==c2) j=t;
    }
    p->adjvex=j;*(p->info)=w;
    p->nextarc=G->vertices[i].firstarc;
    G->vertices[i].firstarc=p;
    G->arcnum++;
    if (K==3||K==4){
        ArcNode *p2=(ArcNode*)malloc(sizeof(ArcNode)); 
        p2->info=(int *)malloc(sizeof(int));
        p2->adjvex=i;*(p2->info)=w; 
        p2->nextarc=G->vertices[j].firstarc;
        G->vertices[j].firstarc=p2;
    }
}
void Create_Graph(ALGraph *G,int numVertices,int numArc,GraphKind K){
    G->vexnum=numVertices;G->arcnum=0;G->kind=K;
    AdjList L=(AdjList)malloc(sizeof(VNode)*numVertices);
    G->vertices=L;
    char c;
    for (int i=0;i<numVertices;i++){
        scanf("%c",&c);getchar();
        (G->vertices)[i].data=c;
        G->vertices[i].firstarc=NULL;
    }
    for (int i=0;i<numArc;i++) {
        if (K==2||K==4) Addarc(G,1,K);
        else Addarc(G,0,K);
    }   
}
void _Visit(char c){
    printf("%c",c);
}
void DFS(ALGraph G,int v,int *ved){
    if (ved[v]==0){
        _Visit(G.vertices[v].data); ved[v]=1;
        int s=0;    
        for (int i=0;i<G.vexnum;i++) if (ved[i]==0) s=1; 
        if (s) printf("->");
        ArcNode *p=G.vertices[v].firstarc;
        for (p;p!=NULL;p=p->nextarc) DFS(G,p->adjvex,ved);
    }
}
void DFSTraverse(ALGraph G){
    int visited[G.vexnum];
    for (int i=0;i<G.vexnum;i++) visited[i]=0;
    for (int i=0;i<G.vexnum;i++){
        if (!(visited[i])) DFS(G,i,visited);
    }
}
int Locatedvex(ALGraph G,char c){
    for (int i=0;i<G.vexnum;i++){
        if (G.vertices[i].data==c) return i;
    }
    return -1;
}
void BFTSTraverse(ALGraph G){
    int visited[G.vexnum];
    int i;
    SqQueue Q;
    char c;
    for(int i=0;i<G.vexnum;i++){
        visited[i]=0;
    }
    InitQueue(&Q); 
    for (int v=0;v<G.vexnum;v++){
        if (!visited[v]){
            EnQueue(&Q,G.vertices[v].data);
            while (Q.front!=Q.rear){
                DeQueue(&Q,&c);
                _Visit(c);
                i=Locatedvex(G,c);
                visited[i]=1;
                ArcNode *p=G.vertices[i].firstarc;
                for (;p;p=p->nextarc){
                    if (!visited[p->adjvex]){
                        EnQueue(&Q,G.vertices[p->adjvex].data);
                        visited[p->adjvex]=1;
                    }

                }
            }
        }
    }
    }
ArcNode* Find_FirstVex(ALGraph G,char c){
    int i=Locatedvex(G,c);
    if(i!=-1&&G.vertices[i].firstarc){ 
    ArcNode* p=G.vertices[i].firstarc;
    printf("第一个邻接点为%c\n",G.vertices[p->adjvex].data);
    return p;
    }
    printf("第一个邻接点为空\n");
    return NULL;
}
ArcNode* Find_NextVex(ALGraph G,ArcNode *p){
    if(!p||!p->nextarc){
        printf("下一个邻接点为空\n");
        return NULL;
    }
    else {
        ArcNode* q=p->nextarc;
        printf("下一个邻接点为%c\n",G.vertices[q->adjvex].data);
        return q;
    }
}