#include <stdio.h>
#include <math.h>

int numberOfDigits(int n) {
    int ans;

    if (n >= 0 && n <= 9)
        ans = 1;
    else
        ans = 1 + numberOfDigits(n / 10);

    return ans;
}


int reverseNumber(int n, int numOfDigits) {
    int ans;
    int rightMostDigit;

    if (n >= 0 && n <= 9)
        ans = n;
    else
    {
        rightMostDigit = n % 10;
        ans = (rightMostDigit)* pow(10,numOfDigits-1) + reverseNumber(n / 10, numOfDigits-1);
    }

    return ans;
}


int main() {
    int n;
    int numOfDigits;
    int nReversed;

    printf("Enter an integer: ");
    scanf("%d", &n);

    numOfDigits = numberOfDigits(n);

    nReversed = reverseNumber(n, numOfDigits);
    printf("%d reversed: %d\n", n, nReversed);

    return 0;
}
