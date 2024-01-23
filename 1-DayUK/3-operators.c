//
// Created by TinA on 23/01/2024.
//
#include "stdio.h"

int main(){

    int number=0;

    printf("Enter your number:");
    scanf("%d",&number);

    printf(" This is your number %d",number);
    return 0;
}

// integer 4 bytes -> 1 byte = 8bit -> 4 bytes = 32 bits ( 2 power 32 )
// 2 pow 32 = 4,294,967,296
// Not only positive number also negative numbers