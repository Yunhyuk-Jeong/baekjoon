//* https://www.acmicpc.net/problem/1654
//* Silver 3

#include <stdio.h>

int main()
{
	int k, n, answer = 0;
	int line[10001];
	int max = 0;
	long long mid, high, low = 1;

	scanf("%d %d", &k, &n);

	for(int i = 0; i < k; i++)
	{
		scanf("%d", &line[i]);
		if(max < line[i]) max = line[i];
	}

	high = max;

	while (low <= high)
	{
		mid = (low + high) / 2;
		int cnt = 0;
		for(int i = 0; i < k; i++)
			cnt += line[i] / mid;

		if(cnt >= n) {
			low = mid + 1;
			if(answer < mid) answer = mid;
		}
		else
			high = mid - 1;
	}
	
	printf("%d", answer);
}