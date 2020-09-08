//* https://www.acmicpc.net/problem/11650
//* Silver 5

#include <stdio.h>
#include <stdlib.h>

int static compare(const void *n, const void *m);
typedef struct Coord
{
    int x, y;
} Coord;

int main()
{
    int n;
    Coord arr[100001];
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);
    qsort(arr, n, sizeof(Coord), compare);

    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].x, arr[i].y);

    return 0;
}

int static compare(const void *n, const void *m)
{
    Coord *ptn = (Coord *)n;
    Coord *ptm = (Coord *)m;

    if (ptn->x > ptm->x)
        return 1;
    else if (ptn->x < ptm->x)
        return -1;
    else if (ptn->x == ptm->x)
        if (ptn->y > ptm->y)
            return 1;
        else if (ptn->y < ptm->y)
            return -1;
        else
            return 0;
    else
        return 0;
}
