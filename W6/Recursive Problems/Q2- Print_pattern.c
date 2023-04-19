#include <stdio.h>
#include <stdlib.h>

void print_pattern(int n){

    if(n <= 0)
        printf("%d ",n);
    else
    {
        printf("%d ",n);
        print_pattern(n-5);
        printf("%d ",n);
    }
}

int main() {
    int n;
    printf("Please enter an integer: ");
    scanf("%d", &n);

    printf("The pattern is: ");
    print_pattern(n);

    return 0;
}
