//* https://www.acmicpc.net/problem/15829
//* Bronze 2

#include <stdio.h>
#include <string.h>

int main()
{
    int MOD = 1234567891;
    int MULTIPLY = 31;

    int L;
    scanf("%d", &L);

    char str[51];
    scanf("%s", str);

    long long sum = 0;
    long long R = 1;

    for (int i = 0; i < strlen(str); i++)
    {
        sum = (sum + (str[i] - 'a' + 1) * R) % MOD;
        R = (R * MULTIPLY) % MOD;
    }

    printf("%lld", sum);

    return 0;
}