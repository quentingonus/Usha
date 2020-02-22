#include<stdio.h>
#include <stdbool.h>

typedef struct employee {
    int emp_num;
    char emp_name[50];
    char job_code[8];
    char joined_date[40];
} EMPLOYEE;

int main(void){

    FILE *fp;

    fp = fopen("employee_data.txt","r");

    char choice, blank_space;

    while (true) {
        EMPLOYEE tmp_employee;
        fscanf(fp, "%d", &tmp_employee.emp_num);
        fscanf(fp, "%s", tmp_employee.emp_name);
        fscanf(fp, "%s", tmp_employee.job_code);
        fscanf(fp, "%s", tmp_employee.joined_date);
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
        printf("Sorting with method 1 [with Employee Number]\n");
    }
    if(choice == '2'){
        printf("Sorting with method 2 [with Date Joined]\n");
    }
}
