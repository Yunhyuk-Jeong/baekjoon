//* https://www.acmicpc.net/problem/2805
//* Silver 3

#include <iostream>

#define INT_MAX 4294967295

using namespace std;

//* 나무의 수 n, 가져갈 나무의 길이 m, 나무의 길이 tree
unsigned int n, m, tree[1000001];

//* 선택한 길이 h로 계산했을 시, m을 충족하는지 T/F로 판별
bool isPossible(int h)
{
    //* 잘린 나무의 길이 cutted
    unsigned int cutted = 0;

    for (int i = 0; i < n; i++)
    {
        if (tree[i] > h)
            cutted += (tree[i] - h);
        if (cutted >= m)
            return true;
    }
    return false;
}

//* 이분탐색을 통하여 값을 찾음
int treeCut()
{
    //* 정답 가능성이 있는 값 treeRet
    int treeRet = 0;

    //* 이분탐색에 사용될 변수
    unsigned int left = 0, right = INT_MAX, mid;

    //* 이분탐색 실행
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (isPossible(mid))
        {
            treeRet = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return treeRet;
}

int main()
{
    //* 나무의 수와 가져갈 길이를 입력받음
    cin >> n >> m;

    //* 나무의 길이를 n번 입력받음
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    cout << treeCut() << endl;

    return 0;
}