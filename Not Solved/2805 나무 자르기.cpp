//* https://www.acmicpc.net/problem/2805
//* Silver 3

#include <iostream>

using namespace std;

int main()
{
    //* 나무의 수 n, 가져갈 나무의 길이 m, 나무의 길이 tree
    //* 톱날의 높이 h, 잘린 나무의 길이 cutted
    int n, m, tree[1000001];
    int h = 0, cutted = 0;

    //* 나무의 수와 가져갈 길이를 입력받음
    cin >> n >> m;

    //* 나무의 길이를 n번 입력받음
    for (int i = 0; i < n; i++)
        cin >> tree[i];
}