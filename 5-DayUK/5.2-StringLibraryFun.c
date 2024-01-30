//
// Created by TinA on 29/01/2024.
//
#include "stdio.h"
#include "string.h"

int main(){
    char myString[]="This is first String";
    char myString2[]="\nThis is concat";
    char toAccept[30];
    strcpy(toAccept,myString);
    strcat(toAccept,myString2);
    int length=strlen(toAccept);
    printf("Processed data:%s and Length=%d",toAccept,length);

    return 0;
}