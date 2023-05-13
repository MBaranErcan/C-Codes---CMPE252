#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 250

float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;

    printf("Enter a number:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);

    if (errorState==0){
        printf("Your number is: %.2f \n", fnum1);
    }else if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}
float myAtof(char* string, char* error) {// Function to convert string into float.
    float total = 0.0;
    int leftLen = 0;        // Number of integers on the left side of the dot "."
    int rightLen = 0;       // Number of integers on the right side of the dot "."
    bool afterDot = false;  // Boolean value to check whether we are calculating the value after or before the dot.
    int i = 0, intValue;    // i is for iterating over string array; intValue is for representing the decimal value of the current integer.

    while (string[i] != '\0') {                                         // Loop through each element until you reach the end ('\0').
        if (string[i] < 42 || string[i] > 57 || string[i] == 44)        // If an invalid char is found:
            return (*error)++;                                          // Increment error and return.
        if (string[i] == '.') {                                         // If a dot is found, mark afterDot as true and move to the next element.
            total /= pow(10 , strlen(string) - leftLen);      // When we encounter a dot, we divide the total so that it moves the decimal point to the correct position.
            afterDot = true;
            i++;
            continue;
        }
        if (!afterDot) {                    // Means we are calculating the left side of the dot.
            intValue = string[i] - '0';     // Calculate the integer value of the current char by subtracting the ASCII value of the '0'.
            total += intValue * pow(10 , strlen(string) - i - 1);// Multiply it with its decimal value.
            leftLen++;                      // Increment the leftLen by one.
            i++;                            // Move to the next element.
        }
        else {                              // Means we are calculating the right side of the dot.
            intValue = string[i] - '0';     // Calculate the integer value of the current char by subtracting the ASCII value of the '0'.
            total += intValue / pow(10 , rightLen + 1);
            rightLen++;                     // Increment the rightLen by one.
            i++;                            // Move to the next element.
        }
    }
    return total;
}

