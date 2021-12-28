#include <iostream>
#include <vector>
using namespace std;
int N, S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	vector<int> nums(N);
	int sum = 0;
	int minLen = 2100000000;
	int iter1, iter2;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		sum += nums[i];
	}
	if (sum < S)
	{
		cout << 0<<"\n";
		return 0;
	}
	sum = nums[0];
	iter1 = 0;
	iter2 = 0;

	while (true)
	{
		if (sum >= S)
		{
			int len = iter2 - iter1 + 1;
			if (len < minLen)
			{
				minLen = len;
				if (minLen == 1)
				{
					break;
				}
			}
			sum -= nums[iter1];
			iter1++;
		}
		else if (iter2 == N - 1)
		{
			break;
		}
		else
		{
			iter2++;
			sum += nums[iter2];
		}
	}
	cout << minLen<<"\n";
	return 0;
}
