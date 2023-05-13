#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 250

float myAtof(char *string, char *error);
void seperateNums(char *string, char *num1, char *num2, char *sign, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    char cnum1[SIZE], cnum2[SIZE], sign[1];
    float fnum1 = 0, fnum2 = 0, result;
    char errorState=0;

    printf("Enter arithmetic operation:\n");
    gets(string);

    seperateNums(string, cnum1, cnum2, sign, &errorState);

    fnum1 = myAtof(cnum1,&errorState);    // First float number.
    fnum2 = myAtof(cnum2,&errorState);    // Second float number.



    if (errorState==0){
        switch (sign[0]) {  // Use a switch statement to perform the appropriate arithmetic operation based on the value of sign.
            case '+':
                result = fnum1 + fnum2;
                break;
            case '-':
                result = fnum1 - fnum2;
                break;
            case '*':
                result = fnum1 * fnum2;
                break;
            case '/':
                if (fnum2 == 0) {
                    printf("Cannot divided into 0.");
                    return 1;
                }
                result = fnum1 / fnum2;
                break;
            default:
                printf("Invalid sign!\n");
                return 0;
        }
        printf("%.2f %c %.2f = %.2f\n",fnum1, sign[0] ,fnum2, result);
    }else if (errorState>=1){
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

void seperateNums(char *string, char *num1, char *num2, char *sign, char *error) {  // Separate the string into two numbers and a sign.
    bool signFound = 0;
    int i = 0, index = 0;
    while (string[i] != '\0') {
        switch (string[i]) {
            case '+':
                sign[0] = '+';
                index = i;
                signFound = true;
                break;
            case '-':
                sign[0] = '-';
                index = i;
                signFound = true;
                break;
            case '*':
                sign[0] = '*';
                index = i;
                signFound = true;
                break;
            case '/':
                sign[0] = '/';
                index = i;
                signFound = true;
                break;
        }
        if (signFound) {   // If a sign has already been found:
            break;         // Break out of the while loop.
        }
        i++;
    }
    if (signFound == false) {   // If no sign is found:
        (*error)++; // Increment error value and return.
        return;
    }
    num1[0] = '\0';
    num2[0] = '\0';
    strncat(num1,string, index);
    num1[index] = '\0';
    strncat(num2, &string[index+1], strlen(&string[index+1])); // num2 is the part of the right side of the sign
    num2[strlen(&string[index+1])] = '\0';
}