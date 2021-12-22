#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
map<int, int> gragh[500];
map<int, int> pointed[500];
map<int, int>::iterator iter;
list<vector<int>> pathList;
list<vector<int>>::iterator pathiter;
bool isVisited[500];
int daicstra[500];
int N, M, S, D;
vector<int> solutions;
void PathFind(int num, vector<int> path)
{
	map<int, int>::iterator iter2 = pointed[num].begin();
	int iterCount = pointed[num].size();
	for (int i = 0; i < iterCount; i++)
	{
		if (daicstra[iter2->first] == daicstra[num] - iter2->second)
		{
			vector<int> curpath = path;
			curpath.push_back(iter2->first);
			if (iter2->first == S)
			{
				pathList.push_back(curpath);
			}
			else
			{
				PathFind(iter2->first, curpath);
			}
		}
		iter2++;
	}
}
void SetDaicstra(int num)
{
	iter = gragh[num].begin();
	isVisited[num] = true;
	int iCount = gragh[num].size();
	int min = 2100000000;
	int nextnum = -1;
	for (int i = 0; i < iCount; i++)
	{
		if (daicstra[num] + iter->second < daicstra[iter->first])
		{
			daicstra[iter->first] = iter->second+ daicstra[num];
		}
		iter++;
	}
	for (int i = 0; i < N; i++)
	{
		if (isVisited[i] == false && daicstra[i] < min)
		{
			min = daicstra[i];
			nextnum = i;
		}
	}
	if (nextnum != -1)
	{
		SetDaicstra(nextnum);
	}

}
void init2()
{
	for (int i = 0; i < 500; i++)
	{
		isVisited[i] = false;
		daicstra[i] = 2100000000;
	}
}
void init()
{
	for (int i = 0; i < 500; i++)
	{
		gragh[i].clear();
		pointed[i].clear();
		isVisited[i] = false;
		daicstra[i] = 2100000000;
	}
	int pathSize = pathList.size();
	pathiter = pathList.begin();
	for (int i = 0; i < pathSize; i++)
	{
		pathiter->clear();
		pathiter++;
	}
	pathList.clear();
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
		init();
		for (int i = 0; i < M; i++)
		{
			cin >> U >> V >> P;
			gragh[U][V] = P; //U에서 V로 가는 길이 있는데, 길이가 P다.
			pointed[V][U] = P; //V로 오는 길이가 P인 길 U가 있다.
		}
		daicstra[S] = 0;
		SetDaicstra(S);
		if (daicstra[D] == 2100000000)
		{
			solutions.push_back(-1);
			continue;
		}
		vector<int> temp;
		temp.push_back(D);
		PathFind(D,temp);
		int isize = pathList.size();
		pathiter = pathList.begin();
		for (int i = 0; i < isize; i++)
		{
			int iisize = (*pathiter).size();
			for (int ii = iisize - 1; ii > 0; ii--)
			{
				iter = gragh[(*pathiter)[ii]].find((*pathiter)[ii-1]);
				if (iter == gragh[(*pathiter)[ii]].end())
				{
					continue;
				}
				gragh[(*pathiter)[ii]].erase(iter);
			}
			pathiter++;
		}
		init2();
		daicstra[S] = 0;
		SetDaicstra(S);
		if (daicstra[D] == 2100000000)
		{
			solutions.push_back(-1);
		}
		else
		{
			solutions.push_back(daicstra[D]);
		}
	}
	int solSize = solutions.size();
	for (int i = 0; i < solSize; i++)
	{
		cout << solutions[i] << endl;
	}

	return 0;
}
