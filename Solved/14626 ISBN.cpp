//* https://www.acmicpc.net/problem/14626
//* Bronze 1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s))
        return 0; //* 예: 9788968322*73 (길이 13)

    int star = -1;
    for (int i = 0; i < 13; ++i)
        if (s[i] == '*')
            star = i;

    auto weight = [](int i) { return (i % 2 == 0) ? 1 : 3; };

    //* 체크기호(마지막 자리)
    int m = s[12] - '0';

    //* *와 체크기호를 제외한 가중합
    int sum = 0;
    for (int i = 0; i < 12; ++i)
    {
        if (i == star)
            continue;
        sum += (s[i] - '0') * weight(i);
    }

    //* w * x ≡ need (mod 10)
    int w = weight(star);
    int need = (10 - ((sum + m) % 10)) % 10;

    int x;
    if (w == 1)
        x = need;
    else
    { //* w == 3, 3의 역원은 7 (mod 10), 3*7 ≡ 1
        x = (7 * need) % 10;
    }

    cout << x << '\n';
    return 0;
}
