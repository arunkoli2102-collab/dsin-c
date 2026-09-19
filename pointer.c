#include<stdio.h>
int main() {
    int *ptr1;
    float *ptr2;
    double *ptr3;
    printf("size of the int pointer:%zu bytes\n",sizeof(*ptr1));
    printf("size of the float pointer:%zu bytes",sizeof(*ptr2));
    printf("size of the dpuble pointer:%zu bytes",sizeof(*ptr3));
    return 0;
}