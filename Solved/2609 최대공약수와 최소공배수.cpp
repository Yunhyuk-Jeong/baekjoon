//* https://www.acmicpc.net/problem/2609
//* Silver 5

#include <stdio.h>

int gcd(int n, int m)
{
    while (m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
    return n;
}

int lcm(int n, int m)
{
    return n * m / gcd(n, m);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n%d", gcd(n, m), lcm(n, m));
    return 0;
}