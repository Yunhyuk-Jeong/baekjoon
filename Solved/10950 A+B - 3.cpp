//* https://www.acmicpc.net/problem/10950
//* Bronze 3

#include <stdio.h>

int main()
{
    int t, a[100001][2];
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        scanf("%d %d", &a[i][0], &a[i][1]);
    for (int i = 0; i < t; i++)
        printf("%d\n", a[i][0] + a[i][1]);
    return 0;
}