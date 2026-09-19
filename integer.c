#include <stdio.h>

void safeprint(const void *ptr, int type);

int main()
{
    int intArray[5];
    float floatArray[5];

    int *ip = intArray;
    float *fp = floatArray;

    int i, option, index;

    printf("Enter 5 integers:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", ip + i);
    }

    printf("Enter 5 floating point values:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%f", fp + i);
    }

    printf("\nInteger Array:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%d\n", *(ip + i));
    }

    printf("\nFloating Point Array:\n");
    for(i = 0; i < 5; i++)
    {
        printf("%f\n", *(fp + i));
    }

    printf("\n0 - Integer\n");
    printf("1 - Float\n");
    printf("Enter your choice: ");
    scanf("%d", &option);

    printf("Enter index to access (0-4): ");
    scanf("%d", &index);

    if(option == 0)
    {
        if(index >= 0 && index < 5)
        {
            safeprint(ip + index, 0);
        }
        else
        {
            safeprint(NULL, 0);
        }
    }
    else if(option == 1)
    {
        if(index >= 0 && index < 5)
        {
            safeprint(fp + index, 1);
        }
        else
        {
            safeprint(NULL, 1);
        }
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}

void safeprint(const void *ptr, int type)
{
    if(ptr == NULL)
    {
        printf("NULL pointer, nothing to print\n");
        return;
    }

    if(type == 0)
    {
        printf("Integer value = %d\n", *(const int *)ptr);
    }
    else if(type == 1)
    {
        printf("Float value = %f\n", *(const float *)ptr);
    }
    else
    {
        printf("Invalid type\n");
    }
}