//* https://www.acmicpc.net/problem/4008
//* Diamond 5

#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

struct Line
{
    long double m, b; //* 기울기, 절편 (교점 계산용 long double)
    long long M, B;   //* 정확한 값으로 평가할 때는 정수 사용
    long long evalLL(long long x) const
    {
        return M * x + B;
    }
};

//* 교점 x좌표: (b2 - b1) / (m1 - m2)  (m1 != m2 가정)
//* (덱 유지 시 비교에만 사용)
long double intersectX(const Line &l1, const Line &l2)
{
    //* 분모 0(동일 기울기)은 호출 전에 처리
    return (l2.b - l1.b) / (l1.m - l2.m);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long a, b, c;
    if (!(cin >> N >> a >> b >> c))
        return 0;

    vector<long long> X(N + 1), S(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        cin >> X[i];
        S[i] = S[i - 1] + X[i];
    }

    vector<long long> dp(N + 1, 0);

    deque<Line> dq;

    auto add_line = [&](long long M, long long B) {
        Line nl;
        nl.M = M;
        nl.B = B;
        nl.m = (long double)M;
        nl.b = (long double)B;

        //* 같은 기울기라면 절편 큰 것만 유지(최대 쿼리)
        if (!dq.empty() && dq.back().M == nl.M)
        {
            if (dq.back().B >= nl.B)
                return; //* 새 선이 열등
            dq.pop_back();
        }
        //* 뒤에서 두 개와 교점 비교해 단조성 유지
        while (dq.size() >= 2)
        {
            long double x1 = intersectX(dq[dq.size() - 2], dq.back());
            long double x2 = intersectX(dq.back(), nl);
            if (x1 >= x2)
                dq.pop_back();
            else
                break;
        }
        dq.push_back(nl);
    };

    auto query = [&](long long x) {
        //* x 비내림차순 가정 → 앞에서 불리한 선 제거
        while (dq.size() >= 2 && dq[0].evalLL(x) <= dq[1].evalLL(x))
            dq.pop_front();
        return dq.front().evalLL(x);
    };

    //* j=0 선 추가: m=-2a*S0=0, B=dp0+a*S0^2-b*S0 = 0
    add_line(0, 0);

    for (int i = 1; i <= N; ++i)
    {
        long long x = S[i];
        long long best = query(x);
        //* dp[i] = a*x^2 + b*x + c + best
        dp[i] = (long long)((i128)a * x * x + (i128)b * x + c + best);

        //* 다음을 위해 j=i 선 추가: M=-2a*S[i], B=dp[i]+a*S[i]^2 - b*S[i]
        long long M = (long long)((i128)(-2) * a * x);
        long long B = (long long)((i128)dp[i] + (i128)a * x * x - (i128)b * x);
        add_line(M, B);
    }

    cout << dp[N] << '\n';
    return 0;
}
