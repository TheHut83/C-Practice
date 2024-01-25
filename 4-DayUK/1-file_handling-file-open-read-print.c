//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"

int main(){
    double number=0.0;
    FILE *fptr;
    fptr = fopen("number.txt", "w");

    if (fptr == NULL){
        printf("File Opening Failed");
    }else{
        double ii=0.1;
        printf("File Opening Success\n");
        for(int i=0; i<10; i++){
            fprintf(fptr, "%lf\n", ii);
            ii++;
        }
    }

    fclose(fptr);

    fptr= fopen("number.txt","r");
    if (fptr==NULL){
        perror("File Opening Failed\n");
        return -1;
    }
    while(fscanf(fptr,"%lf",&number)!=EOF){
        printf("data inside file: %lf\n", number);
    }
    fclose(fptr);

    return 0;
}