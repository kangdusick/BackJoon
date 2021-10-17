#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> datas[32001];
int degree[32001];
priority_queue<int, vector<int>, greater<int>> pq;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		datas[A].push_back(B);
		degree[B]++;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (degree[i] == 0)
		{
			pq.push(i);
		}
	}
	while (pq.size()!=0)
	{
		int top = pq.top();
		pq.pop();
		cout << top << " ";
		int size = datas[top].size();
		for (int i = 0; i < size; i++)
		{
			if (--degree[datas[top][i]] == 0)
			{
				pq.push(datas[top][i]);
			}
		}
	}
	return 0;
}

/*
위상정렬
1. 진입 차수가 0인 정점을 큐에 삽입한다.
2. 큐에서 원소를 꺼내 해당 원소와 간선을 제거한다.
3. 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입한다.
4. 큐가 빌때까지 2~3 과정을 반복한다.
*/