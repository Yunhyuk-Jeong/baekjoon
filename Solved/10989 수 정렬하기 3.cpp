//* https://www.acmicpc.net/problem/10989
//* Silver 5

#include <stdio.h>

int main()
{
    int inputSize;

    scanf("%d", &inputSize);

    int arr[10000] = {0};

    for (int i = 0; i < inputSize; i++)
    {
        int num;
        scanf("%d", &num);
        arr[num - 1]++;
    }

    for (int i = 0; i < 10000; i++)
        for (int j = 0; j < arr[i]; j++)
            printf("%d\n", i + 1);

    return 0;
}