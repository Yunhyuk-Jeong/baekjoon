//* https://www.acmicpc.net/problem/16163
//^ Platinum 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s))
        return 0;
    const int n = (int)s.size();

    //* 변환 문자열: ^#a#b#...#z#$  (경계 센티넬로 비교 안전)
    string t;
    t.reserve(2 * n + 3);
    t.push_back('^');
    t.push_back('#');
    for (char c : s)
    {
        t.push_back(c);
        t.push_back('#');
    }
    t.push_back('$');

    const int m = (int)t.size();
    vector<int> p(m, 0); //* p[i]: 변환 문자열에서 i를 중심으로 한 팰린드롬 반지름
    int center = 0, right = 0;

    for (int i = 1; i < m - 1; ++i)
    {
        int mirror = 2 * center - i;
        if (i < right)
            p[i] = min(right - i, p[mirror]);

        while (t[i + p[i] + 1] == t[i - p[i] - 1])
            ++p[i];

        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
    }

    //* 팰린드롬 부분 문자열 개수: sum((p[i] + 1) / 2)
    //* (변환 문자열 기준 반지름에서 실제 개수로 환산)
    long long ans = 0;
    for (int i = 1; i < m - 1; ++i)
        ans += (p[i] + 1) / 2;

    cout << ans << '\n';
    return 0;
}
