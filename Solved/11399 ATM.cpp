//* https://www.acmicpc.net/problem/11399
//* Silver 3

#include <stdio.h>

int main()
{
    int arr[1000], sum = 0, n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += arr[j];
        }
    }

    printf("%d", sum);

    return 0;
}