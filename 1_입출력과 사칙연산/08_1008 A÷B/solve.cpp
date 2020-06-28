#include <stdio.h>

int main()
{
    double inputA, inputB;
    scanf("%lf %lf", &inputA, &inputB);
    printf("%.9lf", inputA / inputB);
    return 0;
}