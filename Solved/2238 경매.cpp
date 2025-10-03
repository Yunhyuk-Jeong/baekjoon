//* https://www.acmicpc.net/problem/2238
//* Silver 5

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>


using namespace std;

int main()
{
    int U, N;
    cin >> U >> N;

    vector<pair<string, int>> bids(N);   // 이름, 가격 순서대로 저장
    unordered_map<int, int> price_count; // 가격별 제시 횟수

    for (int i = 0; i < N; i++)
    {
        string name;
        int price;
        cin >> name >> price;

        bids[i] = {name, price};
        price_count[price]++;
    }

    // 1. 최소 등장 횟수 구하기
    int min_count = N + 1;
    for (auto &p : price_count)
    {
        if (p.second < min_count)
        {
            min_count = p.second;
        }
    }

    // 2. 가장 낮은 가격 중 가장 먼저 나온 사람 찾기
    int winning_price = U + 1;
    for (auto &p : price_count)
    {
        if (p.second == min_count && p.first < winning_price)
        {
            winning_price = p.first;
        }
    }

    // 3. 해당 가격을 가장 먼저 제시한 사람 찾기
    for (auto &bid : bids)
    {
        if (bid.second == winning_price)
        {
            cout << bid.first << " " << bid.second << endl;
            break;
        }
    }

    return 0;
}
