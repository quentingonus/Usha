// Declarations for a doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ITEM;

typedef struct ListNode
{
    ITEM key;
    struct ListNode *prev;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList
{
    ListNode* head;
} LinkedList;

LinkedList* createList(void);
ListNode* createNode(ITEM);

void addNode(LinkedList*, ITEM);
void displayList(LinkedList*);
int sizeList(LinkedList*);
ListNode* deleteNode(LinkedList*, ITEM);
bool isEmpty(LinkedList*);
