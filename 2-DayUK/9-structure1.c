//
// Created by TinA on 24/01/2024.
//
#include "stdio.h"

struct my_struct{
    int age;
    int fav_char;
};

int main(){
    struct my_struct data;
    data.age=10;
    data.fav_char='Z';

    printf("Date age: %d\n", data.age);
    printf("Date char: %c\n", data.fav_char);

    return 0;
}