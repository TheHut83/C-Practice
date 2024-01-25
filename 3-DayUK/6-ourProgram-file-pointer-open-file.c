//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"
int main(){
    FILE *fptr; //this is file pointer
    fptr = fopen("filter.txt","w");

    if(fptr==NULL){
        printf("File Opening Failed\n");
    }else{
        printf("File Opening Success\n");
        for(int i=0; i<=10; i++){
            fprintf(fptr, "%d-Hello Embedded World!\n", i);//fprintf is writing to a file
                                                                        //this also wrote i value from 0 to 10
            //fprintf(fptr, "Hello Embedded World!\n");
        }

    }
    fclose(fptr);

    return 0;
}