//* https://www.acmicpc.net/problem/8437
//* Bronze 5

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 큰 수 덧셈 함수
string addBigNumbers(string a, string b) {
    string result = "";
    int carry = 0;
    
    // 문자열 길이를 맞춰줌
    while (a.length() < b.length()) a = "0" + a;
    while (b.length() < a.length()) b = "0" + b;
    
    // 뒤에서부터 자리별 덧셈 수행
    for (int i = a.length() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    
    if (carry) result += carry + '0';
    
    reverse(result.begin(), result.end());
    return result;
}

// 큰 수 뺄셈 함수 (a >= b 가정)
string subtractBigNumbers(string a, string b) {
    string result = "";
    int borrow = 0;
    
    // 문자열 길이를 맞춰줌
    while (b.length() < a.length()) b = "0" + b;
    
    // 뒤에서부터 자리별 뺄셈 수행
    for (int i = a.length() - 1; i >= 0; i--) {
        int diff = (a[i] - '0') - (b[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += diff + '0';
    }
    
    // 앞에 남은 불필요한 0 제거
    while (result.length() > 1 && result.back() == '0') result.pop_back();
    
    reverse(result.begin(), result.end());
    return result;
}

// 큰 수를 2로 나누는 함수
string divideByTwo(string num) {
    string result = "";
    int carry = 0;
    
    for (char digit : num) {
        int current = carry * 10 + (digit - '0');
        result += (current / 2) + '0';
        carry = current % 2;
    }
    
    // 앞에 남은 불필요한 0 제거
    while (result.length() > 1 && result[0] == '0') result.erase(result.begin());
    
    return result;
}

int main() {
    string S, D;
    
    // 입력 받기
    cin >> S >> D;
    
    // (S + D) / 2 계산
    string K = divideByTwo(addBigNumbers(S, D));
    
    // (S - D) / 2 계산
    string N = divideByTwo(subtractBigNumbers(S, D));

    // 결과 출력
    cout << K << endl;
    cout << N << endl;

    return 0;
}
