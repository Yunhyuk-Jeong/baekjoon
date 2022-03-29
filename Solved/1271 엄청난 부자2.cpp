//* https://www.acmicpc.net/problem/1271
//* Bronze 5
//* But if you solve it with C++, you'll probably go over the Gold.

#include <cstring>
#include <iostream>

using namespace std;

char *max(char *n, char *m)
{
    for (int i = 0; i < strlen(n); i++)
    {
        //* m이 더 클 경우, m 리턴
        //* 반대의 경우, n 리턴
        if (n[i] < m[i])
            return m;
        else if (n[i] > m[i])
            return n;
    }
    //* 둘이 같은 경우, n을 리턴
    return n;
}

//* 문자열 내의 수를 빼는 경우 사용
void subtract(char *n, char *m)
{
    //* ASCII의 값을 통하여 n에서 m를 뺌
    //* ASCII가 '0'보다 작은 경우, 10을 더한 뒤,
    //* 앞자리에서 1을 뺌
    for (int i = 0; i < strlen(m); i++)
    {
        n[i] = n[i] - m[i] + '0';
        if (n[i] < '0')
        {
            n[i] += 10;
            n[i - 1]--;
        }
    }
    //* 같은 동작을 역으로 수행
    for (int i = strlen(m) - 1; i >= 0; i--)
    {
        if (n[i] < '0')
        {
            n[i] += 10;
            n[i - 1]--;
        }
    }
}

//* 나눗셈을 뺄셈의 단순화이므로, 양의 정수로써 더 이상 뺄 수 없을 때까지 빼면
//* 몫과 나머지를 산출할 수 있음
void devideSubtract(char *n, char *m, char *result, int index)
{
    //* 결과값의 index 위치에 0을 삽입
    result[index] = '0';

    //* n[index - 1]이 0보다 크거나, n의 index번째부터 m을 비교했을 때, n의 index번째부터가 더 클 경우
    //* n의 index번째에서 m을 빼고, result[index]를 1 더함
    while (n[index - 1] > '0' || max(n + index, m) == n + index)
    {
        subtract(n + index, m);
        ++result[index];
    }
}

void devide(char *n, char *m, char *result)
{
    int index = 0;
    //* 아무리 커도, 자릿수는 n의 길이 - m의 길이로 표기 가능
    int digit = strlen(n) - strlen(m);

    //* index가 digit보다 작거나 같은 경우,
    //* devideSubtract 실행 / index++ 이므로, index가 들어간 상태로 작동함
    while (index <= digit)
        devideSubtract(n, m, result, index++);

    result[index] = '\0';
}

int main()
{
    //* 입력값을 저장할 n, m과 출력값을 저장할 result
    char n[1001], m[1001], result[1001];
    //* *Remover는 맨 앞자리에 0이 오는 경우를 방지함
    int resultRemover = 0, nRemover = 0;

    //* n, m 입력 실행
    cin >> n >> m;

    //* n, m, result devide 실행
    devide(n, m, result);

    //* result와 n의 맨 앞에 0이 없을때까지 *Remover를 증가시킴
    while (result[resultRemover] == '0')
        resultRemover++;
    while (n[nRemover] == '0')
        nRemover++;

    //* devide가 불가능한 경우, devide의 마기막의 result[index] = '\0'만 남게 됨
    //* 이 경우, 몫을 0으로 초기화함
    if (result[0] == '\0')
    {
        result[0] = '0';
        result[1] = '\0';
    }

    //* result에 0만 담겨있다면 resultRemover는 1이므로, 출력시 공백 발생
    //* 이를 위하여 resultRemover-- 실행
    if (result[resultRemover] == '\0')
        resultRemover--;

    //* n에 0만 담겨있다면 nRemover는 n[nRemover] == '\0'에 멈추게 된다.
    //* 이때 nRemover-- 실행
    if (n[nRemover] == '\0')
        nRemover--;

    //* 각각 * + *Remover부터 끝까지 출력
    //! 포인터 주소임에 유의
    cout << result + resultRemover << endl;
    cout << n + nRemover << endl;

    return 0;
}