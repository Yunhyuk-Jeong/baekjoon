#include <stdio.h>

int main()
{
    int inputA, inputB;
    scanf("%d %d", &inputA, &inputB);
    int compare = inputA - inputB;
    printf("%s", compare > 0 ? ">" : compare == 0 ? "==" : "<");
    return 0;
}