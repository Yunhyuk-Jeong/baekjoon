//* https://www.acmicpc.net/problem/2839
//* Bronze 1

#include <stdio.h>

int main()
{
    int N, bag = -1;

    scanf("%d", &N);

    int n = (N / 5) * 5;

    for (int i = 0; n >= 0; i++)
    {
        if ((N - n) % 3 == 0)
        {
            bag = (n / 5) + ((N - n) / 3);
            break;
        }
        else n -= 5;
    }

    printf("%d", bag);

    return 0;
}