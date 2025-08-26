//* https://www.acmicpc.net/problem/18917
//* Silver 4

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    if (!(cin >> M))
        return 0;

    // 초기 배열 A = [0]
    long long sumAll = 0; // A의 원소 총합
    long long xorAll = 0; // A의 원소 XOR

    // (선택) 존재 보장을 위해 개수만 추적 – 문제에서 항상 유효한 삭제만 준다고 했으니
    // 없어도 되지만, 디버깅/안전용으로 둡니다.
    unordered_map<long long, long long> cnt;
    cnt[0] = 1; // 처음에 0 하나 포함

    while (M--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            long long x;
            cin >> x;
            sumAll += x;
            xorAll ^= x;
            ++cnt[x];
        }
        else if (t == 2)
        {
            long long x;
            cin >> x;
            // 항상 존재한다고 주어짐
            sumAll -= x;
            xorAll ^= x;
            if (--cnt[x] == 0)
                cnt.erase(x);
        }
        else if (t == 3)
        {
            cout << sumAll << '\n';
        }
        else if (t == 4)
        {
            cout << xorAll << '\n';
        }
    }
    return 0;
}
