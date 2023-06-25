#include <stdio.h>
#include <string.h>

/* Recursive Problems */
int power_raiser(int base, int power);
int checkIfPrime(int number, int divisor);

int main()
{
    int base = 2, power = 3;
    printf("%dth power of %d is: %d\n",power, base, power_raiser(2, 3));


    int number = 25;
    if (checkIfPrime(number , number-1))
        printf("%d is a prime number." , number);
    else
        printf("%d is not a prime number.", number);

}

//Q1 - Fill in the following recursive function that calculates the value of a number (base) raised to a power.
//Assume that power is a nonnegative integer.
int power_raiser(int base, int power)
{
    int ans;
    if (power == 0)
        ans = 1;
    else
        ans = base * power_raiser(base, power-1);
    return ans;
}

//Q2 - Write a recursive function which checks whether a given number is prime or not.
int checkIfPrime(int number, int divisor)
{
    if (number <= 1) return 0;  // Not Prime.
    else if (divisor == 1) return 1;    // Prime.

    if (number % divisor == 0) return 0;    // Not Prime.
    else return (checkIfPrime(number, divisor-1));
}