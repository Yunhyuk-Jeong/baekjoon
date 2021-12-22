//* https://www.acmicpc.net/problem/1929
//* Silver 2

#include <stdio.h>

int main()
{
    int m, n;
    int cnt = 0;

    scanf("%d %d", &m, &n);

    bool PrimeArray[1000001];

    for (int i = 1; i < 1000001; i++)
        PrimeArray[i] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (PrimeArray[i])
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
    }

    for (int i = m; i <= n; i++)
        if (PrimeArray[i] == true && i != 1)
            printf("%d\n", i);

    return 0;
}