#include<stdio.h>
#include <stdbool.h>
#include <time.h>
#include "d_linked_list.h"

void unnamed_Sorting_1(LinkedList *);
void unnamed_Sorting_2(LinkedList *);
bool compareDate(char fString[], char sString[]);

int main(void){

    FILE *fp;
    LinkedList* list;
    list = createList();

    fp = fopen("employee_data.txt","r");

    char choice, blank_space;

    while (true) {
        EMPLOYEE tmp_employee;
        fscanf(fp, "%d", &tmp_employee.emp_num);
        fscanf(fp, "%s", tmp_employee.emp_name);
        fscanf(fp, "%s", tmp_employee.job_code);
        fscanf(fp, "%s", tmp_employee.joined_date);
        addNode(list, tmp_employee);
        if (feof(fp)){
            break;
        }
    }
    printf("\nDatas from text files are imported successfully!\n\nMethods:\n1. Sort with Employee Number\t2. Sort with Date of Joining\n\n");
    
    userChoiceChecker:

    scanf("%c", &choice);
    scanf("%c", &blank_space);

    if(!(choice == '1' || choice == '2')){
        printf("Please choose method 1 or 2 to sort the employee\n");
        goto userChoiceChecker;
    }
    if(choice == '1'){
        printf("\nSorting with method 1 [with Employee Number]\n");
        unnamed_Sorting_1(list);
    }
    if(choice == '2'){
        printf("\nSorting with method 2 [with Date Joined]\n");
        unnamed_Sorting_2(list);
    }
}
bool compareDate(char fString[], char sString[]){
    int fDay = ((fString[8]-48)*10)+(fString[8]-48);
    int fMonth = ((fString[5]-48)*10)+(fString[6]-48);
    int fYear = ((fString[0]-48)*1000)+((fString[1]-48)*100)+((fString[2]-48)*10)+(fString[3]-48);
    int sDay = ((sString[8]-48)*10)+(sString[8]-48);
    int sMonth = ((sString[5]-48)*10)+(sString[6]-48);
    int sYear = ((sString[0]-48)*1000)+((sString[1]-48)*100)+((sString[2]-48)*10)+(sString[3]-48);
    if(fYear > sYear){
        return true;
    }
    if(fYear == sYear && fMonth > sMonth){
        return true;
    }
    if(fYear == sYear && fMonth == sMonth && fMonth > sMonth){
        return true;
    }
    return false;
}
void unnamed_Sorting_1(LinkedList *list){
	ListNode *nodeOuter, *nodeInner, *nodeMin;
	EMPLOYEE temp;
	nodeOuter = list->head;

	while (nodeOuter != NULL) {
		nodeMin = nodeOuter;
		nodeInner = nodeOuter->next;
		while (nodeInner != NULL) {
			if (nodeInner->employee.emp_num < nodeMin->employee.emp_num){
				nodeMin = nodeInner;
            }
			nodeInner = nodeInner->next;
		}
		if (nodeMin != nodeOuter) {
			temp = nodeMin->employee;
			nodeMin->employee = nodeOuter->employee;
			nodeOuter->employee = temp;
		}
		nodeOuter = nodeOuter->next;
	}
    displayList(list);
}
void unnamed_Sorting_2(LinkedList *list){
    time_t date1, date2;
	ListNode *nodeOuter, *nodeInner, *nodeMin;
	EMPLOYEE temp;
	nodeOuter = list->head;

	while (nodeOuter != NULL) {
		nodeMin = nodeOuter;
		nodeInner = nodeOuter->next;
		while (nodeInner != NULL) {
            if (compareDate(nodeMin->employee.joined_date,nodeInner->employee.joined_date)){
				nodeMin = nodeInner;
            }
			nodeInner = nodeInner->next;
		}
		if (nodeMin != nodeOuter) {
			temp = nodeMin->employee;
			nodeMin->employee = nodeOuter->employee;
			nodeOuter->employee = temp;
		}
		nodeOuter = nodeOuter->next;
	}
    displayList(list);
}
