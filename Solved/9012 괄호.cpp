//* https://www.acmicpc.net/problem/9012
//* Silver 4

#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    int boolen[100000] = {
        0,
    };
    char paren[100000][100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%s", paren[i]);

    for (int i = 0; i < n; i++)
    {
        int chk = 0;
        int len = strlen(paren[i]);
        for (int j = 0; j < len; j++)
        {
            if (chk < 0)
            {
                boolen[i] = 0;
                break;
            }

            if (paren[i][j] == '(')
                chk++;
            else if (paren[i][j] == ')')
                chk--;
        }
        if (chk != 0)
            boolen[i] = 0;
        else
            boolen[i] = 1;
    }

    for (int i = 0; i < n; i++)
        printf("%s\n", boolen[i] == 0 ? "NO" : "YES");

    return 0;
}