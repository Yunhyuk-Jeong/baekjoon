//* https://www.acmicpc.net/problem/31403
//* Bronze 4

#include <iostream>
#include <string>

using namespace std;

int main() {
    int A, B, C;
    
    cin >> A >> B >> C;

    cout << (A + B - C) << endl;

    string strResult = to_string(stoi(to_string(A) + to_string(B)) - C);
    cout << strResult << endl;

    return 0;
}
