//
// Created by TinA on 24/01/2024.
//
#include "stdio.h"
int cal_option();
int add_fun(int a, int b);
int sub_fun(int a, int b);
int multi_fun(int a, int b);
int div_fun(int a, int b);
int main(){
    cal_option();
    return 0;
}

int cal_option(){
    int first_num=0;
    int second_num=0;
    int my_opt=0;
    int result=0;
    printf("This is a calculator program\n");
    printf("Enter your first number\n");
    scanf("%d", &first_num);
    printf("Enter your second number\n");
    scanf("%d", &second_num);
    printf("press 1: to add\npress 2 to sub:\npress 3 to multi\npress 4 to div\n");
    scanf("%d", &my_opt);
    switch(my_opt){
        case 1:
            printf("This is addition\n");
            result = add_fun(first_num,second_num);
            printf("This is the result:%d", result);
            break;
        case 2:
            printf("This is subtraction\n");
            result = sub_fun(first_num, second_num);
            printf("This is the result:%d", result);
            break;
        case 3:
            printf("This is multiplication\n");
            result = multi_fun(first_num, second_num);
            printf("This is the result:%d", result);
            break;
        case 4:
            printf("This is division\n");
            result = div_fun(first_num, second_num);
            printf("This is the result:%d", result);
            break;

    }
}

int add_fun(int a, int b){
    return a+b;
}

int sub_fun(int a, int b){
    return a-b;
}

int multi_fun(int a, int b){
    return a*b;
}

int div_fun(int a, int b){
    return a/b;
}