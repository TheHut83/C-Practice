//
// Created by TinA on 24/01/2024.
//
#include "stdio.h"
struct data{
    int age;
    char *name;
    int ph;
    char *address;
};

int main(){
    struct data db1Ptr, data1;
    db1Ptr.age = 20;
    db1Ptr.name = "Peter"; //Question-> why it doesn't print character
    db1Ptr.ph = 998;
    db1Ptr.address = "This is using the structure with string and pointer";

    printf("Age: %d\n",db1Ptr.age);
    printf("Name: %s\n",db1Ptr.name);
    printf("Phone: %d\n",db1Ptr.ph);
    printf("Address: %s\n",db1Ptr.address);

    return 0;
}