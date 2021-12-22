//* https://www.acmicpc.net/problem/1966
//* Silver 3

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int count = 0;
    int test_case;

    cin >> test_case;

    int n, m, imp;

    for (int i = 0; i < test_case; ++i)
    {
        count = 0;

        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int j = 0; j < n; ++j)
        {
            cin >> imp;

            q.push({j, imp});
            pq.push(imp);
        }

        while (!q.empty())
        {
            int index = q.front().first;
            int value = q.front().second;

            q.pop();

            if (pq.top() == value)
            {
                pq.pop();

                count++;

                if (index == m)
                {
                    cout << count << endl;
                    break;
                }
            }
            else
                q.push({index, value});
        }
    }

    return 0;
}