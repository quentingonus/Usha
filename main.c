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

    int counter = 0, i;

    while (true) {
        EMPLOYEE tmp_employee;
        fscanf(fp, "%d", tmp_employee.emp_num);
        fscanf(fp, "%s", tmp_employee.emp_name);
        fscanf(fp, "%s", tmp_employee.job_code);
        fscanf(fp, "%s", tmp_employee.joined_date);
        if (feof(fp)){
            break;
        }
        printf("%d\t%s\t%s\t%s\n",tmp_employee.emp_num,tmp_employee.emp_name,tmp_employee.job_code,tmp_employee.joined_date);
        counter++;
    }
}
