#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

map<int, map<int, int>> islandList;
bool isSearched[10001];
queue<int> islandSearch;
bool isTrue = false;
//key: 섬 번호, value -key: 연결된 다리 value-value: 1,2번 연결한 다리들 중 최대 하중
void Init()
{
	isTrue = false;
	for (int i = 0; i < 10001; i++)
	{
		isSearched[i] = false;
	}
	int size = islandSearch.size();
	for (int i = 0; i < size; i++)
	{
		islandSearch.pop();
	}
	
}

void SearchIsland(int destiny, int weight)
{
	int start = islandSearch.front();
	islandSearch.pop();
	if (start == destiny)
	{
		isTrue = true;
		return;
	}
	if (isTrue)
	{
		return;
	}
	else
	{
		map<int, int>::iterator iter;
		iter = islandList[start].begin();
		int startSize = islandList[start].size();
		for (int i = 0; i < startSize; i++)
		{
			if (iter->second >= weight&&isSearched[iter->first]==false)
			{
				islandSearch.push(iter->first);
				isSearched[iter->first] = true;
			}
			iter++;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, weight;
	int islandA, islandB;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> islandA >> islandB >> weight;
		int beforeWeight = islandList[islandA][islandB];
		if (beforeWeight < weight)
		{
			islandList[islandA][islandB] = weight;
			islandList[islandB][islandA] = weight;
		}
	}
	cin >> islandA >> islandB;
	int max = 1000000000;
	int min = 1;
	int mid;
	int solution = 0;
	while (min <= max)
	{
		Init();
		mid = (min + max) / 2;
		

		islandSearch.push(islandA);
		isSearched[islandA] = true;
		while (true)
		{
			if (islandSearch.size() == 0 || isTrue)
			{
				break;
			}
			SearchIsland(islandB, mid);
		}
		if (isTrue)
		{
			min = mid + 1;
			solution = mid;
		}
		else
		{
			max = mid - 1;
		}
	}

	cout << solution;
	return 0;
}

/*
3 3
1 2 2
3 1 3
2 3 2
1 3
답: 3

9 9
1 4 11
1 5 2
4 5 4
4 3 10
4 2 7
5 2 10
5 6 13
3 2 9
2 6 8
1 6
답: 9

10000 3
9998 9999 2
10000 9998 3
9999 10000 2
9998 10000
답: 3

3 1
1 3 1
1 2
답: 0

5 5
1 2 5
2 3 4
1 3 3
1 4 3
4 5 1
5 1
ans: 1

6 9
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
6 3
ans: 8

6 12
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
3 6 7
1 3 11
5 6 12
6 3
ans: 9

3 1
1 2 999999999
1 2
ans: 999999999

3 3
1 2 2
3 1 2
2 3 2
1 3
ans: 2

3 3
1 2 2
3 1 2
2 3 99999999
1 3
ans: 2

5 5
1 2 5
2 3 4
1 3 3
1 4 3
4 5 1
5 1
ans: 1
*/