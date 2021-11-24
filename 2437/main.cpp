#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
long long int* nums;
int sol=0;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	nums = new long long int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	sort(nums, nums + N);
	for (int i = 0; i < N; i++)
	{
		if (nums[i]-sol > 1)
		{
			break;
		}
		sol = sol + nums[i];
	}
	sol++;
	cout << sol;
	return 0;
}