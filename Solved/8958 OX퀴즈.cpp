//* https://www.acmicpc.net/problem/8958
//* Bronze 2

#include <stdio.h>
#include <string.h>

int main()
{
    int n, number[100001] = {
               0,
           };
    char string[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int k = 1;
        scanf("%s", string);
        int len = strlen(string);
        for (int j = 0; j < len; j++)
        {
            if (string[j] == 'O')
            {
                number[i] += k;
                k++;
            }
            else
            {
                k = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", number[i]);

    return 0;
}