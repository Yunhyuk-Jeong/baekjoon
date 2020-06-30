//* https://www.acmicpc.net/problem/2577
//* Bronze 2

#include <stdio.h>

int main()
{
    int number[3],
        mulNumber = 1,
        numberIndex[10] = {
            0,
        };

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &number[i]);
        mulNumber = number[i];
    }

    while (true)
    {
        if (mulNumber == 0)
            break;
        int temp = mulNumber % 10;
        mulNumber /= 10;
        numberIndex[temp]++;
    }

    for (int i = 0; i < 10; i++)
        printf("%d\n", numberIndex[i]);

    return 0;
}