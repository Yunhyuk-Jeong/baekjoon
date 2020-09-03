//* https://www.acmicpc.net/problem/1259
//* Bronze 1

#include <stdio.h>
#include <string.h>

bool isPalindrome(char *s)
{
    int len = strlen(s);

    for (int i = 0; i < len / 2; ++i)
        if (s[i] != s[len - i - 1])
            return false;
    return true;
}

int main()
{
    bool result = false;
    char input[100001] = {
        0,
    };

    scanf("%s", &input);
    while (strcmp(input, "0"))
    {
        printf("%s\n", isPalindrome(input) ? "yes" : "no");
        scanf("%s", input);
    }

    return 0;
}