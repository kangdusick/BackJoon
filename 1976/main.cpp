#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int N;
int M;
map<int, vector<int>> Groups; // key: 유니온 그룹, val: 그룹에 속한 도시들
map<int, int> FindGroupIndex; //key: 도시 key: 도시가 속한 그룹
void Unionxy(int x, int y)
{
	int groupSize[2];
	int groupIndex[2];
	groupIndex[0] = FindGroupIndex[x];
	groupIndex[1] = FindGroupIndex[y];
	int mergedIndex;
	int superIndex;
	if (groupIndex[0] != groupIndex[1])
	{
		groupSize[0] = Groups[groupIndex[0]].size();
		groupSize[1] = Groups[groupIndex[1]].size();
		//더 작은 사이즈의 그룹이 합병된다.
		mergedIndex = groupSize[0] > groupSize[1] ? 1 : 0; //합병되는 그룹 인덱스
		superIndex = 1 - mergedIndex; //더 큰 그룹의 인덱스
		for (int i = 0; i < groupSize[mergedIndex]; i++)
		{
			Groups[groupIndex[superIndex]].push_back(Groups[groupIndex[mergedIndex]][i]);
			FindGroupIndex[Groups[groupIndex[mergedIndex]][i]] = groupIndex[superIndex];
		}
		Groups.erase(groupIndex[mergedIndex]);
	}
	else
	{
		return;
	}
}
void init()
{
	for (int i = 0; i < N; i++)
	{
		FindGroupIndex[i] = i;
		Groups[i].push_back(i);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int num;
	vector<int> sol;
	cin >> N >> M;
	init();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			if (num == 1)
			{
				Unionxy(i, j);
			}
		}
	}
	string nums;
	string tempNum = "";
	getline(cin,nums);
	getline(cin, nums);
	if (nums.size() == 0)
	{
		cout << "NO";
		return 0;
	}
	int numsSize = nums.size();
	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] == ' ')
		{
			sol.push_back(stoi(tempNum)-1);
			tempNum.clear();
		}
		else
		{
			tempNum.push_back(nums[i]);
		}
	}
	sol.push_back(stoi(tempNum) - 1);
	numsSize = sol.size();
	int solIndex = FindGroupIndex[sol[0]];
	int nowIndex;
	for (int i = 0; i < numsSize; i++)
	{
		nowIndex = FindGroupIndex[sol[i]];
		if (nowIndex != solIndex)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}