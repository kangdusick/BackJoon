#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> nums(N);
	int iter1 = 0;
	int iter2 = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	int sum = 0;
	int sol = 0;
	sum += nums[0];
	while (true)
	{
		if (sum == M)
		{
			sol++;
		}
		if (sum >= M)
		{
			sum -= nums[iter1];
			iter1++;
		}
		else if (iter2 == N-1)
		{
			break;
		}
		else
		{
			iter2++;
			sum += nums[iter2];
		}
	}
	cout << sol;
	return 0;
}