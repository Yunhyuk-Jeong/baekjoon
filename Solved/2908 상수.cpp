//* https://www.acmicpc.net/problem/2908
//* Bronze 2

#include <stdio.h>

int main()
{
    int before[2], after[2] = {0, 0};
    scanf("%d %d", &before[0], &before[1]);

    for (int i = 0; i < 2; i++)
    {
        after[i] += before[i] % 10 * 100;
        before[i] /= 10;
        after[i] += before[i] % 10 * 10;
        before[i] /= 10;
        after[i] += before[i] % 10;
    }
    after[0] > after[1] ? printf("%d", after[0]) : printf("%d", after[1]);
    return 0;
}