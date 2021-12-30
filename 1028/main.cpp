#include <iostream>
#include <vector>
using namespace std;
int R, C;
vector<vector<int>> orc;
int maxs = 0;
int Limit;
void CheckSize(int n, int x, int y)
{
	int xTemp = x;
	int yTemp = y;
	int N = n - 1;
	bool isTrue = true;
	if ((xTemp >= C || xTemp < 0) || (yTemp >= R || yTemp < 0) || orc[yTemp][xTemp] == 0) //상꼭지점
		isTrue = false;
	if (isTrue)
		for (int i = 0; i < N; i++) //상꼭지점에서 우측하단
		{
			xTemp++;
			yTemp++;
			if ((xTemp >= C || xTemp < 0) || (yTemp >= R || yTemp < 0) || orc[yTemp][xTemp] == 0)
				isTrue = false;
		}
	if(isTrue)
	for (int i = 0; i < N; i++) //우꼭지점에서 좌하단
	{
		xTemp--;
		yTemp++;
		if ((xTemp >= C || xTemp < 0) || (yTemp >= R || yTemp < 0) || orc[yTemp][xTemp] == 0)
			isTrue = false;
	}
	if (isTrue)
	for (int i = 0; i < N; i++) //하꼭지점에서 좌상단
	{
		xTemp--;
		yTemp--;
		if ((xTemp >= C || xTemp < 0) || (yTemp >= R || yTemp < 0) || orc[yTemp][xTemp] == 0)
			isTrue = false;
	}
	if (isTrue)
	for (int i = 0; i < N; i++) //좌꼭지점에서 우상단
	{
		xTemp++;
		yTemp--;
		if ((xTemp >= C || xTemp < 0) || (yTemp >= R || yTemp < 0) || orc[yTemp][xTemp] == 0)
			isTrue = false;
	}
	if (isTrue&&maxs < n)
	{
		maxs = n;
	}
	if (n < Limit)
	CheckSize(n + 1, x, y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C;
	string nums = "";
	Limit = R > C ? C : R;
	if (Limit % 2 == 0)
	{
		Limit--;
	}
	Limit = Limit / 2 + 1;
	for (int i = 0; i < R; i++)
	{
		vector<int> temp(C);
		cin >> nums;
		for (int j = 0; j < C; j++)
		{
			temp[j] = nums[j] - 48;
		}
		orc.push_back(temp);
		nums.clear();
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (maxs == Limit)
			{
				cout << maxs << "\n";
				return 0;

			}
			CheckSize(maxs + 1, j, i);
		}
	}
	cout << maxs<<"\n";
	return 0;
}