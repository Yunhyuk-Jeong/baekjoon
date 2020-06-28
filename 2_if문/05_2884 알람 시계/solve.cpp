#include <stdio.h>

int main()
{
    int wakeHour, wakeMin;
    bool minusMin = false;
    scanf("%d %d", &wakeHour, &wakeMin);
    wakeMin < 45 ? minusMin = true : wakeMin -= 45;
    if (minusMin)
    {
        wakeMin += 15;
        wakeHour = wakeHour == 0 ? 23 : wakeHour - 1;
    }
    printf("%d %d", wakeHour, wakeMin);
    return 0;
}