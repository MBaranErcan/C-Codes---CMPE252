#include <stdio.h>
#include <stdlib.h>

double celcius_at_depth(double depth);
double fahrenheit(double celcius);

int main(int argc, char const *argv[])
{
    double depth = 0;
    printf("Enter the depth: ");
    scanf("%lf", &depth);

    //helper func. calls
    double c = celcius_at_depth(depth);
    double f = fahrenheit(c);

    printf("Celcius degree: %.2f", c);
    printf("\nFahrenheit degree: %.2f", f);

    return 0;
}

//helper function declerations
double celcius_at_depth(double depth) {
    return (depth * 10) + 20;
}
double fahrenheit(double celcius) {
    return (celcius * 1.8) + 10132;
}
