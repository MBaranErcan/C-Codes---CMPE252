#include <stdio.h>
#include <stdlib.h>


   // read two integers from the user.
   // List and calculate sum of the numbers between these two numbers, recursively.
   // For example: User enters 10 and 12.
   // List= 10, 11 ,12
   // Sum = 10 + 11 + 12 = 33


int sumOfRange(int min, int max) {
   int res;

   printf("%d ", min);

   if (min == max)
      return min;
   else
      res = min + sumOfRange(min+1, max);

   return (res);
}

int main() {
   int sum;
   int min, max;

   printf("Enter the first number: ");
   scanf("%d", &min);

   printf("Enter the second number: ");
   scanf("%d", &max);

   printf("Numbers are: ");

   sum = sumOfRange(min, max);

   printf("\nThe sum of numbers from %d to %d : %d\n\n", min, max, sum);

   return (0);
}
