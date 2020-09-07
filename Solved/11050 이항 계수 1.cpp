//* https://www.acmicpc.net/problem/11050
//* Bronze 1

#include <stdio.h>

int main()
{
    int n, k;
    int fac[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    scanf("%d %d", &n, &k);
    printf("%d", fac[n - 1] / (fac[k - 1] * fac[n - k - 1]));
    return 0;
}