//* https://www.acmicpc.net/problem/14681
//* Bronze 4

#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d", x > 0 && y > 0 ? 1 : x < 0 && y < 0 ? 3 : x > 0 ? 4 : 2);
    return 0;
}