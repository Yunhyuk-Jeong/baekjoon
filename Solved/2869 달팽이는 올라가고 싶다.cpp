//* https://www.acmicpc.net/problem/2869
//* Bronze 1

#include <stdio.h>

int main()
{
    int A, B, V, progress = 0;

    scanf("%d %d %d", &A, &B, &V);

    int temp = A - B;

    progress += ((V - A) / temp) + 1;
    if ((V - A) % temp != 0)
        progress += 1;

    printf("%d", progress);

    return 0;
}