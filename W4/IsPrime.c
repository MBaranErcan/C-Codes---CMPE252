#include <stdio.h>
#include <stdbool.h>

bool isPrime(int number);
bool isPrimeHelper(int number, int divisor);

int main() {
    
    int number;
    printf("Enter a number to check if it is Prime: ");
    scanf("%d", &number);

    bool x = isPrime(number);

    printf("%d is %s\n", number, x ? "prime" : "not prime");

    return 0;
}

bool isPrime(int number) {
    return isPrimeHelper(number, 2);
}

bool isPrimeHelper(int number, int divisor) {
    bool result = true;
    if (divisor <= number / 2) {
        if (number % divisor == 0) {
            printf("%d is a divisor of %d\n", divisor, number);
            result = false;
        } else {
            return isPrimeHelper(number, divisor + 1);
        }
    }
    return result;
    
}
