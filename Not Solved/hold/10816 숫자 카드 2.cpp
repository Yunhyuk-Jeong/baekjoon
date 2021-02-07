//* https://www.acmicpc.net/problem/10816
//* Silver 4

//! Time Over

#include <stdio.h>
#include <algorithm>

int card[600000], search[600000];

int binarySearch(int left, int right, int count, int searchNum)
{
    int mid = (left + right) / 2;
    int result;

    if (left > right)
        return count;
    else
    {
        if (card[mid] > searchNum)
            result = binarySearch(left, mid - 1, count, searchNum);
        else if (card[mid] < searchNum)
            result = binarySearch(mid + 1, right, count, searchNum);
        else
        {
            result = binarySearch(left, mid - 1, count, searchNum);
            result += binarySearch(mid + 1, right, count, searchNum);
            result += 1;
        }

        return result;
    }
}

int main()
{
    int n, m;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &card[i]);

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        scanf("%d", &search[i]);

    std::sort(card, card + n);

    for (int i = 0; i < m; i++)
    {
        int searchNum = search[i];
        int left = 0, right = n - 1;

        printf("%d ", binarySearch(left, right, 0, searchNum));
    }

    printf("\n");

    return 0;
}