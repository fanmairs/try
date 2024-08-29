# include <stdio.h>
# include <stdlib.h>
# include <string.h>
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void Create_BiTree(BiTree *T){
    char c;
    scanf("%c",&c);
    getchar();
    if (c==' ') {
        (*T)=NULL;
    }
    else {
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=c;
        Create_BiTree(&((*T)->lchild));
        Create_BiTree(&((*T)->rchild));
    }
}
void Visit(char c){
    printf("%c",c);
}
void Preorder(BiTree T){
    if (T){
        Visit(T->data);
        Preorder(T->lchild);
        Preorder(T->rchild);
    }
}
void Inorder(BiTree T){
    if (T){
        Inorder(T->lchild);
        Visit(T->data);
        Inorder(T->rchild);
    }
    else return;
}
void Postorder(BiTree T){
    if (T){
        Postorder(T->lchild);
        Postorder(T->rchild);
        Visit(T->data);
    }
    else return;
}
void ShuangQin(BiTree T,char e,char *c){
    if (!(*c)) *c='?';
    if (T){
        ShuangQin(T->lchild,e,c);
        ShuangQin(T->rchild,e,c);
        if (T->lchild) if (T->lchild->data==e) *c=T->data;
        if (T->rchild) if (T->rchild->data==e) *c=T->data;
    }
    else return;
}
void XiongDi(BiTree T,char e,char *c){
    if (!(*c)) *c='?';
    if (T){
        XiongDi(T->lchild,e,c);
        XiongDi(T->rchild,e,c);
        if (T->lchild&&T->rchild){
        if (T->lchild->data==e) *c=T->rchild->data;
        if (T->rchild->data==e) *c=T->lchild->data;
        }
    }

}
void Find_Child(BiTree T,char c,char* c1,char* c2){
    if (T&&T->data==c){
        if (T->lchild) *c1=T->lchild->data;
        else printf("左孩子不存在\n"); 
        if (T->rchild) *c2=T->rchild->data;
        else printf("右孩子不存在\n");
        return;
        }
    else if(T) {
        Find_Child(T->lchild,c,c1,c2);
        Find_Child(T->rchild,c,c1,c2);
    }
}

