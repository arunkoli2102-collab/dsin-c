#include <stdio.h>

// Function declarations
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
float divide(int a, int b);

int main() {
    int num1, num2, choice;
    float result;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("\nChoose operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            result = add(num1, num2);
            printf("Result = %d\n", (int)result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result = %d\n", (int)result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result = %d\n", (int)result);
            break;
        case 4:
            if(num2 != 0)
                result = divide(num1, num2);
            else {
                printf("Error: Division by zero!\n");
                return 1;
            }
            printf("Result = %.2f\n", result);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

// Function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}