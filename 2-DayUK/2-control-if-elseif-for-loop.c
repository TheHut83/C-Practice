//
// Created by TinA on 23/01/2024.
//
#include "stdio.h"

int main(){
    int age=0;
    printf("Enter Your Age:");
    scanf("%d", &age);
    if (age<19){
        printf("You can't play game:\n");
    }else if(age==18){
        printf("You need a little more time\n");
    }else{
        int space=age;
        for(int x=age; x>=0; x--){

        for(int y=space; y>=0; y--){

            printf(" ");
        }
        for(int xx=0; xx<x*2; xx++){
            printf("*");
        }
        printf("\n");
        space++;
    }

    }

    return 0;
}