#include<stdio.h>

#define DAYS_PER_YEAR 365

int main(void)
{
    int age, days;
    age = 20;
    days = age * DAYS_PER_YEAR;
    printf("Your age is %d, and it is %d days. \n", age, days);
    return 0;

}