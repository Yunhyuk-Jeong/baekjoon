//* https://www.acmicpc.net/problem/1546
//* Bronze 1

#include <stdio.h>

int main()
{
    int scoreCount,               //* 들어오는 점수의 갯수
        scoreData[1020],          //* 들어올 정수 점수
        scoreMax = -1;            //* 들어온 최대 정수 점수
    double scoreDataUpdate[1020], //* 변환된 실수 점수
        scoreDataSum = 0;         //* 실수 점수의 평균

    scanf("%d", &scoreCount);
    for (int i = 0; i < scoreCount; i++)
    {
        scanf("%d", &scoreData[i]);
        scoreMax < scoreData[i] ? scoreMax = scoreData[i] : 0;
    }

    for (int i = 0; i < scoreCount; i++)
    {
        scoreDataUpdate[i] = (double)scoreData[i] / scoreMax * 100;
        scoreDataSum += scoreDataUpdate[i];
    }

    printf("%.2lf", scoreDataSum / scoreCount);
    return 0;
}