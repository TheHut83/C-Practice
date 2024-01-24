//
// Created by TinA on 24/01/2024.
//
#include "stdio.h"
int main(){
    int option=0;
    int loop=10;
    while(loop>=0){
        printf("Enter some date\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("Option is 1:\n");
                break;
            case 2:
                printf("Option is 2:\n");
                break;
            case 3:
                printf("Option is 3:\n");
                break;
            default:
                printf("This is a default option\n");
                break;
        }
        loop--;
    }

    return 0;
}
