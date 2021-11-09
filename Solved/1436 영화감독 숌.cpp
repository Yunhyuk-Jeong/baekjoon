//* https://www.acmicpc.net/problem/1436
//* Silver 5

#include <stdio.h>
#include <string>

int main(int argc, char *argv[])
{
    int n;
    int count = 0;
    int num = 665;
    std::string s;

    scanf("%d", &n);

    while (++num)
    {
        s = std::to_string(num);

        if (s.find("666") != -1)
        {
            ++count;
        }

        if (count == n)
        {
            printf("%d", num);
            break;
        }
    }

    return 0;
}
