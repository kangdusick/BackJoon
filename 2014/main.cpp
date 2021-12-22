#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long int lli;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	priority_queue<int> pq;
	int K, N;
	int same = -1;
	cin >> K >> N;
	vector<int> primes(K);
	for (int i = 0; i < K; i++)
	{
		cin >> primes[i];
		pq.push(-primes[i]);
	}
	while (true)
	{
		lli temp;
		do
		{
			temp = pq.top();
			pq.pop();
		} while (same == temp);
		same = temp;
		for (int i = 0; i < K; i++)
		{
			lli num = (lli)temp * primes[i];
			if (num < -2147483648 || temp < -1073741824)
			{
				break;
			}
			pq.push((int)num);
		}
		N--;
		if (N == 0)
		{
			cout << -temp;
			break;
		}
	}


	return 0;
}