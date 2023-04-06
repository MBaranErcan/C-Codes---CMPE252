#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int speed = 0;
    int normal = 0, high = 0, slow = 0;
    int car_count = 0;

    printf("Enter the speeds:\n");
    scanf("%d", &speed);

    while (speed != -99)    // -99 to quit
    {
        car_count++;
        if (speed > 90)
        {
            printf("Vehicle %d has a high speed.\n", car_count);
            high++;
        }
        else if (speed < 50)
        {
            printf("Vehicle %d has a slow speed.\n", car_count);
            slow++;
        }
        else {
            printf("Vehicle %d has a normal speed.\n", car_count);
            normal++;
        }
        scanf("%d", &speed);
    } // move the closing brace to here

    printf("High Speed vehicle count: %d\n", high);
    printf("Normal Speed vehicle count: %d\n", normal);
    printf("Slow Speed vehicle count: %d\n", slow);

    return 0;
}
