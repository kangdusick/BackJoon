#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int* x;
	int* C;
	int N, cc;
	cin >> N >>cc;
	x = new int[N];
	C = new int[cc];
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> x[i];
	}
	sort(x, x + N);

	int start = 1;
	int end = x[N - 1] - x[0];
	int result = 0;
	int mid;
	while (start<=end)
	{
		mid = (start + end) / 2;
		int value = x[0];
		int count = 1;
		for (i = 1; i < N; i++)
		{
			if (x[i] >= value + mid)
			{
				value = x[i];
				count++;
			}
		}
		if (count >= cc)
		{
			start = mid + 1;
			result = mid;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << result;
	return 0;
}

/*
5 3
1
2
8
4
9
답: 3

5 2
1
2
8
4
9
정답:8

3 3
1
4
6
답: 2

5 3
1
7
8
9
10
답: 3

*/