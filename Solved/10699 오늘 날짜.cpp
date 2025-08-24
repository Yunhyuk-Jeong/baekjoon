//* https://www.acmicpc.net/problem/10699
//* Bronze 5

#include <chrono>
#include <iomanip>
#include <iostream>


int main()
{
    // 현재 시간을 시스템 클록으로부터 얻습니다.
    auto now = std::chrono::system_clock::now();

    // UTC 시간에 9시간을 더하여 서울 시간대로 변환합니다.
    auto seoul_time = now + std::chrono::hours(9);

    // 서울 시간을 time_t 형식으로 변환합니다.
    time_t time = std::chrono::system_clock::to_time_t(seoul_time);

    // tm 구조체를 사용하여 연, 월, 일을 얻습니다.
    tm utc_tm = *gmtime(&time);

    // 출력 형식을 설정하고 날짜를 출력합니다.
    std::cout << std::put_time(&utc_tm, "%Y-%m-%d") << std::endl;

    return 0;
}
