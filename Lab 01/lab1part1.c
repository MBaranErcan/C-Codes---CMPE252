#include <stdio.h>
#include <math.h>

/*
pre-conditions
n is greater than 1 (n > 1)
maxVal is positive (maxVal > 0)
minVal is positive (minVal > 0)
maxVal is greater than or equal to minVal (maxVal >= minVal)
*/
void printPowersInRange(int n, int p, int count, int minVal, int maxVal)
{
    int result = pow(n, p) + (3 * p);

    if (result >= minVal && result <= maxVal) { // Wanted interval.
        printf("F_%d is: %d \n",(count+1) , result);
        count++;
    }
    if (result < maxVal) {                  // Cases where we want to increment p, so we can reach the wanted interval.
        p++;
        printPowersInRange(n, p, count, minVal, maxVal);
    }
    if (result > maxVal) {  		// Base case.
        printf("%d", count);
    }
}

int main()
{
    int number;
    int minVal, maxVal;

    printf("Enter number> ");
    scanf("%d", &number);
    printf("Enter minimum value> ");
    scanf("%d", &minVal);
    printf("Enter maximum value> ");
    scanf("%d", &maxVal);

    printPowersInRange(number, 0,0, minVal, maxVal);

    return 0;
}

