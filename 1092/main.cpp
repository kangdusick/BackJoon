#include <iostream>
#include <algorithm>
#include <queue>
#include <list>
#include<map>
using namespace std;
map<int,int> crainWeight; //key: 무게 val: 크레인 갯수
map<int, int>::iterator iter;
map<int,int> BoxGroups; //val: key 이하의 무게를 가지는 박스의 수.
int FindBoxGroups(map<int, int>::iterator tempiter)
{
	int w =0;
	while (true)
	{
		w = tempiter->first;
		if (BoxGroups[w] >= 1)
		{
			return w;
		}
		else
		{
			if (tempiter == crainWeight.begin())
			{
				return 0;
			}
			tempiter--;
		}
	}
	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M,BoxCount;
	int solution = 0;
	cin >> N;
	int weight = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> weight;
		crainWeight[weight]++;
	}
	cin >> M;
	BoxCount = M;
	iter = crainWeight.end();
	iter--;
	int maxWeight = iter->first;
	for (int i = 0; i < M; i++)
	{
		cin >> weight;
		if (weight > maxWeight)
		{
			cout << -1;
			return 0;
		}

		iter = crainWeight.begin();
		for (int j = 0; j < N; j++)
		{
			if (weight <= iter->first)
			{
				BoxGroups[iter->first]++;
				break;
			}
			iter++;
		}
	}
	int CrainGroupCount = crainWeight.size();
	while (true)
	{
		iter = crainWeight.end();
		iter--;
		for (int i = 0; i < CrainGroupCount; i++)
		{
			for (int j = 0; j < iter->second; j++)
			{
				int temp = FindBoxGroups(iter);
				if (temp == 0)
				{
					continue;
				}
				else
				{
					BoxGroups[FindBoxGroups(iter)]--;
					BoxCount--;
					if (BoxCount == 0)
					{
						solution++;
						cout << solution;
						return 0;
					}
				}
				
			}
			iter--;
		}
		solution++;
	}

	return 0;
}