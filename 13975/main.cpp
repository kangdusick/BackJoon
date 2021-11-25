#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef long long int lld;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, K, num;
	priority_queue<lld> pq;
	vector<lld> sol;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> K;
		lld cost = 0;
		lld sum = 0;
		for (int j = 0; j < K; j++)
		{
			cin >> num;
			pq.push(-num);
		}
		while (pq.size() != 1)
		{
			sum = pq.top();
			pq.pop();
			sum += pq.top();
			pq.pop();
			pq.push(sum);
			cost += sum;
		}
		sol.push_back(-cost);
		pq.pop();
	}
	for (int i = 0; i < T; i++)
	{
		cout << sol[i] << "\n";
	}
	return 0;
}