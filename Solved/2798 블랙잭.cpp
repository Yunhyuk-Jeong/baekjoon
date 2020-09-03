//* https://www.acmicpc.net/problem/2798
//* Bronze 2

#include <stdio.h>

int main()
{
    int n, m;
    int sum, max = -1;
    int card[101];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
            {
                sum = card[i] + card[j] + card[k];
                if (sum > max && sum <= m)
                    max = sum;
            }
    printf("%d", max);
    return 0;
}