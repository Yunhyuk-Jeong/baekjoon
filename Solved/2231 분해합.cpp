//* https://www.acmicpc.net/problem/2231
//* Bronze 2

#include <stdio.h>

int main()
{
    int N, M, digit = 0, answer = 0;

    scanf("%d", &N);

    int n = N;

    for (int i = 0; 0 < n; i++)
    {
        n /= 10;
        digit++;
    }

    M = N - digit * 9;

    while (true)
    {
        int temp = 0, num = M;
        for (int i = 0; i < digit; i++)
        {
            temp += num % 10;
            num /= 10;
            if (num == 0)
                break;
        }
        if (M + temp == N)
        {
            answer = M;
            break;
        }
        else if (M == N)
            break;

        M++;
    }

    printf("%d", answer);

    return 0;
}