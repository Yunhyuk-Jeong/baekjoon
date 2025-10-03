//* https://www.acmicpc.net/problem/1017
//* Platinum 3

#include <bits/stdc++.h>
using namespace std;

static const int MAXV = 2000; //* 값 합의 상한(≤1000+1000)

vector<int> A;
vector<vector<int>> adj; //* L -> R
vector<int> Lidx, Ridx;
vector<int> matchR, matchL;
vector<int> vis;
vector<int> isPrime;

void buildPrimes()
{
    isPrime.assign(MAXV + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int p = 2; p * p <= MAXV; ++p)
        if (isPrime[p])
            for (int q = p * p; q <= MAXV; q += p)
                isPrime[q] = 0;
}

//* cand: L[0]이 반드시 매칭되어야 하는 R의 인덱스
bool dfs(int u, int cand)
{
    for (int v : adj[u])
    {
        //* cand는 L[0]만 사용할 수 있게 고정: u!=0이면 cand로 가는 간선 금지
        if (u != 0 && v == cand)
            continue;
        if (vis[v])
            continue;
        vis[v] = 1;

        //* cand는 L[0]에게 이미 배정되어 있으므로, matchR[v]==0인 경우는 v==cand 뿐
        //* 그 외의 경우에만 증강 경로 탐색
        if (matchR[v] == -1 || (matchR[v] != 0 && dfs(matchR[v], cand)))
        {
            matchR[v] = u;
            matchL[u] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    A.resize(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    //* 홀짝 개수 다르면 절대 불가
    int odd = 0, even = 0;
    for (int x : A)
        (x & 1 ? odd : even)++;
    if (odd != even)
    {
        cout << -1 << '\n';
        return 0;
    }

    buildPrimes();

    //* a[0]의 홀짝에 따라 L/R 분할 (L은 a[0]과 같은 홀짝)
    bool firstOdd = (A[0] & 1);
    for (int i = 0; i < N; ++i)
    {
        if ((A[i] & 1) == (firstOdd ? 1 : 0))
            Lidx.push_back(i);
        else
            Ridx.push_back(i);
    }

    int nL = (int)Lidx.size(), nR = (int)Ridx.size();

    //* 인접리스트 구성: 합이 소수면 간선
    adj.assign(nL, {});
    for (int i = 0; i < nL; ++i)
        for (int j = 0; j < nR; ++j)
            if (isPrime[A[Lidx[i]] + A[Ridx[j]]])
                adj[i].push_back(j);

    vector<int> answers;

    //* L[0]과 연결된 R 후보를 하나씩 "고정"해서 완전매칭 가능한지 검사
    for (int cand : adj[0])
    {
        matchR.assign(nR, -1);
        matchL.assign(nL, -1);

        //* L[0] <-> cand 고정
        matchR[cand] = 0;
        matchL[0] = cand;

        int matched = 1;
        for (int u = 1; u < nL; ++u)
        {
            vis.assign(nR, 0);
            if (dfs(u, cand))
                matched++;
        }

        if (matched == nL)
        {
            answers.push_back(A[Ridx[cand]]);
        }
    }

    if (answers.empty())
    {
        cout << -1 << '\n';
    }
    else
    {
        sort(answers.begin(), answers.end());
        for (size_t i = 0; i < answers.size(); ++i)
        {
            if (i)
                cout << ' ';
            cout << answers[i];
        }
        cout << '\n';
    }
    return 0;
}
