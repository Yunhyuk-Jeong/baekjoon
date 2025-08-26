//* https://www.acmicpc.net/problem/30802
//* Bronze 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;
    vector<long long> sizes(6);
    for (int i = 0; i < 6; i++)
        cin >> sizes[i];

    long long T, P;
    cin >> T >> P;

    // 티셔츠 최소 묶음 수
    long long tshirtBundles = 0;
    for (long long x : sizes)
    {
        tshirtBundles += (x + T - 1) / T; // ceil(x / T)
    }
    cout << tshirtBundles << "\n";

    // 펜 묶음 & 낱개 수
    cout << (N / P) << " " << (N % P) << "\n";

    return 0;
}
