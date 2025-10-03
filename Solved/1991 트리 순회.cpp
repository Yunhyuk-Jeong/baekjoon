//* https://www.acmicpc.net/problem/1991
//* Silver 1

#include <bits/stdc++.h>
using namespace std;

int L[26], R[26];

void preorder(int u)
{
    if (u == -1)
        return;
    cout << char('A' + u);
    preorder(L[u]);
    preorder(R[u]);
}

void inorder(int u)
{
    if (u == -1)
        return;
    inorder(L[u]);
    cout << char('A' + u);
    inorder(R[u]);
}

void postorder(int u)
{
    if (u == -1)
        return;
    postorder(L[u]);
    postorder(R[u]);
    cout << char('A' + u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < 26; ++i)
        L[i] = R[i] = -1;

    for (int i = 0; i < N; ++i)
    {
        char a, b, c;
        cin >> a >> b >> c;
        int u = a - 'A';
        L[u] = (b == '.') ? -1 : (b - 'A');
        R[u] = (c == '.') ? -1 : (c - 'A');
    }

    int root = 0;
    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    return 0;
}