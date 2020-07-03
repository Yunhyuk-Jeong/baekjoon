//* https://www.acmicpc.net/problem/1181
//* Silver 5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int a_len = strlen((char *)a);
    int b_len = strlen((char *)b);

    if (a_len == b_len)
        return strcmp((char *)a, (char *)b);
    else if (a_len > b_len)
        return 1;
    else
        return -1;
}

int main()
{
    int num;
    char word[20002][51];

    scanf("%d", &num);

    for (int i = 0; i < num; i++)
        scanf("%s", word[i]);

    qsort(word, num, sizeof(word[0]), compare);

    for (int i = 0; i < num; i++)
    {
        if (!strcmp(word[i], word[i + 1]))
            continue;
        else
            printf("%s\n", word[i]);
    }
    return 0;
}