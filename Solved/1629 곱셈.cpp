//* https://www.acmicpc.net/problem/1629
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

long long mod_pow(long long a, long long b, long long mod)
{
    a %= mod;
    long long res = 1 % mod;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod; //* 홀수 지수면 한 번 곱함
        a = (a * a) % mod;         //* 밑을 제곱
        b >>= 1;                   //* 지수 반으로
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    if (!(cin >> a >> b >> c))
        return 0;
    cout << mod_pow(a, b, c) << '\n';
    return 0;
}