#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef long long int lld;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, K, num;
	map<int, lld> files;
	map<int, lld>::iterator iter;
	map<int, lld>::iterator tempiter;
	vector<lld> sol;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> K;
		lld cost=0;
		lld sum = 0;
		
		for (int j = 0; j < K; j++)
		{
			cin >> num;
			files[j] = num;
		}
		int SumCost = 0;
		while (true)
		{
			int fileSize = files.size();
			int min = 2100000000;
			if (fileSize == 1)
			{
				break;
			}
			int cost = 0;
			tempiter = files.begin();
			for (int i = 0; i < fileSize-1; i++)
			{
				cost = 0;
				cost += tempiter->second;
				tempiter++;
				cost += tempiter->second;
				if (cost < min)
				{
					min = cost;
					iter = tempiter;
				}
			}
			tempiter = iter;
			tempiter--;
			files.erase(iter);
			files[tempiter->first] = min;
			SumCost += min;
		}
		iter = files.begin();
		sol.push_back(SumCost);
		files.clear();
	}
	for (int i = 0; i < T; i++)
	{
		cout << sol[i]<<"\n";
	}
	return 0;
}