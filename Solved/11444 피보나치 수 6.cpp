//* https://www.acmicpc.net/problem/11444
//* Gold 2

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

//* 2×2 행렬 구조체
struct Mat
{
    long long a[2][2];
    Mat()
    {
        a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
    }
};

//* 행렬 곱
Mat mul(const Mat &A, const Mat &B)
{
    Mat C;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            __int128 sum = 0;
            for (int k = 0; k < 2; k++)
            {
                sum += (__int128)A.a[i][k] * B.a[k][j];
            }
            C.a[i][j] = (long long)(sum % MOD);
        }
    }
    return C;
}

//* 행렬 거듭제곱 (A^e)
Mat mat_pow(Mat A, long long e)
{
    Mat res;
    //* 단위 행렬로 초기화
    res.a[0][0] = res.a[1][1] = 1;
    res.a[0][1] = res.a[1][0] = 0;

    while (e > 0)
    {
        if (e & 1)
            res = mul(res, A);
        A = mul(A, A);
        e >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    //* 기본 변환 행렬
    Mat T;
    T.a[0][0] = 1;
    T.a[0][1] = 1;
    T.a[1][0] = 1;
    T.a[1][1] = 0;

    //* T^(n-1)
    Mat R = mat_pow(T, n - 1);

    //* [ F(n), F(n-1) ]^T = R * [F(1), F(0)]^T = R * [1, 0]^T
    long long fn = R.a[0][0] * 1 + R.a[0][1] * 0;
    fn %= MOD;
    cout << fn << "\n";

    return 0;
}
