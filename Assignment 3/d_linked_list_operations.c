#include<stdio.h>
#include<stdlib.h>
#include "d_linked_list.h"

//Creates an empty list and returns the pointer to it
LinkedList* createList(void) {
    LinkedList* temp = (LinkedList*)malloc(sizeof(LinkedList));
    temp->head = NULL;
    return(temp);
}

//Create an empty node for the list and returns a pointer to it.
ListNode* createNode(EMPLOYEE in_employee) {
    ListNode* temp;
    temp = (ListNode*)malloc(sizeof(ListNode));
    if(temp == NULL) {
	exit(false);
    }
    else {
        temp->employee = in_employee;
        temp->prev = NULL;
        temp->next = NULL;
        return(temp);
    }
}

void addNode(LinkedList* list, EMPLOYEE employee) {
    ListNode* temp = list->head;
    ListNode* node = createNode(employee);
    if(isEmpty(list)) {
        list->head = node;
    }
    else {
        while(temp->next != NULL){
            temp = temp->next;
        }
	    node->prev = temp;
        temp->next = node;
    }
}
void displayList(LinkedList* list) {
    ListNode* temp = list->head;

    int i = 1;
    printf("\n");
    if(isEmpty(list))
        printf("List is empty. Nothing to display.\n");
    else {
        printf("#\tEmployee_Number\tEmployee_Name\t\tJob_Code\tDate_of_Joining\n\n");
        while(temp != NULL) {
            printf("%d\t%d\t\t%s\t\t\t%s\t\t%s\n",i, temp->employee.emp_num, temp->employee.emp_name, temp->employee.job_code, temp->employee.joined_date);
            i++;
            temp = temp->next;
        }
    }
}

int sizeList(LinkedList* list) {
	ListNode *temp;
	int count = 0;

	temp = list->head;
	if (!isEmpty(list)) {
		count++;
        	while(temp->next != '\0') {
			count++;
            		temp = temp->next;
		}
	}
	return count;
}

bool isEmpty(LinkedList* list) {
	
	if (list->head == NULL)
		return true;
	else
		return false;
}
