//* https://www.acmicpc.net/problem/10999
//* Platinum 4

#include <cstring>
#include <iostream>
#include <vector>

#define fastio                                                                                                         \
    ios_base::sync_with_stdio(false);                                                                                  \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define MAX 1000001

typedef long long ll;
using namespace std;

int N, M, K;
ll arr[MAX];
ll tree[MAX * 4];
ll lazy[MAX * 4];

// 입력 받기
void input()
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
}

// 세그먼트 트리 초기화
ll buildTree(int start, int end, int node)
{
    if (start == end)
        return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = buildTree(start, mid, node * 2) + buildTree(mid + 1, end, node * 2 + 1);
}

// Lazy 업데이트 처리
void propagateLazy(int start, int end, int node)
{
    if (lazy[node] != 0)
    { // Lazy 값이 존재하면
        tree[node] += (lazy[node] * (end - start + 1));
        if (start != end)
        { // 리프 노드가 아니라면 lazy 값을 자식들에게 전파
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0; // 현재 노드의 lazy 값 초기화
    }
}

// 구간 합 쿼리 (b~c 구간 합)
ll query(int start, int end, int left, int right, int node)
{
    propagateLazy(start, end, node); // Lazy 업데이트 먼저 수행

    if (right < start || left > end)
        return 0; // 범위를 벗어남
    if (left <= start && end <= right)
        return tree[node]; // 범위 완전히 포함됨

    int mid = (start + end) / 2;
    return query(start, mid, left, right, node * 2) + query(mid + 1, end, left, right, node * 2 + 1);
}

// 구간 업데이트 (b~c 범위에 d 추가)
void update(int start, int end, int left, int right, ll value, int node)
{
    propagateLazy(start, end, node); // Lazy 값 적용

    if (right < start || left > end)
        return; // 범위를 벗어나면 return
    if (left <= start && end <= right)
    { // 범위가 완전히 포함될 경우
        tree[node] += (value * (end - start + 1));
        if (start != end)
        { // 자식 노드에 lazy 값을 저장
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, left, right, value, node * 2);
    update(mid + 1, end, left, right, value, node * 2 + 1);
    tree[node] = tree[node * 2] + tree[node * 2 + 1]; // 부모 노드 갱신
}

// 문제 해결 (업데이트 및 구간 합 연산 수행)
void solve()
{
    buildTree(1, N, 1);
    int a, b, c;
    ll d;
    for (int i = 0; i < K + M; i++)
    {
        cin >> a;
        if (a == 1)
        { // 구간 업데이트 (b~c 범위에 d 추가)
            cin >> b >> c >> d;
            update(1, N, b, c, d, 1);
        }
        else
        { // 구간 합 쿼리 (b~c 구간 합 출력)
            cin >> b >> c;
            cout << query(1, N, b, c, 1) << "\n";
        }
    }
}

int main()
{
    fastio;
    input();
    solve();
    return 0;
}
