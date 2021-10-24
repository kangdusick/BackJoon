#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> Netlist[10001];
map<int, vector<int>> sol;
map<int, vector<int>>::iterator soliter;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M,A,B;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		Netlist[B].push_back(A);
	}
	for(int i = 1; i<=N;i++)
	{
		int count = 0;
		int top = 0;
		bool check[10001] = { false, };
		queue<int> que;
		que.push(i);
		check[i] = true;
		while (que.size() != 0)
		{
			top = que.front();
			que.pop();
			int vectorSize = Netlist[top].size();
			for (int j = 0; j < vectorSize; j++)
			{
				if (check[Netlist[top][j]] == false)
				{
					que.push(Netlist[top][j]);
					check[Netlist[top][j]] = true;
					count++;
				}
			}

		}
		sol[count].push_back(i);
	}
	soliter = sol.end();
	soliter--;
	sort(soliter->second.begin(), soliter->second.end());
	int solsize = soliter->second.size();
	for (int i = 0; i < solsize; i++)
	{
		cout << soliter->second[i] << " ";
	}
	return 0;
}