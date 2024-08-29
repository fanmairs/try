# ifndef GRAPH_H
# define GRAPH_H
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
void Addarc(ALGraph *G,int info,GraphKind K);
void Create_Graph(ALGraph *G,int numVertices,int numArc,GraphKind K);
void _Visit(char c);
void DFS(ALGraph G,int v,int *ved);
void DFSTraverse(ALGraph G);

int Locatedvex(ALGraph G,char c);
void BFTSTraverse(ALGraph G);
ArcNode* Find_FirstVex(ALGraph G,char c);
ArcNode* Find_NextVex(ALGraph G,ArcNode *p);
#endif