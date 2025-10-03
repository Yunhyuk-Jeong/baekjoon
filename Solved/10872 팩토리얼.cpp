//* https://www.acmicpc.net/problem/10872
//* Bronze 3

#include <bits/stdc++.h>
using namespace std;

long long fact(int n)
{
    if (n <= 1)
        return 1;
    return (long long)n * fact(n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    cout << fact(N) << '\n';
    return 0;
}
