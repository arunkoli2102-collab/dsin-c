#include <stdio.h>
#include <stdlib.h>

int *allocUsingMalloc(int n) {
    return malloc(n * sizeof(int));
}

int *allocUsingCalloc(int n) {
    return calloc(n, sizeof(int));
}

int *resizeArray(int *arr, int newSize) {
    return realloc(arr, newSize * sizeof(int));
}

void readElements(int *arr, int start, int end) {
    for (int i = start; i < end; i++) {
        scanf("%d", &arr[i]);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void freeMemory(int *arr) {
    free(arr);
}

int main() {
    int n, new_n;
    int *mallocArray, *callocArray;

    printf("Enter array size: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size\n");
        return 1;
    }

    mallocArray = allocUsingMalloc(n);
    if (mallocArray == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements for the malloc array:\n", n);
    readElements(mallocArray, 0, n);
    printf("Malloc Array after user input:\n");
    printArray(mallocArray, n);

    callocArray = allocUsingCalloc(n);
    if (callocArray == NULL) {
        printf("Memory allocation failed\n");
        freeMemory(mallocArray);
        return 1;
    }

    printf("\nArray allocated using calloc (Zero-initialized):\n");
    printArray(callocArray, n);

    printf("Enter %d elements for the calloc array:\n", n);
    readElements(callocArray, 0, n);
    printf("Calloc Array after user input:\n");
    printArray(callocArray, n);

    printf("Enter new size for realloc: ");
    if (scanf("%d", &new_n) != 1 || new_n <= 0) {
        printf("Invalid new size.\n");
        freeMemory(mallocArray);
        freeMemory(callocArray);
        return 1;
    }

    int *resizedArray = resizeArray(mallocArray, new_n);
    if (resizedArray == NULL) {
        printf("Memory allocation failed\n");
        freeMemory(mallocArray);
        freeMemory(callocArray);
        return 1;
    }
    mallocArray = resizedArray;

    if (new_n > n) {
        printf("Enter %d additional elements:\n", new_n - n);
        readElements(mallocArray, n, new_n);
    }

    printf("Array after realloc:\n");
    printArray(mallocArray, new_n);

    freeMemory(mallocArray);
    freeMemory(callocArray);

    printf("Memory successfully released using free()\n");
    return 0;
}
