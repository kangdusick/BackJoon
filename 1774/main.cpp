#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

class XY
{
public:
	long long int x = -1;
	long long int y = -1;
};

int Unions[1001]; // 인덱스: 번호, 값: 인덱스가 속한 그룹
map<int,vector<int>> unionGroups;
map<double, vector<XY>> lenghths;
map<double, vector<XY>>::iterator iter;

XY xys[1001];

void UnionFind(int n1, int n2)
{
	if (n1 == n2)
	{
		return;
	}
	int size1 = unionGroups[n1].size();
	int size2 = unionGroups[n2].size();
	if (size2 <= size1)
	{
		for (int i = 0; i < size2; i++)
		{
			unionGroups[n1].push_back(unionGroups[n2][i]);
			Unions[unionGroups[n2][i]] = n1;
		}
			unionGroups.erase(unionGroups[n2].front());
	}
	else
	{
		for (int i = 0; i < size1; i++)
		{
			unionGroups[n2].push_back(unionGroups[n1][i]);
			Unions[unionGroups[n1][i]] = n2;
		}
			unionGroups.erase(unionGroups[n1].front());
	}
}
double CalLength(XY n1, XY n2)
{
	
	return sqrt((n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed;
	cout.precision(2);
	int N, M,n1,n2;
	int unionCount = 0;
	double sol = 0;
	for (int i = 1; i < 1001; i++)
	{
		Unions[i] = i;
		unionGroups[i].push_back(i);
	}
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> xys[i].x >> xys[i].y;
	}
	for (int i = 0; i < M; i++)
	{
		cin >> n1 >> n2;
		if (Unions[n1] != Unions[n2])
		{
			unionCount++;
			if (unionCount == N - 1)
			{
				cout << sol << endl;
				return 0;
			}
		}
		UnionFind(Unions[n1], Unions[n2]);
	}
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			XY add;
			add.x = i;
			add.y = j;
			lenghths[CalLength(xys[i], xys[j])].push_back(add);
		}
	}
	iter = lenghths.begin();
	while (true)
	{
		int iterSize = iter->second.size();
		for (int i = 0; i < iterSize; i++)
		{
			XY xy1 = iter->second[i];
			if (Unions[xy1.x] != Unions[xy1.y])
			{
				UnionFind(Unions[xy1.x],Unions[xy1.y]);
				unionCount++;
				sol += iter->first;
				if (unionCount == N - 1)
				{
					cout << sol<<endl;
					return 0;
				}
			}
		}
		iter++;
	}

	return 0;
}

/*
5 3
1 1
3 1
2 3
3 2
3 3
1 2
2 3
3 1
*/