//* https://www.acmicpc.net/problem/18110
//* Silver 4

#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int static compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return 1;
    else if (*(int *)first < *(int *)second)
        return -1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, opi[400000];
    int sum = 0;
    int trim;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> opi[i];

    qsort(opi, n, sizeof(int), compare);

    trim = floor(((double)n / 100 * 15) + 0.5);

    for (int i = trim; i < n - trim; i++)
        sum += opi[i];

    cout << floor((double)sum / (n - (trim * 2)) + 0.5);

    return 0;
}
