//* https://www.acmicpc.net/problem/2675
//* Bronze 2

#include <stdio.h>
#include <string.h>

int main()
{
    int number, repeatNumber[1001], repeatLength[1001];
    char repeatString[1001][50];

    scanf("%d", &number);

    for (int i = 0; i < number; i++)
    {
        scanf("%d %s", repeatNumber[i], repeatString[i]);
        repeatLength[i] = strlen(repeatString[i]);
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < repeatLength[i]; j++)
            for (int k = 0; k < repeatNumber[i]; k++)
                printf("%c", repeatString[i][j]);
        printf("\n");
    }
}