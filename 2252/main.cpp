#include <iostream>
#include <vector>
#include <queue>
#define maxIndex 32001
using namespace std;
vector<int> gragh[maxIndex];
int degree[maxIndex];
priority_queue<int> pq;
int N, M;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int A;
	int B;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		gragh[A].push_back(B);
		degree[B]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (degree[i] == 0)
		{
			pq.push(-i);
		}
	}

	while (pq.size() != 0)
	{
		int top = -pq.top();
		pq.pop();
		cout << top << " ";
		int size = gragh[top].size();
		for (int i = 0; i < size; i++)
		{
			if (--degree[gragh[top][i]] == 0)
			{
				pq.push(-gragh[top][i]);
			}
		}
	}
	return 0;
}
/*
3 1
1 3
*/
