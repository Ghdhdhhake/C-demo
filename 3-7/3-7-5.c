#include<stdio.h>

#define SEC_PRE_YEAE 3.156e7

int main(void)
{
    float year, second;
    printf("Please enter your age: \n");
    scanf("%f", &year);
    second = SEC_PRE_YEAE * year;
    printf("You are :%f years old. \n", year);
    printf("And you are %e second old, too. \n", second);
    return 0;
}