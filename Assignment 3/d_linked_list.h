// Declarations for a doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct employee {
    int emp_num;
    char emp_name[50];
    char job_code[8];
    char joined_date[40];
} EMPLOYEE;

typedef struct ListNode
{
    EMPLOYEE employee;
    struct ListNode *prev;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList
{
    ListNode* head;
} LinkedList;

LinkedList* createList(void);
ListNode* createNode(EMPLOYEE);

void addNode(LinkedList*, EMPLOYEE);
void displayList(LinkedList*);
int sizeList(LinkedList*);
ListNode* deleteNode(LinkedList*, EMPLOYEE);
bool isEmpty(LinkedList*);
