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
ListNode* createNode(ITEM key) {
    ListNode* temp;
    temp = (ListNode*)malloc(sizeof(ListNode));
    if(temp == NULL) {
        printf("ERROR - Malloc failed!\n");
	exit(false);
    }
    else {
        printf("\nSUCCESS - Malloc successfully allocated memory!");
        temp->key = key;
        temp->prev = NULL;
        temp->next = NULL;
        return(temp);
    }
}

//Adds a new node to the list with the desired value.
void addNode(LinkedList* list, ITEM key) {
    //Storing the head of the list in a temporary pointer
    ListNode* temp = list->head;

    //Creating a new node with the given key
    ListNode* node = createNode(key);

    //Checking if the head is pointing to an empty node
    if(isEmpty(list)) {
        list->head = node;
        printf("\nFirst element added in the list!\n\n");
    }
    else {
        //Traversing from the head to the end of the list
        while(temp->next != NULL)
            temp = temp->next;

        //Adding the new node at the end of the list
        //The last element in the list now points to NULL
	node->prev = temp;
        temp->next = node;
        printf("New node added to the list!\n\n");
    }
}

//Displays the elements of the list in sequential order
void displayList(LinkedList* list) {
    ListNode* temp = list->head;

    int i = 1;
    printf("\n");
    if(isEmpty(list))
        printf("List is empty. Nothing to display.\n");
    else {
        while(temp != NULL) {
            printf("List element %d is: \t%d\n", i, temp->key);
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
		//Traversing from the head to the end of the list
        	while(temp->next != '\0') {
			count++;
            		temp = temp->next;
		}
	}
	return count;
}

//Deletes the node (first occurrence) whose key matches the given key
// Return the deleted node
ListNode* deleteNode(LinkedList* list, ITEM key) {
    //Pointers to current and previous nodes
    ListNode *curr, *prev, *deletedNode;
    prev = curr = list->head;

    deletedNode = NULL;
    printf("\n");
    if (!isEmpty(list)) {
        //Element to be deleted is the first element in the list
        //Position of the head needs to be changed
        if (curr->key == key) {
	    deletedNode = curr;
            list->head = list->head->next;
	}
        else {
            //Element to be deleted is not the first element in the list
            while (curr != NULL) { // When curr is NULL it means the item is not found in the list
                if(curr->key == key) {
                    printf("Value in the node matches the key. Deleting node...\n");
                    //Pointing the next pointer of previous node to the next pointer of current node in case key matches
		    prev->next = curr->next;
		    deletedNode = curr;
		    if (curr->next != NULL) // To check deleted node is not the last node in the list
		    	curr->next->prev = prev;
                    return deletedNode;
                }
                else {
                    printf("Value in the node does not match the key. Moving to the next node...\n");
                    //Saving the current pointer in previous pointer in case key does not match
                    prev = curr;
                    curr = curr->next;
                }
	    }
        }
    }
    return deletedNode;
}

bool isEmpty(LinkedList* list) {
	
	if (list->head == NULL)
		return true;
	else
		return false;
}
