//* https://www.acmicpc.net/problem/2108
//* Silver 4

#include <iostream>
#include <stdlib.h>

using namespace std;

int num[500001] = {0};
int cnt[8001] = {0};

int cmp(const void *a, const void *b)
{
    if (*(int *)a > *(int *)b)
        return 1;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 0;
}

int maxFinder(int *arr, int sizeArr)
{
    int maxV = arr[0];
    for (int i = 0; i < sizeArr; i++)
        if (maxV < arr[i])
            maxV = arr[i];

    return maxV;
}

int main()
{
    int n, sum = 0, flag = 0;
    int min = 4001, max = -4001;
    int mode = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];

        if (min > num[i])
            min = num[i];
        if (max < num[i])
            max = num[i];

        cnt[num[i] + 4000]++;
    }

    for (int i = 0; i < 8001; i++)
        if (maxFinder(cnt, 8001) == cnt[i])
            flag++;

    for (int i = 0; i < 8001; i++)
    {
        if (flag == 1)
        {
            if (maxFinder(cnt, 8001) == cnt[i])
            {
                mode = i - 4000;
                break;
            }
        }
        else
        {
            if (maxFinder(cnt, 8001) == cnt[i])
            {
                if (flag == 0)
                {
                    mode = i - 4000;
                    break;
                }
                else
                    flag = 0;
            }
        }
    }

    qsort(num, n, sizeof(int), cmp);

    printf("%.0f\n%d\n%d\n%d\n", (double)sum / n, num[(n + 1) / 2 - 1], mode, max - min);

    return 0;
}
