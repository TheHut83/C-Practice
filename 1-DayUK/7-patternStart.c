//
// Created by TinA on 23/01/2024.
//
#include "stdio.h"

int main(){
    int i=0;
    int y=0;
    int z=0;
    for(i=0; i<=10; i++){
        for(y=0; y<i; y++){
            printf("*");
        }
        for(z=0; z<y*2; z++){
            printf("#");
        }
        printf("\n");
    }

    return 0;
}