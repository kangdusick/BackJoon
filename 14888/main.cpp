#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int* nums;
int cals[4];//0:+ 1:- 2:* 3:/
vector<int> prevCals; 
int minNum = 2100000000;
int maxNum = -2100000000;
void cal14888()
{
	int res = nums[0];
	for (int i = 0; i < N - 1; i++)
	{
		switch (prevCals[i])
		{
		case 0:
			res += nums[i + 1];
			break;
		case 1:
			res -= nums[i + 1];
			break;
		case 2:
			res *= nums[i + 1];
			break;
		case 3:
			res /= nums[i + 1];
			break;
		}
	}
	if (res > maxNum)
	{
		maxNum = res;
	}
	if (res < minNum)
	{
		minNum = res;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	nums = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> cals[i];
		for (int j = 0; j < cals[i]; j++)
		{
			prevCals.push_back(i);
		}
	}
	cal14888();
	while (next_permutation(prevCals.begin(), prevCals.end()))
	{
		cal14888();
	}
	cout << maxNum << "\n";
	cout << minNum << "\n";
	return 0;
}