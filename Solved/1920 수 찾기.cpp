//* https://www.acmicpc.net/problem/1920
//* Silver 4

#include <algorithm>
#include <iostream>

using namespace std;

int arr[100001];

int static compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return 1;
    else if (*(int *)first < *(int *)second)
        return -1;
    else
        return 0;
}

void solve(int n, int key)
{
    int start = 0;
    int end = n - 1;
    int mid;

    while (end - start >= 0)
    {
        mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            cout << "1\n";
            return;
        }
        else if (arr[mid] > key)
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << "0\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, tmp;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    qsort(arr, n, sizeof(int), compare);

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        solve(n, tmp);
    }

    return 0;
}