//* https://www.acmicpc.net/problem/28702
//* Bronze 1

#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string &s)
{
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

string fizzbuzz(long long x)
{
    if (x % 15 == 0)
        return "FizzBuzz";
    if (x % 3 == 0)
        return "Fizz";
    if (x % 5 == 0)
        return "Buzz";
    return to_string(x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> s(3);
    for (int i = 0; i < 3; i++)
        cin >> s[i];

    long long start = -1;

    if (isNumber(s[0]))
    {
        start = stoll(s[0]);
    }
    else if (isNumber(s[1]))
    {
        start = stoll(s[1]) - 1;
    }
    else if (isNumber(s[2]))
    {
        start = stoll(s[2]) - 2;
    }

    if (start != -1)
    {
        cout << fizzbuzz(start + 3) << '\n';
        return 0;
    }

    for (int i = 1; i <= 15; ++i)
    {
        if (fizzbuzz(i) == s[0] && fizzbuzz(i + 1) == s[1] && fizzbuzz(i + 2) == s[2])
        {
            cout << fizzbuzz(i + 3) << '\n';
            return 0;
        }
    }

    return 0;
}
