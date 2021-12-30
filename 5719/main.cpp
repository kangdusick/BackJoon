#include <iostream>
#include <vector>
#include <map>
#include <set>
#define maxIndex 500
#define maxNum 2100000000
using namespace std;
int N, M;
int S, D;
vector<pair<int, int>> gragh[maxIndex]; //U에서 V로 가는 도로의 길이 P
vector<pair<int, int>> pointed[maxIndex]; //[V]에 연결되어있는 도로 (U의 길이 P).
int daicstra[maxIndex];
set<pair<int, int>> forbidden;
pair<int, int> path[10001]; //level에 할당된 도로 U,V
bool checkDaic[maxIndex];
void Init2()
{
	for (int i = 0; i < maxIndex; i++)
	{
		gragh[i].clear();
		pointed[i].clear();
	}
	forbidden.clear();
}
void Init()
{
	for (int i = 0; i < maxIndex; i++)
	{
		daicstra[i] = maxNum;
		checkDaic[i] = false;
	}
	daicstra[S] = 0;
}
void SetDaicstra(int u)
{
	int vecSize = gragh[u].size();
	int min = maxNum;
	int minIndex;
	checkDaic[u] = true;
	for (int i = 0; i < vecSize; i++)
	{
		pair<int, int> check;
		check.first = u;
		check.second = gragh[u][i].first;
		if (forbidden.find(check) != forbidden.end())
		{
			continue;
		}
		int cal = daicstra[u] + gragh[u][i].second;
		if (daicstra[gragh[u][i].first] > cal)
		{
			daicstra[gragh[u][i].first] = cal;
		}
	}
	for (int i = 0; i < maxIndex; i++)
	{
		if (daicstra[i] < min && checkDaic[i] == false)
		{
			min = daicstra[i];
			minIndex = i;
		}
	}
	if (min != maxNum)
	{
		SetDaicstra(minIndex);
	}
}
void DFS(int level, int v, int totalLen)
{
	int pointedSize = pointed[v].size();
	if (totalLen == daicstra[D] && v == S)
	{
		for (int i = 0; i < level; i++)
		{
			forbidden.insert(path[i]);
		}
		return;
	}
	for (int i = 0; i < pointedSize; i++)
	{
		int tempU = pointed[v][i].first;
		int tempP = pointed[v][i].second;
		if (totalLen + tempP <= daicstra[D])
		{
			path[level] = make_pair(tempU, v);
			DFS(level + 1, tempU, totalLen + tempP);
		}

	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int U, V, P;
	while (true)
	{
		cin >> N >> M;
		if (N == 0 && M == 0)
		{
			break;
		}
		cin >> S >> D;
		for (int i = 0; i < M; i++)
		{
			cin >> U >> V >> P;
			gragh[U].push_back(make_pair(V, P));
			pointed[V].push_back(make_pair(U, P));
		}
		Init();
		SetDaicstra(S);
		DFS(0, D, 0);
		Init();
		SetDaicstra(S);
		if (daicstra[D] == maxNum)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << daicstra[D] << "\n";
		}
		Init2();
	}

	return 0;
}

/*
5 6
0 4
0 1 2
0 2 2
1 2 1
2 4 2
2 3 1
3 4 2
답:6
*/