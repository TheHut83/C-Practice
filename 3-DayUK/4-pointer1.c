//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"
int main(){
    //in the below a holds the address of the location where it has the value 10
    //p is pointing to the address of a and which also now has the value 10
    int a=10;
    int *p = &a;

    printf("Address of a is %x\n", &a);
    printf("Value inside the address of a is %d\n", a);
    printf("Address of pointer p itself is %x\n", &p);
    printf("Address of pointer p pointing to is %x\n",p);//in this case it's the same as "a" address because it's pointing to "a" address
    printf("Value inside the address of p is %d\n", *p);// in this case it's 10, the same as the value holds in "a" address


    return 0;
}