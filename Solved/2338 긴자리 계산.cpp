//* https://www.acmicpc.net/problem/2338
//* Bronze 5

#include <bits/stdc++.h>
using namespace std;

//* 문자열 형태의 큰 정수 구조체
struct BigInt
{
    //* 음의 값은 `sign = -1`, 양수 혹은 0은 `sign = +1`
    int sign;
    string digits; //* 절댓값, 앞엔 0 없음 (예: "0", "12345")

    BigInt() : sign(1), digits("0")
    {
    }
    BigInt(string s)
    {
        if (s[0] == '-')
        {
            sign = -1;
            digits = s.substr(1);
        }
        else
        {
            sign = 1;
            digits = s;
        }
        //* 앞의 0 제거
        while (digits.size() > 1 && digits[0] == '0')
        {
            digits.erase(digits.begin());
        }
        if (digits == "0")
            sign = 1; //* 0은 양수로 간주
    }
};

//* 절댓값 비교: |a| > |b| 인가?
bool absGreater(const BigInt &a, const BigInt &b)
{
    if (a.digits.size() != b.digits.size())
        return a.digits.size() > b.digits.size();
    return a.digits > b.digits;
}

//* 두 양수 문자열 덧셈 (digits 내림차순 아님, 앞이 가장 큰 자리)
string addPos(const string &a, const string &b)
{
    int na = a.size(), nb = b.size();
    int n = max(na, nb);
    string A = string(n - na, '0') + a;
    string B = string(n - nb, '0') + b;
    string res(n + 1, '0');
    int carry = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        int da = A[i] - '0';
        int db = B[i] - '0';
        int sum = da + db + carry;
        res[i + 1] = char((sum % 10) + '0');
        carry = sum / 10;
    }
    res[0] = char(carry + '0');
    //* 앞에 0 제거
    if (res[0] == '0')
        return res.substr(1);
    else
        return res;
}

//* 양수 문자열 a ≥ b에 대해 뺄셈 (a - b), 결과도 양수 문자열
string subPos(const string &a, const string &b)
{
    //* assume a >= b in abs
    int na = a.size(), nb = b.size();
    string B = string(na - nb, '0') + b;
    string res(na, '0');
    int borrow = 0;
    for (int i = na - 1; i >= 0; --i)
    {
        int da = a[i] - '0' - borrow;
        int db = B[i] - '0';
        if (da < db)
        {
            da += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        res[i] = char((da - db) + '0');
    }
    //* 앞의 0 제거
    int idx = 0;
    while (idx + 1 < (int)res.size() && res[idx] == '0')
        idx++;
    return res.substr(idx);
}

//* 덧셈: a + b
BigInt addBig(const BigInt &a, const BigInt &b)
{
    BigInt res;
    if (a.sign == b.sign)
    {
        res.sign = a.sign;
        res.digits = addPos(a.digits, b.digits);
    }
    else
    {
        //* 부호 다름: 큰 쪽 절댓값에서 작은 쪽 빼기
        if (absGreater(a, b))
        {
            res.sign = a.sign;
            res.digits = subPos(a.digits, b.digits);
        }
        else
        {
            res.sign = b.sign;
            res.digits = subPos(b.digits, a.digits);
        }
    }
    if (res.digits == "0")
        res.sign = 1;
    return res;
}

//* 뺄셈: a - b
BigInt subBig(const BigInt &a, const BigInt &b)
{
    BigInt negb = b;
    negb.sign = -b.sign;
    return addBig(a, negb);
}

//* 곱셈: a * b
BigInt mulBig(const BigInt &a, const BigInt &b)
{
    BigInt res;
    res.sign = a.sign * b.sign;
    int na = a.digits.size(), nb = b.digits.size();
    vector<int> tmp(na + nb, 0);
    for (int i = na - 1; i >= 0; --i)
    {
        for (int j = nb - 1; j >= 0; --j)
        {
            int da = a.digits[i] - '0';
            int db = b.digits[j] - '0';
            tmp[i + j + 1] += da * db;
        }
    }
    //* 자리 올림
    for (int i = na + nb - 1; i > 0; --i)
    {
        tmp[i - 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    //* vector → 문자열
    string s;
    for (int v : tmp)
        s.push_back(char(v + '0'));
    //* 앞의 0 제거
    int idx = 0;
    while (idx + 1 < (int)s.size() && s[idx] == '0')
        idx++;
    s = s.substr(idx);
    res.digits = s;
    if (res.digits == "0")
        res.sign = 1;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string sa, sb;
    cin >> sa >> sb;
    BigInt A(sa), B(sb);

    BigInt sum = addBig(A, B);
    BigInt diff = subBig(A, B);
    BigInt prod = mulBig(A, B);

    //* 출력
    if (sum.sign < 0)
        cout << '-';
    cout << sum.digits << "\n";
    if (diff.sign < 0)
        cout << '-';
    cout << diff.digits << "\n";
    if (prod.sign < 0)
        cout << '-';
    cout << prod.digits << "\n";

    return 0;
}
