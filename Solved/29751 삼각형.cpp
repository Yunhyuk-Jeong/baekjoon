//* https://www.acmicpc.net/problem/29751
//* Bronze 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, H;
    cin >> W >> H;

    double area = (double)W * H / 2.0;
    //* 소수점 아래 한 자리까지 출력
    cout << fixed << setprecision(1) << area << "\n";
    return 0;
}
