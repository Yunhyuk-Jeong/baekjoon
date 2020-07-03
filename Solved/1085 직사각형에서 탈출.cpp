//* https://www.acmicpc.net/problem/1085
//* Bronze 3

#include <stdio.h>

int main()
{
    int x, y, w, h;
    int min = 99999;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    min > x ? min = x : 0;
    min > y ? min = y : 0;
    min > w - x ? min = w - x : 0;
    min > h - y ? min = h - y : 0;
    printf("%d", min);
    return 0;
}