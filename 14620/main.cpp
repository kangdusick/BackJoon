#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class XY
{
public:
	int x;
	int y;

};

map<int, vector<XY>> nums;
map<int, vector<XY>>::iterator iter;
vector<XY>::iterator veciter;
bool CheckXY2(XY xy1, XY xy2)
{
	int x1 = xy1.x;
	int x2 = xy2.x;
	int y1 = xy1.y;
	int y2 = xy2.y;
	if (x1 == x2)
	{
		if (abs(y1 - y2) < 3)
		{
			return false;
		}
	}
	if (y1 == y2)
	{
		if (abs(x1 - x2) < 3)
		{
			return false;
		}
	}
	if (abs(x1 - x2) == 1 && abs(y1 - y2) == 1)
	{
		return false;
	}
	return true;
}
bool CheckXY(XY xy1,XY xy2,XY xy3)
{
	if (CheckXY2(xy1, xy2)==false)
	{
		return false;
	}
	if (CheckXY2(xy1, xy3)==false)
	{
		return false;
	}
	if (CheckXY2(xy2, xy3)==false)
	{
		return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, G;
	cin >> N;
	int NN = N * N;
	int** cost = new int* [N];
	int** sumCost = new int* [N];
	for (int i = 0; i < N; i++)
	{
		cost[i] = new int[N];
		sumCost[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i - 1 >= 0 && i + 1 < N && j - 1 >= 0 && j + 1 < N)
			{
				sumCost[i][j] = cost[i][j] + cost[i - 1][j] + cost[i + 1][j] + cost[i][j + 1] + cost[i][j - 1];
				XY newxy;
				newxy.x = i;
				newxy.y = j;
				nums[sumCost[i][j]].push_back(newxy);
			}
			else
			{
				sumCost[i][j] = 2100000000;
			}
		}
	}
	vector<XY> sequence;
	iter = nums.begin();
	while (iter!=nums.end())
	{
		int iterSize = iter->second.size();
		for (int i = 0; i < iterSize; i++)
		{
			sequence.push_back(iter->second[i]);
		}
		iter++;
	}
	int seqSize = sequence.size();
	vector<int> sols;
	for (int i = 0; i < seqSize-2; i++)
	{
		for (int j = i + 1; j < seqSize-1; j++)
		{
			for (int k = j + 1; k < seqSize; k++)
			{
				if (CheckXY(sequence[i], sequence[j], sequence[k])==true)
				{
					sols.push_back(sumCost[sequence[i].x][sequence[i].y] + sumCost[sequence[j].x][sequence[j].y] + sumCost[sequence[k].x][sequence[k].y]);
				}

			}
		}
	}
	sort(sols.begin(), sols.end());
	cout << sols[0];

	return 0;
}