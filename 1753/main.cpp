#include <iostream>
#include <map>
using namespace std;
int V, E,K;
map<int, int>gragh[20001]; //key: u에서 key:v로 가는 value 가중치 w
map<int, int>::iterator iter;
int daicstra[20001];
bool checkDaicstra[20001];
void init()
{
	for (int i = 0; i < 20001; i++)
	{
		daicstra[i] = 2100000000;
	}
}
void SetDaicstra(int num)
{
	int size = gragh[num].size();
	int min = 2100000000;
	int minIndex;
	iter = gragh[num].begin();
	for (int i = 0; i < size; i++)
	{
		if (daicstra[num] + iter->second < daicstra[iter->first])
		{
			daicstra[iter->first] = daicstra[num] + iter->second;
		}
		iter++;
	}
	checkDaicstra[num] = true;
	//아직 안찾은 다익스트라 중에서 가장 작은값을 찾아 재귀적으로 실행하기
	for (int i = 1; i <= V; i++)
	{
		if (checkDaicstra[i] == false&&daicstra[i]<min)
		{
			min = daicstra[i];
			minIndex = i;
		}
	}
	if (min == 2100000000)
	{
		return;
	}
	else
	{
		SetDaicstra(minIndex);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int u, v, w;
	int uv;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		uv = gragh[u][v];
		if (uv == 0)
		{
			gragh[u][v] = w;
		}
		else if(uv >w)
		{
			gragh[u][v] = w;
		}
	}
	init();
	daicstra[K] = 0;
	SetDaicstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (daicstra[i] == 2100000000)
		{
			cout << "INF" << "\n";
		}
		else
		{
			cout << daicstra[i] << "\n";
		}
		
	}

	return 0;
}

/*
4 4
1
1 2 7
1 4 5
2 3 3
3 4 7
답:
0
7
10
5

4 5
1
1 3 2
3 2 4
1 4 2
4 2 1
1 3 5
답:
0
3
2
2

2 4

2

1 2 1

1 2 2

1 2 3

1 2 4

답:
INF
0

*/