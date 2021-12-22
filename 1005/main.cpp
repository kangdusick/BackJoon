#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
int degree[1001];
int times[1001];
vector<int> gragh[1001];
priority_queue<int, vector<int>, greater<int>> pq;
vector<int> target[1001];
int completeTimes[1001];

void init()
{
	
	for (int i = 0; i < 1001; i++)
	{
		degree[i] = 0;
		completeTimes[i] = 0;
		times[i] = 0;
		gragh[i].clear();
		target[i].clear();
	}
	int size = pq.size();
	for (int i = 0; i < size; i++)
	{
		pq.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int testCase, N, W, K,i;
	int* solutions;
	cin >> testCase;
	solutions = new int[testCase];
	for (i = 0; i < testCase; i++)
	{
		solutions[i] = 0;
	}
	for (int j = 0; j < testCase; j++)
	{
		init();
		cin >> N>>K;
		int A, B;
		for (i = 1; i <= N; i++)
		{
			cin >> times[i];
			completeTimes[i] = times[i];
		}
		for (i = 0; i < K; i++)
		{
			cin >> A >> B;
			degree[B]++;
			gragh[A].push_back(B);
			target[B].push_back(A);
		}
		cin >> W;
		for (i = 1; i <= N; i++)
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
			if (top == W)
			{
				solutions[j] = completeTimes[top];
				break;
			}
			int size = gragh[top].size();
			for (i = 0; i < size; i++)
			{
				if (--degree[gragh[top][i]] == 0)
				{
					int maxTime = 0;
					int maxSize = target[gragh[top][i]].size();
					for (int ii = 0;ii<maxSize;ii++ )
					{
						if (completeTimes[target[gragh[top][i]][ii]] >= maxTime)
							maxTime = completeTimes[target[gragh[top][i]][ii]];
					}
					completeTimes[gragh[top][i]] += maxTime;
					pq.push(gragh[top][i]);
				}
					
			}
		}
	}
	for (i = 0; i < testCase; i++)
	{
		cout << solutions[i]<<"\n";
	}
	return 0;
}
/*
1
10 11
10 20 30 40 50 60 70 80 90 100
1 2
2 3
3 6
6 9
5 4
4 7
7 8
8 9
4 9
10 7
4 3
9
답: 

1
5 4
10 10 10 100 10
1 2
2 3
4 5
4 3
3
답: 110

1
5 4
10 10 10 100 10
1 2
2 3
4 3
4 5
3
답: 110

1
3 2
3 3 3
2 1
3 2
1
답: 9

1
10 11
10 20 30 40 50 60 70 80 90 100
1 2
2 3
3 6
6 9
5 4
4 7
7 8
8 9
4 9
10 7
4 3
9
답: 340
*/