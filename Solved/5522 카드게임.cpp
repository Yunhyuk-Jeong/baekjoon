//* https://www.acmicpc.net/problem/5522
//* Bronze 5

#include <iostream>

using namespace std;

int main()
{
    int a, sum = 0;

    for (int i = 0; i < 5; i++)
    {
        cin >> a;
        sum += a;
    }

    cout << sum << endl;

    return 0;
}