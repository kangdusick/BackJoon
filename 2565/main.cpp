#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int As[501];
vector<int> as;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int A, B;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		As[A]=B;
	}
	for (int i = 1; i <= 500; i++)
	{
		if (As[i] != 0)
		{
			as.push_back(As[i]);
		}
	}
	int asSize = as.size();
	vector<int> sol(asSize);
	for (int i = asSize - 1; i >= 0; i--)
	{
		int tempmax = 0;
		for (int j = i+1; j < asSize; j++)
		{
			if (as[i] < as[j] && tempmax < sol[j])
			{
				tempmax = sol[j];
			}
		}
		sol[i] = tempmax + 1;
	}
	sort(sol.begin(), sol.end());
	cout << asSize - sol[asSize - 1]<<"\n";
	return 0;
}