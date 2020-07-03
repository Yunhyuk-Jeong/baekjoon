//* https://www.acmicpc.net/problem/1259
//* Bronze 1

#include <stdio.h>
#include <string.h>

int main()
{
    bool palindrome = false;
    char number[100001];

    while (true)
    {
        scanf("%s", number);
        if (!strcmp(number, "0"))
            return 0;
        int len = strlen(number);
        char number2[100001];
        for (int i = 0; i < len; i++)
            number2[i] = number[len - 1 - i];
        if (!strcmp(number, number2))
            printf("yes\n");
        else
            printf("no\n");
    }
}