#include<iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
int N, K;
string nums = ""; //1의자릿수: 0번, 최대자릿수: numSize-1번
string sortNums = "";
int numSize;
stack<char> stk;
int maxs = -1;
bool hasSameNo = false;
void dfs(int level)
{
	bool check = false;
	if (level == K)
	{
		int tempnums = 0;
		for (int i = 0; i < numSize; i++)
		{
			tempnums *= 10;
			tempnums += nums[i];
		}
		if (maxs < tempnums)
		{
			maxs = tempnums;
		}
		return;
	}
	for (int i = 0; i < numSize; i++)
	{
		if (nums[i] != sortNums[i])
		{
			int k = numSize - 1;
			for (k; k >= 0; k--)
			{
				if (nums[k] == sortNums[i])
				{
					int temp = nums[i];
					nums[i] = sortNums[i];//해당 인덱스에 해당하는 최대값 넣기
					nums[k] = temp;
					dfs(level + 1);
					nums[i] = temp;
					nums[k] = sortNums[i];
				}
			}
			check = true;
			break;
		}
	}
		if (check == false)
		{
			if (hasSameNo)
			{
				int tempnums = 0;
				for (int i = 0; i < numSize; i++)
				{
					tempnums *= 10;
					tempnums += nums[i];
				}
				if (maxs < tempnums)
				{
					maxs = tempnums;
				}
				return;
			}
			
			int temp = nums[numSize-1];
			int temp2 = nums[numSize - 2];
			nums[numSize-1] = temp2;
			nums[numSize-2] = temp;
			if (nums[0] == 0)
			{
				return;
			}
			dfs(level + 1);
			nums[numSize - 1] = temp;
			nums[numSize - 2] = temp2;
		}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	numSize = 0; // 최종적으로 numSize가 됨. index= numSize-1
	int nextmax;
	while (N!=0)
	{
		int temp = N % 10;
		stk.push((char)temp);
		sortNums.push_back((char) temp);
		N /= 10;
		numSize++; //제일 큰 숫자가 제일 나중에 온다.
	}
	numSize = 0;
	while (stk.size()!=0)
	{
		nums.push_back(stk.top());
		stk.pop();
		numSize++;
	}
	if (numSize == 1)
	{
		cout << -1 << "\n";
		return 0;
	}
	sort(sortNums.begin(), sortNums.end(),greater<char>());
	for (int i = 0; i < numSize-1; i++)
	{
		if (sortNums[i] == sortNums[i + 1])
		{
			hasSameNo = true;
			break;
		}
	}
	dfs(0);
	cout << maxs <<"\n";
	return 0;
}

/*
2133 2
3321
*/