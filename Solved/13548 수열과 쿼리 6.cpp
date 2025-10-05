//* https://www.acmicpc.net/problem/13548
//* Platinum 1

#include <bits/stdc++.h>
using namespace std;

struct Query
{
    int l, r, idx, block;
    bool operator<(const Query &o) const
    {
        if (block != o.block)
            return block < o.block;
        //* 홀짝 블록에 따라 r 정렬 방향 바꾸기 (스네이크)
        if (block & 1)
            return r > o.r;
        return r < o.r;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N))
        return 0;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> a[i];

    //* 좌표 압축
    vector<int> comp(a.begin() + 1, a.end());
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 1; i <= N; ++i)
    {
        a[i] = int(lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin()) + 1; //* 1..M
    }
    int M = (int)comp.size();

    int Q;
    cin >> Q;
    vector<Query> qs(Q);
    int B = max(1, (int)(sqrt(N))); //* 블록 크기
    for (int i = 0; i < Q; ++i)
    {
        int l, r;
        cin >> l >> r;
        qs[i] = {l, r, i, l / B};
    }
    sort(qs.begin(), qs.end());

    vector<int> cnt(M + 1, 0);
    vector<int> freqOfFreq(N + 1, 0); //* 빈도의 빈도: 최대 빈도는 N을 넘지 않음
    vector<int> ans(Q);

    int curL = 1, curR = 0;
    int curMax = 0;

    auto add = [&](int pos) {
        int x = a[pos];
        int c = cnt[x];
        if (c > 0)
            freqOfFreq[c]--;
        cnt[x] = ++c;
        freqOfFreq[c]++;
        if (c > curMax)
            curMax = c;
    };
    auto remove = [&](int pos) {
        int x = a[pos];
        int c = cnt[x];
        freqOfFreq[c]--;
        cnt[x] = --c;
        if (c > 0)
            freqOfFreq[c]++;
        while (curMax > 0 && freqOfFreq[curMax] == 0)
            curMax--;
    };

    for (const auto &q : qs)
    {
        int L = q.l, R = q.r;
        while (curL > L)
            add(--curL);
        while (curR < R)
            add(++curR);
        while (curL < L)
            remove(curL++);
        while (curR > R)
            remove(curR--);
        ans[q.idx] = curMax;
    }

    ostringstream out;
    for (int i = 0; i < Q; ++i)
        out << ans[i] << '\n';
    cout << out.str();
    return 0;
}