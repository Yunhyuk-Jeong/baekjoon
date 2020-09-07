//* https://www.acmicpc.net/problem/10828
//* Silver 4

#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char data[10];
    int stack[10010];
    int point = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", data);
        if (strcmp(data, "push") == 0)
            scanf("%d", &stack[point++]);
        else if (strcmp(data, "pop") == 0)
            printf("%d\n", point != 0 ? stack[--point] : -1);
        else if (strcmp(data, "size") == 0)
            printf("%d\n", point);
        else if (strcmp(data, "empty") == 0)
            printf("%d\n", point == 0 ? 1 : 0);
        else if (strcmp(data, "top") == 0)
            printf("%d\n", point != 0 ? stack[point - 1] : -1);
    }
    return 0;
}