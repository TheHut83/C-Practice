//
// Created by TinA on 29/01/2024.
//
#include "stdio.h"

int main(){
    FILE *fptr;
    fptr = fopen("filter.txt","a");

    if (fptr == NULL){
        perror("File Open Failed");
        return -1;
    }
    fprintf(fptr, "This is new appended data");
    fclose(fptr);

    return 0;
}