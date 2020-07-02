//* https://www.acmicpc.net/problem/10809
//* Bronze 2

#include <stdio.h>
#include <string.h>

int main()
{
    int alpha[26];
    char inputString[110];

    for (int i = 0; i < 26; i++)
        alpha[i] = -1;

    scanf("%s", inputString);

    int len = strlen(inputString);

    for (int i = 0; i < len; i++)
        if (alpha[inputString[i] - 97] == -1)
            alpha[inputString[i] - 97] = i;

    for (int i = 0; i < 26; i++)
        printf("%d ", alpha[i]);

    return 0;
}