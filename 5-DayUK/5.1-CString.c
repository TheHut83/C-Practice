//
// Created by TinA on 29/01/2024.
//
#include "stdio.h"
struct mystruct{
    char *myarr;
};
int main(){
    struct mystruct data;
    data.myarr="we can use pointer to write in array in structure";
    printf("Data: %s",data.myarr);

    return 0;
}