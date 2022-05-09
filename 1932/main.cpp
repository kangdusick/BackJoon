#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> nums[501];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int input;
	int downIndex;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> input;
			nums[i].push_back(input);
		}
	}
	for (int i = n-1; i >= 1; i--)
	{
		downIndex = i + 1;
		for (int j = 0; j < i; j++)
		{
			if (nums[downIndex][j] > nums[downIndex][j + 1])
			{
				nums[i][j] += nums[downIndex][j];
			}
			else
			{
				nums[i][j] += nums[downIndex][j+1];
			}
		}
	}
	cout << nums[1][0];
	return 0;
}