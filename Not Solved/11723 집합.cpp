//* https://www.acmicpc.net/problem/11723
//* Silver 5

#include <stdio.h>

int main()
{

    int n, m, x;
    char s[11];

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%s", s);

        if (s[0] == 'a' && s[1] == 'd')
        {
            scanf("%d", &x);
            n |= (1 << x);
        }
        else if (s[0] == 'r')
        {
            scanf("%d", &x);
            n &= ~(1 << x);
        }
        else if (s[0] == 'c')
        {
            scanf("%d", &x);
            printf("%d\n", (n & (1 << x)) == 0 ? 0 : 1);
        }
        else if (s[0] == 't')
            n ^= (1 << x);
        else if (s[0] == 'a' && s[1] == 'l')
            n = (1 << 21) - 1;
        else
            n = 0;
    }

    return 0;
}
