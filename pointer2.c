#include<stdio.h>
int main()
{
    int age=40;
    int *ptr=&age;
    printf("%d\n",age);
    printf("%p\n",ptr);
    printf("%p\n",&age);
    return 0;
}