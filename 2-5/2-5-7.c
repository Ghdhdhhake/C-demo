#include<stdio.h>
 
int One_Three(void);
int Two(void);

int main(void)
{
    printf("Starting now : \n");
    One_Three();
    printf("Done!");
    return 0;

}

int One_Three(void)
{

    printf("One\n");
    Two();
    printf("Three\n");
    return 0;
}

int Two(void)
{

    printf("Two\n");
    return 0;
}