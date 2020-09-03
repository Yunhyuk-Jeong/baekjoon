//* https://www.acmicpc.net/problem/2164
//* Silver 4

#include <stdio.h>

int main()
{
    int n, i, com = 0;
    int arr[1000000] = {
        0,
    };

    scanf("%d", &n);

    for (i = 1; i <= n; i++)
        arr[i - 1] = i;

    for (i = 0; arr[i + 1] != 0; i++)
    {
        if (i % 2)
        {
            arr[com + n] = arr[i];
            com++;
        }
    }

    printf("%d", arr[i]);

    return 0;
}