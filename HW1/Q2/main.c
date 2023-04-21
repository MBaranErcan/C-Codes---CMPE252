#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c, x_n = 10;
    int start, end;


    printf("Enter value of a:\n");
    scanf("%f", &a);
    printf("Enter value of b:\n");
    scanf("%f", &b);
    printf("Enter value of c:\n");
    scanf("%f", &c);
    printf("Enter minimum value of x_n:\n");
    scanf("%d", &start);
    printf("Enter maximum value of x_n:\n");
    scanf("%d", &end);

    for (int i = 1; i <= end; ++i) {
        x_n = (x_n * b) + (((-1*b)+ sqrt(pow(b,2)-4*a*c))/(2*a));

        if(i >= start)
            printf("x_%d: %.2f\n", i, x_n);
    }


    return 0;
}
