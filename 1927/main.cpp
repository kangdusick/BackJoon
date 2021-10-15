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
	cin >> N;
	vector<int> sol;
	priority_queue<int,vector<int>,greater<int>> pq;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		if (input == 0)
		{
			if (pq.size() == 0)
				sol.push_back(0);
			else
			{
				sol.push_back(pq.top());
				pq.pop();
			}	
		}
		else
		{
			pq.push(input);
		}
	}
	int size = sol.size();
	for (int i = 0; i < size; i++)
	{
		cout << sol[i] << "\n";
	}


	return 0;
}