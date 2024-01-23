//
// Created by TinA on 23/01/2024.
//
#include "stdio.h"

int main(){
    int age=0;
    printf("This is program 5:\n");
    printf("Enter your age: ");
    scanf("%d", &age);

    if(age<=19){
        printf("Your can't play!\n");
    }else{
        printf("You can play!");
    }

    return 0;
}