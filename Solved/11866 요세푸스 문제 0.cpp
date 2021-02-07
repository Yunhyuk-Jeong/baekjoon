//* https://www.acmicpc.net/problem/11866
//* Silver 4

#include <stdio.h>

int main()
{
    int n, k, seat[1000], cnt = 0;

    scanf("%d %d", &n, &k);

    printf("<");

    for (int i = 0; i < n; i++)
        seat[i] = i + 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            seat[cnt] == 0 ? j-- : 0;
            cnt = (cnt + 1) % n;
        }

        while (seat[cnt] == 0)
            cnt = (cnt + 1) % n;

        printf("%d", seat[cnt]);
        if (i != n - 1)
            printf(", ");
        seat[cnt] = 0;
    }

    printf(">");

    return 0;
}