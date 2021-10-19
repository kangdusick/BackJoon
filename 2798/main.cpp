#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, solution = 0;
	int select[3];
	cin >> N >> M;
	int* nums = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	sort(nums, nums + N);
	for (int i = 0; i < N; i++)
	{
		select[0] = nums[i];
		int j;
		int leftOver = M - select[0];
		int* nums1 = new int[N - 1];
		for (j = 0; j < i; j++)
		{
			nums1[j] = nums[j];
		}
		for (j = i; j < N - 1; j++)
		{
			nums1[j] = nums[j + 1];
		}
		for (int jj = 0; jj < N - 1; jj++)
		{
			select[1] = nums1[jj];
			int* nums2 = new int[N - 2];
			for (j = 0; j < jj; j++)
			{
				nums2[j] = nums1[j];
			}
			for (j = jj; j < N - 2; j++)
			{
				nums2[j] = nums1[j + 1];
			}
			int inLeft = 0;
			int inRight = N - 2;
			int inMid;
			while (inRight >= inLeft)
			{
				inMid = (inLeft + inRight) / 2;
				select[2] = nums2[inMid];
				int sum = select[0] + select[1] + select[2];
				if (sum == M)
				{
					solution = M;
					break;
				}
				else if (sum > M)
				{
					inRight = inMid - 1;
				}
				else
				{
					if (solution < sum)
					{
						solution = sum;
					}
					inLeft = inMid + 1;
				}
			}
		}
		if (solution == M)
			break;
	}
	cout << solution;
	return 0;
}