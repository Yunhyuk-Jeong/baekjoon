//* https://www.acmicpc.net/problem/4153
//* Bronze 3

#include <stdio.h>
#include <math.h>

int RightTriangle(int side[3])
{
    int temp, i, j;

    if (side[0] == side[1] && side[1] == side[2] && side[2] == 0)
        return 0;

    for (i = 1; i < 3; i++)
    {
        temp = side[(j = i)];
        while (--j >= 0 && temp < side[j])
        {
            side[j + 1] = side[j];
            side[j] = temp;
        }
    }

    if (pow(side[0], 2) + pow(side[1], 2) == pow(side[2], 2))
        return 1;
    else
        return 2;
}

int main()
{
    int side[3];

    while (true)
    {
        for (int i = 0; i < 3; i++)
            scanf("%d", &side[i]);

        int answer = RightTriangle(side);
        if (answer == 0)
            return 0;
        else if (answer == 1)
            printf("right");
        else
            printf("wrong");
        printf("\n");
    }
    return 0;
}