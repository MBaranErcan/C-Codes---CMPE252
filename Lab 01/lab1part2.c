#include <stdio.h>
#include <math.h>

void findClosestPoint(double *length, double *closestX, double *closestY)
{
    double x, y, dist, min_dist = 9999;
    double min_x, min_y;

    while (scanf("%lf %lf", &x, &y) != EOF) {
        dist = sqrt(x * x + y * y);

        if (dist < min_dist) {
            min_dist = dist;
            min_x = x;
            min_y = y;
        }
    }
    *length = min_dist;
    *closestX = min_x;
    *closestY = min_y;
}

int main()
{
    double length, closestX, closestY;

    findClosestPoint(&length, &closestX, &closestY);

    printf("length of line from point to origin %.2f\n", length);
    printf("Closest Point X: %.2f\n", closestX);
    printf("Closest Point Y %.2f\n", closestY);

    return 0;
}
