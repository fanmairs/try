# ifndef LINKLIST_H
# define LINKLIST_H
#include <stdio.h>
#include <stdlib.h>

// LinkList definitions and functions
typedef struct LNode {
    char data;
    struct LNode *next;
} LNode, *LinkList;

void Create_LinkList(LinkList *L, int n);
void ListInsert(LinkList *L, int n, char c);
void List_Delete(LinkList *L, int n, char *c);
void List_Search(LinkList L, char c, int *i);
void List_Xianshi(LinkList L);

// LRUCache definitions and functions
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

LRUCache* createCache(int capacity);
void addToFront(LRUCache* cache, Node* node);
void moveToHead(LRUCache* cache, Node* node);
void removeFromTail(LRUCache* cache);
void insert(LRUCache* cache, int data);
void accessData(LRUCache* cache, int data);
void printCache(LRUCache* cache);

#endif // COMBINED_H