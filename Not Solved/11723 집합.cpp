//* https://www.acmicpc.net/problem/11723
//* Silver 5

#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int set[21] = {
        false,
    };

    int m;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        char commend[10];
        int value = 0;

        cin >> commend;

        if (strcmp(commend, "add") == 0)
        {
            cin >> value;
            set[value] = 1;
        }
        else if (strcmp(commend, "remove") == 0)
        {
            cin >> value;
            set[value] = 0;
        }
        else if (strcmp(commend, "check") == 0)
        {
            cin >> value;
            cout << set[value] << endl;
        }
        else if (strcmp(commend, "toggle") == 0)
        {
            cin >> value;
            set[value] = abs(set[value] - 1);
        }
        else if (strcmp(commend, "all") == 0)
            for (int i = 1; i < 21; i++)
                set[i] = 1;
        else if (strcmp(commend, "empty") == 0)
            for (int i = 1; i < 21; i++)
                set[i] = 0;
    }

    return 0;
}