//* https://www.acmicpc.net/problem/10250
//* Bronze 3

#include <stdio.h>

int main()
{
    int num;
    int h, w, n;
    int room[10000];

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        scanf("%d %d %d", &h, &w, &n);
        int y = (n - 1) % h + 1;
        int x = (n - 1) / h + 1;
        room[i] = y * 100 + x;
    }

    for (int i = 0; i < num; i++)
        printf("%d\n", room[i]);
    return 0;
}