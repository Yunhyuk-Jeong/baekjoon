//* https://www.acmicpc.net/problem/9498
//* Bronze 4

#include <stdio.h>

int main()
{
    int score;
    scanf("%d", &score);
    printf("%s", score >= 90 ? "A" : score >= 80 ? "B" : score >= 70 ? "C" : score >= 60 ? "D" : "F");
    return 0;
}