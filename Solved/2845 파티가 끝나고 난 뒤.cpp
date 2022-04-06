//* https://www.acmicpc.net/problem/2845
//* Bronze 5

#include <iostream>

using namespace std;

int main()
{
    int n, m;
    int news[5], result[5];

    cin >> n >> m;

    for (int i = 0; i < 5; i++)
    {
        cin >> news[i];
        result[i] = news[i] - (n * m);
    }

    for (int i = 0; i < 5; i++)
        cout << result[i] << endl;

    return 0;
}