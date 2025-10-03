//* https://www.acmicpc.net/problem/18115
//* Silver 3

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> op(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> op[i];

    deque<int> dq;
    int card = 1; //* 역으로 넣을 카드 번호: 1,2,...,N
    for (int i = N; i >= 1; --i, ++card)
    {
        if (op[i] == 1)
        {
            dq.push_front(card); //* 맨 위에 내려놓기의 역
        }
        else if (op[i] == 2)
        {
            if (!dq.empty())
            { //* 두 번째에 내려놓기의 역
                int first = dq.front();
                dq.pop_front();
                dq.push_front(card);
                dq.push_front(first); //* card가 두 번째로 오도록
            }
            else
            {
                dq.push_front(card);
            }
        }
        else
        {                       //* op[i] == 3
            dq.push_back(card); //* 맨 아래에 내려놓기의 역
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << dq[i] << (i + 1 == N ? '\n' : ' ');
    }
    return 0;
}
