#include <iostream>
#include <vector>
using namespace std;
int N;
int* nums;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	nums = new int[N];
	vector<int> sols;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	sols.push_back(nums[0]);
	for (int i = 1; i < N; i++)
	{
		if (sols.back() > nums[i])
		{
			sols[lower_bound(sols.begin(), sols.end(), nums[i]) - sols.begin()] = nums[i];
		}
		else if (sols.back() < nums[i])
		{
			sols.push_back(nums[i]);
		}
	}
	cout << sols.size() << "\n";
	return 0;
}