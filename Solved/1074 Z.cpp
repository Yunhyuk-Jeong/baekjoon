//* https://www.acmicpc.net/problem/1074
//* Gold 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long r, c;
    if (!(cin >> N >> r >> c))
        return 0;

    long long idx = 0; //* 방문 순서
    for (int k = 0; k < N; ++k)
    {
        //* c의 k번째 비트를 인덱스의 2k번째 비트로
        idx |= ((c >> k) & 1LL) << (2 * k);
        //* r의 k번째 비트를 인덱스의 2k+1번째 비트로
        idx |= ((r >> k) & 1LL) << (2 * k + 1);
    }

    cout << idx << '\n';
    return 0;
}
