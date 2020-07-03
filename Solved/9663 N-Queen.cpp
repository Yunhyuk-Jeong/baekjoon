//* https://www.acmicpc.net/problem/9663
//* Gold 5

#include <stdio.h>
const int queen = 13;

int n, cnt = 0;
int up[30] = {
    0,
},
    left[30] = {
        0,
},
    right[30] = {
        0,
};

int nQueen(int x)
{
    if (x > n)
    {
        cnt++;
        return 0;
    }

    for (int y = 1; y <= n; y++)
    {
        if (up[y] == 1)
            continue;
        else if (right[x + y] == 1)
            continue;
        else if (left[x - y + queen] == 1)
            continue;
        else
        {
            up[y] = 1;
            right[x + y] = 1;
            left[x - y + queen] = 1;
            nQueen(x + 1);
        }
        up[y] = 0;
        right[x + y] = 0;
        left[x - y + queen] = 0;
    }

    return 0;
}

int main()
{
    scanf("%d", &n);

    nQueen(1);

    printf("%d", cnt);

    return 0;
}