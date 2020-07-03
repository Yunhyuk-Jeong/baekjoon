//* https://www.acmicpc.net/problem/11047
//* Silver 1

#include <stdio.h>

int number, money, m = 0;
int a[10] = {
    0,
};

void sort()
{
    for (int i = 0; i < number - 1; i++)
        for (int j = i + 1; j < number; j++)
            if (a[i] < a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void mo(int x)
{
    while (true)
    {
        if (money - a[x] < 0)
            break;
        money -= a[x];
        m++;
    }
}

void go()
{
    for (int i = 0; i < number; i++)
        mo(i);
    printf("%d", m);
}

int main()
{
    scanf("%d %d", &number, &money);
    for (int i = 0; i < number; i++)
        scanf("%d", &a[i]);

    sort();
    go();
}