#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

void readInput(int arr[], int *nPtr); // You can use same from Part I

void printNumbers(const int arr[], int n); // You can use same from Part I


void findLoosers(const int arr[], int n, int loosersArr[], int *sp)
{
    int temp = arr[0];
    loosersArr[*sp] = arr[0];
    ++*sp; // First item

    for (int i = 1; i < n; ++i) {
        if (arr[i] <= temp) {
            if (*sp < n) {
                loosersArr[*sp] = arr[i];
                temp = arr[i];
                (*sp)++;
            }
        }

    }
}


int main() {
        int arr[SIZE];
        int n;
        int loosersArr[SIZE];
        int s=0;
        readInput(arr, &n);
        printNumbers(arr, n);
		findLoosers(arr, n, loosersArr, &s);
		printf("\nLoosers ");
		printNumbers(loosersArr, s);

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
