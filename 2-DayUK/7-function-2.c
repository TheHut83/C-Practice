//
// Created by TinA on 24/01/2024.
//
#include "stdio.h"

void printing_fun();
int adding(int a, int b);
int main(){
    int first=10;
    int second=200;
    int result=0;

    printing_fun();
    result = adding(first,second);
    printf("This is the result - %d", result);
    return 0;
}
    void printing_fun(){
    printf("This is a printing function\n");
}

    int adding(int a, int b){
    return a+b;
}