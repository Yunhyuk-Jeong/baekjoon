#include <stdio.h>

int main()
{
    int score;
    scanf("%d", &score);
    printf("%s", score >= 90 ? "A" : score >= 80 ? "B" : score >= 70 ? "C" : score >= 60 ? "D" : "F");
    return 0;
}