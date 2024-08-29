# include <stdio.h>
# include <stdlib.h>
typedef struct LNode{
    char data;
    struct LNode * next;
}LNode,*LinkList;

void Create_LinkList(LinkList *L,int n){
    *L=(LinkList)malloc(sizeof(LNode));
    (*L)->next=NULL;
    for (int i=0;i<n;i++){
        LinkList p=(LinkList)malloc(sizeof(LNode));
        scanf("%c",&(p->data));
        //getchar();
        p->next=(*L)->next;
        (*L)->next=p;
    }
}
//第n个位置之前插入元素
void ListInsert(LinkList *L,int n,char c){
    int j=0;
    LinkList q=*L;
    while(j<n-1&&q){
        j++;
        q=q->next;
    }
    LinkList p=(LinkList)malloc(sizeof(LNode));
    if (!q||n<1) exit(EXIT_FAILURE);
    p->data=c;
    p->next=q->next;
    q->next=p;
}

void List_Delete(LinkList *L,int n,char *c){
    int j=0;
    LinkList p=*L;
    while (j<n-1&&p){
        j++;
        p=p->next;
    }
    if (!(p->next)||n<1) exit(EXIT_FAILURE);
    LinkList q=p->next;
    *c=q->data;
    p->next=q->next;
    free(q);
}                                                       

void List_Search(LinkList L,char c,int *i){
    int j=0;
    LinkList p=L;
    while(p->next){
        j++;
        p=p->next;
        if (p->data==c){
            *i=j;
            break;
        }  
        if (!(p->next)) *i=0;
    }   
}
void List_Xianshi(LinkList L){
    int j=0;
    LinkList p=L;
    while(p->next){
        j++;
        p=p->next;
        printf("%c",p->data);
        if (p->next) printf("->");  
    }
}


//LRU缓存区域
#define CACHE_SIZE 5
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
    int capacity;
} LRUCache;

LRUCache* createCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->head = NULL;
    cache->tail = NULL;
    cache->size = 0;
    cache->capacity = capacity;
    return cache;
}

void addToFront(LRUCache* cache, Node* node) {
    if (cache->head == NULL) {
        cache->head = node;
        cache->tail = node;
    } else {
        node->next = cache->head;
        cache->head->prev = node;
        cache->head = node;
    }
    cache->size++;
}

void moveToHead(LRUCache* cache, Node* node) {
    if (node == cache->head) {
        return;
    }

    if (node == cache->tail) {
        cache->tail = node->prev;
        cache->tail->next = NULL;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    node->prev = NULL;
    node->next = cache->head;
    cache->head->prev = node;
    cache->head = node;
}

void removeFromTail(LRUCache* cache) {
    if (cache->tail != NULL) {
        Node* temp = cache->tail;
        if (cache->head == cache->tail) { // If there's only one node
            cache->head = NULL;
            cache->tail = NULL;
        } else {
            cache->tail = temp->prev;
            cache->tail->next = NULL;
        }
        free(temp);
        cache->size--;
    }
}

void insert(LRUCache* cache, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (cache->size == cache->capacity) {
        removeFromTail(cache);
    }

    addToFront(cache, newNode);
}

void accessData(LRUCache* cache, int data) {
    Node* current = cache->head;
    while (current != NULL) {
        if (current->data == data) {
            moveToHead(cache, current);
            return;
        }
        current = current->next;
    }

    insert(cache, data);
}

void printCache(LRUCache* cache) {
    Node* current = cache->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
