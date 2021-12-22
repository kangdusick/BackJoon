#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, N, C, sol;
	bool isEnd = false;
	int endCount = 0;
	cin >> T;
	vector<int> candys;
	vector<int> sols;
	for (int i = 0; i < T; i++)
	{
		isEnd = false;
		sol = 0;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			cin >> C;
			if (C % 2 == 1)
			{
				C++;
			}
			candys.push_back(C);
		}
		if (N == 1)
		{
			sols.push_back(sol);
			candys.clear();
			continue;
		}
		endCount = 0;
		for (int j = 0; j < N - 1; j++)
		{
			if (candys[j] == candys[j + 1])
			{
				endCount++;
			}
			else
			{
				break;
			}
		}
		if (endCount == N - 1)
		{
			isEnd = true;
			sols.push_back(sol);
			candys.clear();
		}
		while (isEnd == false)
		{
			vector<int> temp = candys;
			candys[0] = temp[0]/2 +temp[N - 1] / 2;
			if (candys[0] % 2 == 1)
			{
				candys[0]++;
			}
			for (int j = 0; j < N - 1; j++)
			{
				candys[j + 1] = temp[j+1]/2+ temp[j] / 2;
				if (candys[j + 1] % 2 == 1)
				{
					candys[j + 1]++;
				}
			}
			sol++;
			endCount = 0;
			for (int j = 0; j < N - 1; j++)
			{
				if (candys[j] == candys[j + 1])
				{
					endCount++;
				}
				else
				{
					break;
				}
			}
			if (endCount == N-1)
			{
				isEnd = true;
				sols.push_back(sol);
				candys.clear();
			}
		}
	}
	for (int i = 0; i < T; i++)
	{
		cout << sols[i] << "\n";
	}

	return 0;
}