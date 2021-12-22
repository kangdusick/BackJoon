#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<int, map<int, int>> nums; // i번 컴퓨터가 value 컴퓨터를 의존하며 감염시키는 시간은 val-val값이다.
vector<int> nums2[10001]; //i번 컴퓨터를 의존하는 컴퓨터들 저장
queue<int> que;
bool checked[10001];
int timeTable[10001];
vector<int> sol;
void init()
{
	for (int i = 0; i < 10001; i++)
	{
		checked[i] = false;
		nums2[i].clear();
		timeTable[i] = 2100000000;
	}
	int quesize = que.size();
	for (int i = 0; i < quesize;i++)
	{
		que.pop();
	}

	nums.clear();
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, n, d, c;
	int a, b, s;
	cin >> T;
	for (int j = 0; j < T; j++)
	{
		cin >> n >> d >> c;
		init();
		int count = 1;
		for (int i = 0; i < d; i++)
		{
			cin >> a >> b >> s;
			nums[a][b] = s;
			nums2[b].push_back(a);
		}
		que.push(c);
		checked[c] = true;
		while (que.size() != 0)
		{
			int front = que.front();
			que.pop();
			int frontSize = nums2[front].size();
			for (int i = 0; i < frontSize; i++)
			{
				if (checked[nums2[front][i]] == false)
				{
					checked[nums2[front][i]] = true;
					que.push(nums2[front][i]);
					count++;

				}
			}
		}

		for (int i = 0; i < 10001; i++)
		{
			checked[i] = false;
		}
		timeTable[c] = 0;
		int front = c;
		que.push(c);
		checked[c] = true;
		int nextfront=-1;
		int max = 0;
		while (que.size()!=0)
		{
			front = que.front();
			que.pop();
			int frontSize = nums2[front].size();
			int min = 2100000000;
			nextfront = -1;
			for (int i = 0; i < frontSize; i++)
			{
				if (timeTable[front] + nums[nums2[front][i]][front] < timeTable[nums2[front][i]])
				{
					timeTable[nums2[front][i]] =  timeTable[front] + nums[nums2[front][i]][front];
				}
				if (min > timeTable[nums2[front][i]] && checked[nums2[front][i]] == false)
				{
					min = timeTable[nums2[front][i]];
					nextfront = nums2[front][i];
				}
			}
			if (nextfront != -1)
			{
			que.push(nextfront);
			checked[nextfront] = true;

			}
		}
		for (int i = 0; i < 10001; i++)
		{
			checked[i] = false;
		}
		que.push(c);
		checked[c] = true;
		while (que.size() != 0)
		{
			int front = que.front();
			que.pop();
			int frontSize = nums2[front].size();
			if (max < timeTable[front])
			{
				max = timeTable[front];
			}
			for (int i = 0; i < frontSize; i++)
			{
				if (checked[nums2[front][i]] == false)
				{
					checked[nums2[front][i]] = true;
					que.push(nums2[front][i]);

				}
			}
		}
		sol.push_back(count);
		sol.push_back(max);
	}
	for (int i = 0; i < sol.size(); i++)
	{
		cout << sol[i] << " ";
		if (i % 2 == 1)
		{
			cout << endl;
		}
	}

	return 0;
}

/*
1
4 5 1
2 1 2
3 2 2
4 3 2
4 1 100
2 4 2

1
4 4 1
2 1 2
3 2 2
4 1 100
2 4 2

1
2 2 2
2 1 1
1 2 10

1
6 9 3
2 1 1
3 2 2
4 3 4
4 1 5
5 4 6
6 5 7
1 6 9
4 6 8
3 1 3

*/