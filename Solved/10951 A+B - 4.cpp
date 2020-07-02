//* https://www.acmicpc.net/problem/10951
//* Bronze 3

#include <stdio.h>

int main()
{
    int a[2];

    while (scanf("%d %d", &a[0], &a[1]) != EOF)
        printf("%d\n", a[0] + a[1]);
    return 0;
}