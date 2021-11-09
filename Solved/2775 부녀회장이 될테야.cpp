//* https://www.acmicpc.net/problem/2775
//* Bronze 2

#include <stdio.h>

int getNumber(int k, int n)
{
    if (n == 1)
        return 1;
    else if (k == 0)
        return n;
    return (getNumber(k - 1, n) + getNumber(k, n - 1));
}

int main()
{
    int T, k, n;

    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &k, &n);
        printf("%d\n", getNumber(k, n));
    }

    return 0;
}