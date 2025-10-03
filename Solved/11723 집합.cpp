//* https://www.acmicpc.net/problem/11723
//* Silver 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    int S = 0; // 집합을 비트마스크로 표현 (0~19 비트 사용)

    while (M--)
    {
        string op;
        int x;
        cin >> op;

        if (op == "add")
        {
            cin >> x;
            S |= (1 << (x - 1));
        }
        else if (op == "remove")
        {
            cin >> x;
            S &= ~(1 << (x - 1));
        }
        else if (op == "check")
        {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << "\n";
        }
        else if (op == "toggle")
        {
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if (op == "all")
        {
            S = (1 << 20) - 1;
        }
        else if (op == "empty")
        {
            S = 0;
        }
    }

    return 0;
}
