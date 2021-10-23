#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
bool isChecke[101];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M,A,B,count = 0;
	map<int, map<int, bool>> gragh;
	map<int, bool>::iterator iter;
	queue<int> que;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		gragh[A][B] = true;
		gragh[B][A] = true;
	}
	que.push(1);
	isChecke[1] = true;
	while (que.size()!=0)
	{
		int front = que.front();
		int frontSize = gragh[front].size();
		que.pop();
		iter = gragh[front].begin();
		for (int i = 0; i < frontSize; i++)
		{
			if (isChecke[iter->first] == false)
			{
				que.push(iter->first);
				isChecke[iter->first] = true;
				count++;
			}
			iter++;
		}
	}
	cout << count;
	return 0;
}