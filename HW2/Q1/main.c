#include <stdio.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr); // reads numbers from the standard input into arr, and stores the number of elements read in the memory cell pointed to by nPtr
void printNumbers(const int arr[], int n); // prints the elements in arr[0..(n-1)]

int main() {
    int arr[SIZE];

    int n = 0;
    int* nPtr = &n;

    readInput(arr, nPtr);
    printNumbers(arr, n);

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