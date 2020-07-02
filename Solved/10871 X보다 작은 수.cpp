//* https://www.acmicpc.net/problem/10871
//* Bronze 3

#include <stdio.h>

int main()
{
    int n, x, a[100001];
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        a[i] < x ? printf("%d ", a[i]) : 0;

    return 0;
}