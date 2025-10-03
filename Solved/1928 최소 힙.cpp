//* https://www.acmicpc.net/problem/1927
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

    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    ostringstream out;

    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            if (pq.empty())
                out << 0 << '\n';
            else
            {
                out << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(x);
        }
    }

    cout << out.str();
    return 0;
}
