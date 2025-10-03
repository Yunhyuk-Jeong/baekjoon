//* https://www.acmicpc.net/problem/1918
//* Gold 2

#include <bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0; //* '(' 등
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<char> st;
    string output;

    for (char c : s)
    {
        if (isalpha(c))
        {
            output.push_back(c);
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output.push_back(st.top());
                st.pop();
            }
            if (!st.empty())
                st.pop(); //* '(' 제거
        }
        else
        {
            //* 연산자 + - * /
            while (!st.empty() && precedence(st.top()) >= precedence(c))
            {
                if (st.top() == '(')
                    break;
                output.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        output.push_back(st.top());
        st.pop();
    }

    cout << output << "\n";
    return 0;
}
