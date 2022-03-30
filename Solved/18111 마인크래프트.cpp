//* https://www.acmicpc.net/problem/18111
//* Silver 2

#include <iostream>

using namespace std;

int main()
{
    int n, m, b;
    int map[500][500];
    int leastTime = 2139062143;
    int mostHeight;

    cin >> n >> m >> b;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];

    for (int h = 0; h <= 256; h++)
    {
        int build = 0;
        int remove = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int height = map[i][j] - h;

                if (height > 0)
                    remove += height;
                else if (height < 0)
                    build -= height;
            }
        }

        if (remove + b >= build)
        {
            int time = remove * 2 + build;

            if (leastTime >= time)
            {
                leastTime = time;
                mostHeight = h;
            }
        }
    }

    cout << leastTime << " " << mostHeight << endl;

    return 0;
}