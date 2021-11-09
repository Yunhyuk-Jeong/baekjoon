//* https://www.acmicpc.net/problem/2292
//* Bronze 2

#include <stdio.h>

int main()
{
    int n, m, answer;

    scanf("%d", &n);

    if (n == 1)
    {
        printf("1");
        return 0;
    }

    int lineNumber = (n - 2) / 6;
    int temp = 0;

    for (int i = 1;; i++)
    {
        temp += i;
        if (lineNumber < temp)
        {
            answer = i;
            break;
        }
    }

    printf("%d", answer + 1);

    return 0;
}