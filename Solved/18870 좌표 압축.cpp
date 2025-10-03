//* https://www.acmicpc.net/problem/18870
//* Silver 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    //* 고유값 벡터 생성
    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end()); //* O(N)

    //* 각 원소의 압축 좌표 = 고유값 배열에서의 lower_bound 인덱스
    //* 총 O(N log N)
    ostringstream out;
    for (int x : a)
    {
        int idx = int(lower_bound(b.begin(), b.end(), x) - b.begin());
        out << idx << ' ';
    }
    cout << out.str() << '\n';
    return 0;
}
