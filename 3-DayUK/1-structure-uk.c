//
// Created by TinA on 24/01/2024.
//
#include "stdio.h"
struct data{
    int age;
    char name[30];
    int ph;
    char address;
};

int main(){
    struct data db1;
    db1.age = 20;
    db1.name[0] = "Peter";
    db1.ph = 998;
    db1.address = "a";

    printf("Age: %d\n",db1.age);
    printf("Name: %c\n",db1.name[0]);
    printf("Phone: %d\n",db1.ph);
    printf("Address: %c\n",db1.address);

    return 0;
}