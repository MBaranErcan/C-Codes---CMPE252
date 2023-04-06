#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
    int num = 0, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);

    sum = sumOfDigits(num);

    printf("\nSum of the digits: %d", sum);
    printf("\nDivisible by 9:");

    if(sum % 9 == 0)
        printf(" Yes");
    else
        printf(" No");
    return 0;
}

int sumOfDigits(int num) {
    int sum = 0;

    while (num != 0) {
        sum += num % 10; // add the last digit of num to sum
        num /= 10; // remove the last digit from num
    }
    return sum;
}
