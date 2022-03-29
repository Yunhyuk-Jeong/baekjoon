//* https://www.acmicpc.net/problem/1874
//* Silver 3

//! TimeOver

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>


using namespace std;

int main()
{
    int n, temp;
    queue<int> q;
    stack<int> s;
    queue<char> ans;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        q.push(temp);
    }

    int m = 1;

    while (q.size())
    {
        if (s.size() && s.top() == q.front())
        {
            s.pop();
            q.pop();
            ans.push('-');
        }

        else if (m <= q.front())
        {
            while (m <= q.front())
            {
                s.push(m++);
                ans.push('+');
            }
        }

        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    while (ans.size())
    {
        cout << ans.front() << endl;
        ans.pop();
    }

    return 0;
}