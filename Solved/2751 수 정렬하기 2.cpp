//* https://www.acmicpc.net/problem/2751
//* Silver 5

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
    int n, *arr, input;
    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n", &input);
        arr[i] = input;
    }
    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
    return 0;
}