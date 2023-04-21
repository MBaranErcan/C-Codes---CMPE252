#include <stdio.h>
#include <math.h>

int f(int x, int c, int d);

int main() {

    int a=0, b=0, c=0, d=0, n=0;
    double area=0, h=0, temp=0;

    printf("Enter value of a:\n");
    scanf("%d",&a);
    printf("Enter value of b:\n");
    scanf("%d",&b);
    printf("Enter value of n:\n");
    scanf("%d",&n);
    printf("Enter value of c:\n");
    scanf("%d",&c);
    printf("Enter value of d:\n");
    scanf("%d",&d);

    h = (b-a)/n;

    for (int i = a+h; i < b; i+=h) {
        temp += f(i,c,d);
    }

    area = (h/2)* ( f(a,c,d) + f(b,c,d) + (2*temp));

    printf("T: %.2lf", area);

    return 0;
}

int f(int x, int c, int d) {
    int res = 0;
    res = pow(x,c) + (2*d);

    return res;
}
