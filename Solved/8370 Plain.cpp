//* https://www.acmicpc.net/problem/8370
//* Bronze 5

#include <iostream>

using namespace std;

int main()
{
    int n, m, sum = 0;

    for (int i = 0; i < 2; i++)
    {
        cin >> n >> m;
        sum += n * m;
    }

    cout << sum << endl;

    return 0;
}
