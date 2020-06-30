//* https://www.acmicpc.net/problem/2562
//* Bronze 2

#include <stdio.h>

int main()
{
    int number[9], maxNumberIndex = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &number[i]);
        number[i] > number[maxNumberIndex] ? maxNumberIndex = i : 0;
    }
    printf("%d\n%d", number[maxNumberIndex], maxNumberIndex + 1);
    return 0;
}