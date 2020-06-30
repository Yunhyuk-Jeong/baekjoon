//* https://www.acmicpc.net/problem/10818
//* Bronze 3

#include <stdio.h>

int main()
{
    int count, numberArray[1000020], min = 0, max = 0;
    scanf("%d", &count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &numberArray[i]);
        numberArray[i] > numberArray[max] ? max = i : 0;
        numberArray[i] < numberArray[min] ? min = i : 0;
    }

    printf("%d %d", numberArray[min], numberArray[max]);

    return 0;
}