//* https://www.acmicpc.net/problem/10773
//* Silver 4

#include <stdio.h>

int main()
{
    int n, input[100001];
    int top = 0, temp, sum = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);

        if (temp != 0)
            input[top++] = temp;
        else
            top--;
    }

    for (int i = 0; i < top; i++)
        sum += input[i];

    printf("%d", sum);

    return 0;
}