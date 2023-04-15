#include <stdio.h>

int powerRaiser(int base, int power);

int main()
{
    int x = powerRaiser(9,2);
    
    printf("%d", x);

    return 0;
}

int powerRaiser(int base, int power) {
    int ans;

    if (power == 1)
        ans = ans;
    else {
        ans = base * base;
    }
    return ans;
}

