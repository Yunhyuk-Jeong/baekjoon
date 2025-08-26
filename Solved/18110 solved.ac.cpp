//* https://www.acmicpc.net/problem/18110
//* Silver 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    if (N == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    // 반올림: (x + 0.5) 사용
    int cut = int((N * 0.15) + 0.5);

    long long sum = 0;
    for (int i = cut; i < N - cut; i++)
    {
        sum += arr[i];
    }

    int cnt = N - 2 * cut;
    int ans = int((double)sum / cnt + 0.5);

    cout << ans << "\n";
    return 0;
}
