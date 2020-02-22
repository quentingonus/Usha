#include<stdio.h>
#include <stdbool.h>
#include "d_linked_list.h"

void unnamed_Sorting_1(LinkedList *);

int main(void){

    FILE *fp;
    LinkedList* list;
    list = createList();

    EMPLOYEE tmp_employee;
    tmp_employee.emp_num = 1;
    tmp_employee.emp_name[0] = 'A';
    tmp_employee.job_code[0] = '0';
    tmp_employee.joined_date[0] = '0';
    addNode(list, tmp_employee);

    EMPLOYEE tmp_employee1;
    tmp_employee1.emp_num = 2;
    tmp_employee1.emp_name[0] = 'B';
    tmp_employee1.job_code[0] = '0';
    tmp_employee1.joined_date[0] = '0';
    addNode(list, tmp_employee1);

    EMPLOYEE tmp_employee2;
    tmp_employee2.emp_num = 3;
    tmp_employee2.emp_name[0] = 'C';
    tmp_employee2.job_code[0] = '0';
    tmp_employee2.joined_date[0] = '0';
    addNode(list, tmp_employee2);

    unnamed_Sorting_1(list);
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