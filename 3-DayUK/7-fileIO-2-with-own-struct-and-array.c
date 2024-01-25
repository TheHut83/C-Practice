//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"
#include "stdlib.h"
typedef struct db{
    char data[100];
}ta;

int main(){
    ta db[100];
    FILE *fptr;
    int index=0;
    fptr = fopen("filter.txt","r");
    if (fptr == NULL){
        printf("File Opening Failed\n");
    }else{
        printf("File Opening Success\n");
        while(fgets(db[index].data,100,fptr)!=NULL){
            printf("data: %s\n",db[index].data); //*****Question->why it gets both int and char even though the data[100] buffer is declared as char
            index ++;
        }
    }
    for(int i=0; i<index; ++i){
        printf("Your Data are: %s\n",db[i].data);
    }
    fclose(fptr);

   return 0;
}