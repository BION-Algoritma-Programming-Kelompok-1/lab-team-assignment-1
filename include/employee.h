#ifndef EMPLOYEE_H
#define EMPLOYEE_H

struct Employee {
    char nip[20];
    char name[50];
    char address[100];
    char phone[20];
    char position[50];
    char grade[5];
    long baseSalary;
    int overtimeHours;
    long totalSalary;
};

void inputEmployee(struct Employee *emp);
void inputOvertime(struct Employee *emp);
void listEmployees();

#endif
