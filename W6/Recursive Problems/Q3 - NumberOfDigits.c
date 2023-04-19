#include <stdio.h>

int numberOfDigits(int n) {
    int ans;

    if (n >= 0 && n <= 9)
        ans = 1;
    else
        ans = 1 + numberOfDigits(n / 10);

    return ans;
}


int main() {
    int n;
    int numOfDigits;

    printf("Enter an integer: ");
    scanf("%d", &n);

    numOfDigits = numberOfDigits(n);
    printf("%d has %d digits\n", n, numOfDigits);

    return 0;
}
