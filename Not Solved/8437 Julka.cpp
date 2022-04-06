//* https://www.acmicpc.net/problem/8437
//* Bronze 5

//! Need Bing Integer

#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    cout << n - ((n / 2) - (m / 2)) << "\n" << (n / 2) - (m / 2) << endl;

    return 0;
}
