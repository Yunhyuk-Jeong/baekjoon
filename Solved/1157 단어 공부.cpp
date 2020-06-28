//* https://www.acmicpc.net/problem/1157
//* Bronze 1

#include <stdio.h>
#include <string.h>

int main()
{
    const int UPPER_A = 65,
              UPPER_Z = 90,
              LOWER_A = 97,
              LOWER_Z = 122,
              ALPHA_GAP = 32,
              ALPHA_NUM = 26;

    int mostUse = 0;
    int alphaCount[26] = {
        0,
    };
    char inputStr[1000020]; //* 65 ~  90 : A ~ Z
    scanf("%s", inputStr);  //* 97 ~ 122 : a ~ z

    int inputStrLen = strlen(inputStr);

    for (int i = 0; i < inputStrLen; i++)
        ((inputStr[i] >= UPPER_A) && (inputStr[i] <= UPPER_Z))
            ? (alphaCount[inputStr[i] - UPPER_A]++)
            : ((inputStr[i] >= LOWER_A) && (inputStr[i] <= LOWER_Z))
                  ? (alphaCount[inputStr[i] - LOWER_A]++)
                  : 0;

    for (int i = 0; i < ALPHA_NUM; i++)
        alphaCount[mostUse] < alphaCount[i] ? mostUse = i : 0;

    for (int i = 0; i < ALPHA_NUM; i++)
        (alphaCount[i] == alphaCount[mostUse]) ? ((i == mostUse) ? (0) : (mostUse = -1)) : (0);

    mostUse == -1 ? printf("?") : printf("%c", UPPER_A + mostUse);

    return 0;
}