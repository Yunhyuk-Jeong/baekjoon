//* https://www.acmicpc.net/problem/10430
//* Bronze 5

#include <stdio.h>

int main()
{
    int inputA, inputB, inputC;
    scanf("%d %d %d", &inputA, &inputB, &inputC);
    printf("%d\n%d\n", (inputA + inputB) % inputC, ((inputA % inputC) + (inputB % inputC)) % inputC);
    printf("%d\n%d\n", (inputA * inputB) % inputC, ((inputA % inputC) * (inputB % inputC)) % inputC);
    return 0;
}