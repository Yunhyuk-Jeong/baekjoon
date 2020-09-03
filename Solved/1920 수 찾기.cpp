//* https://www.acmicpc.net/problem/1920
//* Silver 4

#include <stdio.h>
#include <stdlib.h>

int static compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return 1;
    else if (*(int *)first < *(int *)second)
        return -1;
    else
        return 0;
}

int main()
{
    int n, m, *a, *b, *solve, input;
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        a[i] = input;
    }

    qsort(a, n, sizeof(int), compare);

    scanf("%d", &m);
    b = (int *)malloc(sizeof(int) * m);
    solve = (int *)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &input);
        b[i] = input;
    }

    for (int i = 0; i < m; i++)
    {
        int start = 0, end = n;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (b[i] == a[mid])
            {
                solve[i] = 1;
                break;
            }
            else if (b[i] < a[mid])
                end = mid - 1;
            else if (b[i] > a[mid])
                start = mid + 1;
        }
        if (solve[i] != 1)
            solve[i] = 0;
    }

    for (int i = 0; i < m; i++)
        printf("%d\n", solve[i]);

    return 0;
}