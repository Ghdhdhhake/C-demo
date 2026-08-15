#include<stdio.h>

#define GALLON_TOLITRE 3.785
#define MILE_TO_KM 1.609

int main(void){
    float range, oil;
    printf("Please input  the range you traveled(in mile) : \n");
    scanf("%f", &range);
    printf("Please input the oil you spend(in gallon) : \n");
    scanf("%f", &oil);
    printf("In USA, your oil wear is %.1f M/G. \n", range/oil);
    printf("In Europe, your oil wear is %.1f L/100KM. ", (oil * GALLON_TOLITRE) / (range * MILE_TO_KM));
    return 0;
}