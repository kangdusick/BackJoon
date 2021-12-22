#include <iostream>
#include <vector>
#include <queue>
#define infn 2100000
#define limitIndex 20001
using namespace std;
int V, E,K;
vector<pair<int,int>> gragh[limitIndex]; //index: u에서 second:v로 가는 second 가중치 w
int daicstra[limitIndex];
priority_queue<pair<int, int>> pq; //first: 거리 second: 인덱스
void init()
{
	for (int i = 0; i < limitIndex; i++)
	{
		daicstra[i] = infn;
	}
}
void SetDaicstra(int num)
{
	pq.pop();
	int size = gragh[num].size();
	int min = infn;
	int minIndex;
	for (int i = 0; i < size; i++)
	{
		int sum = daicstra[num] + gragh[num][i].second;
		if (sum < daicstra[gragh[num][i].first])
		{
			daicstra[gragh[num][i].first] = sum;
			pq.push(make_pair(-sum, gragh[num][i].first));
		}
	}
	if (pq.empty())
	{
		return;
	}
	else
	{
		SetDaicstra(pq.top().second);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);
	int u, v, w;
	int uv;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		gragh[u].push_back(make_pair(v,w));
	}
	init();
	daicstra[K] = 0;
	pq.push(make_pair(0, K));
	SetDaicstra(K);
	for (int i = 1; i <= V; i++)
	{
		if (daicstra[i] == infn)
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


3 4
1
2 1 1
2 3 2
2 1 3
2 3 4

*/