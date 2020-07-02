//* https://www.acmicpc.net/problem/3052
//* Bronze 2

#include <stdio.h>

int main()
{
    const int number = 42;
    int input[10], count = 0;

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &input[i]);
        input[i] = input[i] % number;
    }

    for (int i = 0; i < 10; i++)
        for (int j = i + 1; j < 9; j++)
            input[i] == input[j] ? input[j] = -1 : 0;

    for (int i = 0; i < 10; i++)
        input[i] != -1 ? count++ : 0;

    printf("%d", count);
    return 0;
}