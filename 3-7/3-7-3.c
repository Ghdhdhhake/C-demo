#include<stdio.h>

int main(void){
    float input;
    printf("Enter a floating-point value: \n");
    scanf("%f", &input);//input = 3.142343

    printf("Fixed-point notation: %f \n", input);
    printf("expeonential notation: %e \n", input);
    printf("p notaion: %a", input);
}