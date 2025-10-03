//* https://www.acmicpc.net/problem/15680
//* Bronze 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;
    cout << (n == 0 ? "YONSEI" : "Leading the Way to the Future") << '\n';
    return 0;
}
