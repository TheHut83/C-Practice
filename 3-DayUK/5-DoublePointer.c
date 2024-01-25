//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"

int main(){
    int a=10;
    int *p=&a;
    int **pp=&p;

    printf("The address of a is %x\n", &a);
    printf("The value it holds in the address a is %d\n",a);
    printf("the address of p itself is %x\n", &p);
    printf("The value it holes in the address p is %d\n", *p);
    printf("The address of pp itself is %x\n", &pp);
    printf("The value it holds in the address pp is %d\n", **pp);

    return 0;
}