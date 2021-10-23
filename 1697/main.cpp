#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
bool checked[100001];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K, time = -1;
	queue<int> que;
	cin >> N >> K;
	que.push(N);
	checked[N] = true;
	while (true)
	{
		int queSize = que.size();
		int top;
		time++;
		for (int i = 0; i < queSize; i++)
		{
			top = que.front();
			if (top == K)
				break;
			que.pop();
			if (top + 1 >= 0 && top + 1 <= 100000 && checked[top + 1] == false)
			{
				que.push(top + 1);
				checked[top + 1] = true;
			}

			if (top - 1 >= 0 && top - 1 <= 100000 && checked[top - 1] == false)
			{
				checked[top - 1] = true;
				que.push(top - 1);
			}
			if (top * 2 >= 0 && top * 2 <= 100000 && checked[top * 2] == false)
			{
				que.push(top * 2);
				checked[top * 2] = true;

			}
		}
		if (top == K)
		{
			cout << time;
			break;
		}

	}

	return 0;
}