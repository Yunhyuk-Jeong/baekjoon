//* https://www.acmicpc.net/problem/7568
//* Silver 5

#include <stdio.h>

int main()
{
    int n;
    int weight[51];
    int height[51];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &weight[i], &height[i]);

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
            if (weight[i] < weight[j] && height[i] < height[j])
                count++;
        printf("%d ", count + 1);
    }
    return 0;
}