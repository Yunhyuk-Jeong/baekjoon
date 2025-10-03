//* https://www.acmicpc.net/problem/5026
//* Bronze 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //* 개행 처리

    ostringstream out;
    for (int i = 0; i < N; ++i)
    {
        string s;
        getline(cin, s);
        if (s == "P=NP")
        {
            out << "skipped\n";
        }
        else
        {
            // "a+b" 형태
            size_t p = s.find('+');
            int a = stoi(s.substr(0, p));
            int b = stoi(s.substr(p + 1));
            out << (a + b) << '\n';
        }
    }
    cout << out.str();
    return 0;
}
