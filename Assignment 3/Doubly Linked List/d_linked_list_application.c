#include<stdio.h>
#include<stdlib.h>
#include "d_linked_list.h"

int main (void)
{
    int i;
    FILE *fp;
    ITEM key;
    LinkedList* list;
    ListNode *dNode;

    //Opening the file for reading
    fp = fopen("numbers.txt", "r");
    if(fp == NULL)
        printf("Error opening file.\n");
    else
    {
        //Creating a new list
        list = createList();

// 	Checking for empty file
	// Going to the end of the file
	fseek(fp, 0, SEEK_END);
	if (ftell(fp) == 0)
		printf("\nFile is empty!\n");
	else {
		// Getting back to the beginning of the file
		fseek(fp,0,SEEK_SET);
		//Reading keys from the file and adding them to the list
        	do {
            		fscanf(fp, "%d", &key);
            		addNode(list, key);
        	} while(!feof(fp));
	}
        fclose(fp);

	// Finding size of list
	printf("\nSize of list is %d\n",sizeList(list));
        //Displaying the list
        displayList(list);

        //Deleting an element from the list
        printf("\nEnter the key of the node to be deleted\n");
        scanf("%d", &key);
        dNode = deleteNode(list, key);
	if (dNode == list->head)
		if (dNode == NULL) 
			printf("\nList is empty\n");
		else
			printf("\nDeleted item is %d\n",dNode->key); 
	else
		if (dNode == NULL)
			printf("\nItem not found in the list to delete\n");
		else
			printf("\nDeleted item is %d\n",dNode->key); 
	// Free the deleted noe
	free(dNode);

	printf("\nSize (after first deletion) of list is %d\n",sizeList(list));
        //Displaying modified list after deletion
        displayList(list);

        //Deleting another node from the list
        printf("\nEnter another key of the node to be deleted\n");
        scanf("%d", &key);
        dNode = deleteNode(list, key);
	if (dNode == list->head)
		if (dNode == NULL) 
			printf("\nList is empty\n");
		else
			printf("\nDeleted item is %d\n",dNode->key); 
	else
		if (dNode == NULL)
			printf("\nItem not found in the list to delete\n");
		else
			printf("\nDeleted item is %d\n",dNode->key); 
	// Free the deleted noe
	free(dNode);

	printf("\nSize (after second deletion) of list is %d\n",sizeList(list));
        //Displaying modified list after another deletion
        displayList(list);
    }
    return 0;
}
