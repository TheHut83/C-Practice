//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"

typedef struct Date{
    int e_id;
    int age;
    char name[30];
}ta;

int main(){
    ta db1;
    db1.e_id=100;
    db1.age=25;
    printf("Own Structure > Name TA > Date Inside \nID:%d\nAge:%d", db1.e_id, db1.age);
    return 0;
}