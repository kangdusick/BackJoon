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
��������
1. ���� ������ 0�� ������ ť�� �����Ѵ�.
2. ť���� ���Ҹ� ���� �ش� ���ҿ� ������ �����Ѵ�.
3. ���� ���Ŀ� ���������� 0�� �� ������ ť�� �����Ѵ�.
4. ť�� �������� 2~3 ������ �ݺ��Ѵ�.
*/