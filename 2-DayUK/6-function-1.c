//
// Created by TinA on 24/01/2024.
//
#include "stdio.h"

int testfunction();
char testcharfunction();
int main(){

    testfunction();
    testcharfunction();
    return 0;
}

    int testfunction(){
    int a=10;
    printf("a = %d This is a test int function\n", a);
    return 0;
    }

    char testcharfunction(){
    char a='Y';
    printf("a = %c This is a test char function\n", a);
    return 0;
}