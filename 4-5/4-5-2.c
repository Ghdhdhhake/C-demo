#include<stdio.h>
#include<string.h>

int main(void){
    char name[40];
    int width;
    printf("Please enter your name: \n");
    scanf("%s", name);
    width = printf("\"%s\" \n", name);
    width =  strlen(name);  //获取name长度
    printf("\"%20s\". \n", name);
    /*在宽度为20的字段右端打印名字，使用转义序列\"打印双引号*/
    printf("\"%-20s\". \n", name);
     /*在宽度为20的字段右端打印名字，使用转义序列\"打印双引号*/
    printf("\"%*s\". \n", (width + 3), name);
     /*使用修饰符*，指定宽度参数，打印名字字符串*/
    return 0;
}