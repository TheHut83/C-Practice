//
// Created by TinA on 25/01/2024.
//
#include "stdio.h"
typedef struct{
    int id;
    float score;
}ta;
int main(){
    ta outRecord={8,10.10};
    ta inRecord;
    FILE *fptr;
    fptr = fopen("record.bin","wb");
    if (fptr==NULL){
        perror("File Opening Failed\n");
        return -1;
    }
    fwrite(&outRecord,sizeof(ta),1,fptr);
    fclose(fptr);

    fptr=fopen("record.bin","rb");
    if(fptr==NULL){
        perror("File Opening Failed");
        return -1;
    }
    fread(&inRecord,sizeof(ta),1,fptr);
    printf("Our Record is:\nID:%d\nScore:%lf\n",inRecord.id, inRecord.score);
    fclose(fptr);


    return 0;
}