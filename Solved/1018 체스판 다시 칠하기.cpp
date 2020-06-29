//* https://www.acmicpc.net/problem/1018
//* Silver 5

#include <stdio.h>
#include <algorithm>
using namespace std;
;

const int MAX = 50;

char board[MAX][MAX]; //* 입력이 들어올 보드

//* (0,0)이 White인 경우의 보드의 예시
char whiteFirst[10][10] = {
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
};

//* (0,0)이 Black인 경우의 보드의 예시
char blackFirst[10][10] = {
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
    {"BWBWBWBW"},
    {"WBWBWBWB"},
};

//* (0,0)이 White인 경우, 바뀔 칸 수
int whiteFirstChange(int y, int x)
{
    int cnt = 0;
    for (int i = y; i < y + 8; i++)
        for (int j = x; j < x + 8; j++)
            board[i][j] != whiteFirst[i - y][j - x] ? cnt++ : 0;
    return cnt;
}

//* (0,0)이 Black인 경우, 바뀔 칸 수
int blackFirstChange(int y, int x)
{
    int cnt = 0;
    for (int i = y; i < y + 8; i++)
        for (int j = x; j < x + 8; j++)
            board[i][j] != blackFirst[i - y][j - x] ? cnt++ : 0;
    return cnt;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", board[i]);

    int result = MAX * MAX + 1;

    for (int i = 0; i + 7 < n; i++)
        for (int j = 0; j + 7 < m; j++)
            result = min(result, min(whiteFirstChange(i, j), blackFirstChange(i, j)));

    printf("%d", result);
    return 0;
}