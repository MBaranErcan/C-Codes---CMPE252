#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr); // You can use same from Part I

void printNumbers(const int arr[], int n); // You can use same from Part I


void countNegNonneg(const int arr[], int n, int *negCountPtr, int *nonnegCountPtr)
{
    for (int i = 0; i < n; ++i) {

        if (arr[i] < 0)
            (*negCountPtr)++;
        else
            (*nonnegCountPtr)++;
    }
}

int main() {
        int arr[SIZE];
        int n, neg=0, nonneg=0;

        readInput(arr, &n);
        printNumbers(arr, n);
		countNegNonneg(arr, n, &neg, &nonneg);
        printf("\nCount of Non-negative elements = %d\n", nonneg);
        printf("Count of Negative elements = %d\n", neg);

        return 0;
}


void readInput(int arr[], int *nPtr) {
    printf("Enter the number of elements:\n");
    scanf("%d", nPtr);

    printf("Enter %d elements:\n", *nPtr);
    for (int i = 0; i < *nPtr; ++i) {
        scanf("%d", &arr[i]);
    }
}

void printNumbers(const int arr[], int n) {
    printf("Array elements:");
    for (int i = 0; i < n; ++i) {
        printf(" %d", arr[i]);
    }

}
