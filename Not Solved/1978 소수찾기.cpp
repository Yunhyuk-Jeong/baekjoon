//* https://www.acmicpc.net/problem/1978
//* Silver 4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime_check(int n)
{
    int m = sqrt((double)n) + 1;
    for (int i = 2; i <= m; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n, prime = 0, input;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if (input != 1)
            prime += prime_check(input);
    }

    printf("%d", prime);

    return 0;
}