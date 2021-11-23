#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int** cells;
int N,K;
bool isEnd = false;
class XY
{
public:
	int x;
	int y;
};
  //그룹인덱스, 그룹에 속한 XY
map<int,vector<XY>> Groups;
map<int, vector<XY>>::iterator iter;
map<int, map<int, int>> FindGroupIndex; //key: i key: j Val: groupindex
void Init()
{
	int groupIndex = 1;
	Groups.clear();
	FindGroupIndex.clear();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (cells[i][j] != 0)
			{
				XY added;
				added.x = i;
				added.y = j;
				FindGroupIndex[i][j] = groupIndex;
				Groups[groupIndex].push_back(added);
				groupIndex++;
			}

		}
	}
	
}
void Merge2Groups(int i1, int j1, int i2, int j2)
{
	if (i2 < 0 || j2 < 0 || i2 >= N || j2 >= 10)
	{
		return;
	}
	if (cells[i1][j1] == 0 || cells[i2][j2] == 0)
	{
		return;
	}
	if (cells[i1][j1] == cells[i2][j2]) //색깔이 같고 인접해있다.
	{
		int GroupSize[2];
		int GroupIndex[2];
		GroupSize[0] = Groups[FindGroupIndex[i1][j1]].size();
		GroupIndex[0] = FindGroupIndex[i1][j1];
		GroupSize[1] = Groups[FindGroupIndex[i2][j2]].size();
		GroupIndex[1] = FindGroupIndex[i2][j2];
		if (GroupIndex[0] != GroupIndex[1]) //색깔이 같고 인접해있는데 다른 그룹이면 합쳐준다.
		{
			int mergedGroupIndex = GroupSize[0] > GroupSize[1] ? 1 : 0; //숫자가 더 작은 그룹이 합병된다.
			for (int ii = 0; ii < GroupSize[mergedGroupIndex]; ii++)
			{
				XY xy = Groups[GroupIndex[mergedGroupIndex]][ii];
				FindGroupIndex[xy.x][xy.y] = GroupIndex[1-mergedGroupIndex];
				Groups[GroupIndex[1-mergedGroupIndex]].push_back(xy);
			}
			Groups.erase(GroupIndex[mergedGroupIndex]);
		}
	}
}
void UnionGroups(int i, int j)
{
	if (cells[i][j] == 0)
	{
		return;
	}
	else
	{
		Merge2Groups(i, j, i, j + 1);
		Merge2Groups(i, j, i, j - 1);
		Merge2Groups(i, j, i + 1, j);
		Merge2Groups(i, j, i - 1, j);
	}
}
void Removed()
{
	int iterSize = Groups.size();
	iter = Groups.begin();
	for (int i = 0; i < iterSize; i++)
	{
		int SecondSize = iter->second.size();
		if (SecondSize >= K)
		{
			for (int j = 0; j < SecondSize; j++)
			{
				cells[iter->second[j].x][iter->second[j].y] = 0;
			}
		}
		iter++;
	}
}
void Gravity()
{
	for (int j = 0; j < 10; j++) //왼쪽 열부터 하나의 열씩 진행한다.
	{
		stack<int> setting;
		for (int i = 0; i < N; i++)
		{
			if (cells[i][j] != 0)
			{
				setting.push(cells[i][j]);
				cells[i][j] = 0;
			}
		}
		int stackSize = setting.size();
		for (int i = 0; i < stackSize; i++)
		{
			cells[N - 1 - i][j] = setting.top();
			setting.pop();
		}
	}
}
void CheckEnd()
{
	int iterSize = Groups.size();
	iter = Groups.begin();
	isEnd = true;
	for (int i = 0; i < iterSize; i++)
	{
		int SecondSize = iter->second.size();
		if (SecondSize >= K)
		{
			isEnd = false;
			return;
		}
		iter++;
	}
}
void ShowCells()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << cells[i][j];
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N>>K;
	cells = new int* [N];
	int groupIndex = 1;
	string inputs;
	getline(cin, inputs);
	for (int i = 0; i < N; i++)
	{
		cells[i] = new int[10];
		getline(cin,inputs);
		for (int j = 0; j < 10; j++)
		{
			cells[i][j] = inputs[j]-48;
			if (inputs[j] != '0')
			{
				XY added;
				added.x = i;
				added.y = j;
				FindGroupIndex[i][j] = groupIndex;
				Groups[groupIndex].push_back(added);
				groupIndex++;
			}
			
		}
		inputs.clear();
	}
	while (isEnd ==false)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				UnionGroups(i, j);
			}
		}
		Removed();
		Gravity();
		CheckEnd();
		Init();
	}
	ShowCells();
	return 0;
}