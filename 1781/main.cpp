#include <iostream>
#include<vector>
#include <map>
#include <queue>
using namespace std;

map<int, priority_queue<int>> ramen; //top: 가장 작은 수에 -곱한값. 가장 작은값이 top이된다. 
map<int, priority_queue<int>>::iterator iter;
priority_queue<int> rameSolutions; //top:가장 작은 수에 -곱한값. 가장 작은값이 top이 된다.
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,D,C;
	long long int sol = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> D >> C;
		if (ramen[D].size() < D)
		{
			ramen[D].push(-C);
		}
		else
		{
			if (C > -ramen[D].top())
			{
				ramen[D].pop();
				ramen[D].push(-C);
			}
		}
	}
	iter = ramen.begin();
	while (iter!=ramen.end())
	{
			vector<int> datas;
			while (iter->second.size()!=0)
			{
				datas.push_back(iter->second.top());
				iter->second.pop();
			}
			int i = datas.size()-1;
			while (i>=0)
			{
				if (rameSolutions.size() < iter->first)
				{
					rameSolutions.push(datas[i]);
					i--;
				}
				else
				{
					if (rameSolutions.top() <= datas[i])
					{
						break;
					}
					if (rameSolutions.top() > datas[i])
					{
						rameSolutions.pop();
						rameSolutions.push(datas[i]);
						i--;
					}
				}
			}		
			iter++;
	}
	while (rameSolutions.size()!=0)
	{
		sol -= rameSolutions.top();
		rameSolutions.pop();
	}
	cout << sol;
	return 0;
}

/*
15
1 2
2 4
2 5
2 3
2 6
3 1
3 10
3 10
3 10
3 2
3 11
3 5
3 4
3 11
3 11
*/