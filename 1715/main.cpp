#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, input;
	int count = 0;
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		pq.push(input);
	}
	while (pq.size()!=1)
	{
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();
		pq.push(num1 + num2);
		count = count + num1 + num2;
	}
	cout <<  count;
	return 0;
}