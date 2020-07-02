//* https://www.acmicpc.net/problem/2920
//* Bronze 2

#include <stdio.h>

int main()
{
    int scale[8];
    int ascending = 0, descending = 0;

    for (int i = 0; i < 8; i++)
        scanf("%d", &scale[i]);

    for (int i = 0; i < 8; i++)
        scale[i] == i + 1 ? ascending++ : 0;
    for (int i = 0; i < 8; i++)
        scale[i] == 8 - i ? descending++ : 0;

    ascending == 8 ? printf("ascending") : descending == 8 ? printf("descending") : printf("mixed");
    return 0;
}