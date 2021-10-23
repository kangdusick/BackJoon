#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

map<int, map<int, bool>> gragh;
map<int, bool>::iterator iter;
queue<int> que;
stack<int> stc;
bool visited[1001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M, V;
	int A, B;
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		gragh[A][B] = true;
		gragh[B][A] = true;
	}
	stc.push(V);
	visited[V] = true;
	cout << V<<" ";
	while (stc.size() != 0)
	{
		int top = stc.top();
		iter = gragh[top].begin();
		int graghSize = gragh[top].size();
		bool isNone = true;
		for (int i = 0; i < graghSize; i++)
		{
			if (visited[iter->first] == false)
			{
				visited[iter->first] = true;
				stc.push(iter->first);
				cout << iter->first << " ";
				isNone = false;
				break;
			}
			iter++;
		}
		if (isNone == true)
		{
			stc.pop();
		}
	}
	for (int i = 0; i < 1001; i++)
	{
		visited[i] = false;
	}
	cout << "\n";
	que.push(V);
	visited[V] = true;
	while (que.size()!=0)
	{
		int top = que.front();
		iter = gragh[top].begin();
		int graghSize = gragh[top].size();
		que.pop();
		cout << top << " ";
		for (int i = 0; i < graghSize; i++)
		{
			if (visited[iter->first] == false)
			{
				visited[iter->first] = true;
				que.push(iter->first);
			}
			iter++;
		}
	}
	return 0;
}