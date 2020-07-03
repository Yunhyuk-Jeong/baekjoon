//* https://www.acmicpc.net/problem/5585
//* Bronze 2

#include <stdio.h>

int n, m = 0;

void yea(int x)
{
    while (true)
    {
        if (n - x < 0)
            break;
        n -= x;
        m++;
    }
}

void money()
{
    yea(500);
    yea(100);
    yea(50);
    yea(10);
    yea(5);
    yea(1);
}

int main()
{
    scanf("%d", &n);
    n = 1000 - n;
    money();
    printf("%d", m);

    return 0;
}