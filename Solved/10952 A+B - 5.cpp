//* https://www.acmicpc.net/problem/10952
//* Bronze 3

#include <stdio.h>

int main()
{
    int a[2];

    while (scanf("%d %d", &a[0], &a[1]) != EOF)
    {
        if (a[0] == 0 && a[1] == 0)
            break;
        printf("%d\n", a[0] + a[1]);
    }
    return 0;
}