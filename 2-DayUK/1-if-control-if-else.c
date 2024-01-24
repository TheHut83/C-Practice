//
// Created by TinA on 23/01/2024.
//
#include "stdio.h"

int main(){
    int age=0;
    printf("Enter your age:");
    scanf("%d", &age);
    if(age<19){
        printf("You can't play game\n");
    }else{
        for(int x=0; x<age; x++){
            printf("%d - %d\n", x, age);
        }
    }

    return 0;
}