#include <stdio.h>

int main()
{
    int inputA, inputB;
    scanf("%d %d", &inputA, &inputB);
    printf("%d\n", inputA * (inputB % 10));
    printf("%d\n", inputA * (inputB / 10 % 10));
    printf("%d\n", inputA * (inputB / 100 % 10));
    printf("%d\n", inputA * inputB);
    return 0;
}