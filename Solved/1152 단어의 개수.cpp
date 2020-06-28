//* https://www.acmicpc.net/problem/1152
//* Bronze 2

#include <stdio.h>

int main()
{
    char inputStr[1000020];
    int cnt = 0;
    bool brk = true;
    scanf("%[^\n]s", inputStr);
    if (!(inputStr[0] == ' ' && inputStr[1] == '\0'))
    {
        cnt++;
        inputStr[0] == ' ' ? inputStr[0] = 'a' : 0;
        for (int i = 0; brk; i++)
            (inputStr[i] == ' ' && inputStr[i + 1] != '\0') ? (cnt++) : ((inputStr[i + 1] == '\0') ? (brk = false) : (0));
    }
    printf("%d", cnt);
    return 0;
}