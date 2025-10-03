//* https://www.acmicpc.net/problem/1012
//* Silver 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    if (!(cin >> N >> M))
        return 0;

    vector<string> A(N), B(M);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < M; ++i)
        cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<string> both;
    both.reserve(min(N, M));

    int i = 0, j = 0;
    while (i < N && j < M)
    {
        if (A[i] == B[j])
        {
            both.push_back(A[i]);
            ++i;
            ++j;
        }
        else if (A[i] < B[j])
            ++i;
        else
            ++j;
    }

    ostringstream out;
    out << both.size() << '\n';
    for (const auto &name : both)
        out << name << '\n';
    cout << out.str();

    return 0;
}