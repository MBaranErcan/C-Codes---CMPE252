#include <stdio.h>

int main(int argc, char const *argv[])
{
    double sum, avg, num1, num2, num3;

    printf("Enter 3 doubles: ");
    scanf("%lf%lf%lf", &num1, &num2, &num3);

    sum_n_avg(num1, num2, num3, &sum, &avg);
    return 0;
}

void sum_n_avg(double n1,double n2,double n3, double* sump, double* avgp) {
    *sump = n1 + n2 + n3;
    *avgp = *sump/3.0;
}
