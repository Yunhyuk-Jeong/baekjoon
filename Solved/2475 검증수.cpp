//* https://www.acmicpc.net/problem/2475
//* Bronze 5

#include <stdio.h>

int main()
{
    int number[5], sum = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &number[i]);
        sum += number[i] * number[i];
    }
    printf("%d", sum % 10);

    return 0;
}