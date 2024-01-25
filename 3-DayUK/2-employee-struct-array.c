//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"

struct data{
    int e_id;
    int age;
    char name[1];
    int ph;
    char address;
};
int main(){
    struct data employee[1000];
    employee[0].e_id=101;
    employee[0].age=25;
    employee[0].name="ta";

    printf("Employee ID: %d\n", employee[0].e_id);
    printf("Employee Age: %d\n", employee[0].age);
    return 0;
}