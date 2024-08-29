# ifndef TREE_H
# define TREE_H
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void Create_BiTree(BiTree *T);
void Visit(char c);
void Preorder(BiTree T);
void Inorder(BiTree T);
void Postorder(BiTree T);
void ShuangQin(BiTree T,char e,char *c);
void XiongDi(BiTree T,char e,char *c);
void Find_Child(BiTree T,char c,char* c1,char* c2);
# endif