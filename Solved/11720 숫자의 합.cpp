//* https://www.acmicpc.net/problem/11720
//* Bronze 2

#include <stdio.h>

int main()
{
    int n;
    char number[101];
    int sum = 0;

    scanf("%d", &n);
    scanf("%s", number);

    for (int i = 0; i < n; i++)
        sum += number[i] - 48;

    printf("%d", sum);

    return 0;
}