//
// Created by TinA on 29/01/2024.
//
#include "stdio.h"
typedef struct{
    char my_arr[30];
    char my_arr2[30];
}TA;

struct data{
    char str_arr[30];
};
int main(){
    TA ourData;
    struct data Desti;
    int a=97;
    for(int i=0; i<26; i++){
        ourData.my_arr[i]=a;
        printf("%c",ourData.my_arr[i]);
        a++;
    }
    printf("\n%s",ourData.my_arr);

    int length=0;
    for(int a=0; a<30; a++){
        if(ourData.my_arr[a] != "\0"){
            length++;
        }else{
            break;
        }
    }
    printf("\nlength: %d",length);
    for(int z=0; z<length; z++){
        Desti.str_arr[z]=ourData.my_arr[z];
    }
    printf("\nData in Destination:%s",Desti.str_arr);

    return 0;
};