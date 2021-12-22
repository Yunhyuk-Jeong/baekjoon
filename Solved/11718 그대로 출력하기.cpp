//* https://www.acmicpc.net/problem/11718
//* Bronze 3

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    while (true)
    {
        getline(cin, str);
        if (str == "")
            break;
        cout << str << endl;
    }
    return 0;
}