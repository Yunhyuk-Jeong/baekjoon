//* https://www.acmicpc.net/problem/2753
//* Bronze 4

#include <stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    printf("%d", year % 4 == 0 ? year % 100 != 0 || year % 400 == 0 ? 1 : 0 : 0);
    return 0;
}