//* https://www.acmicpc.net/problem/18917

#include <iostream>
using namespace std;

int main()
{
    int N, v, count = 0;

    // 정수 개수 입력
    cin >> N;

    int arr[N]; // 배열 선언

    // 배열 입력 받기
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // 찾을 숫자 v 입력
    cin >> v;

    // v의 개수 세기
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == v)
        {
            count++;
        }
    }

    // 결과 출력
    cout << count << endl;

    return 0;
}
