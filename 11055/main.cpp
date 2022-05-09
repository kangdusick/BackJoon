#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int* A;
	int* DP;
	int maxx;
	cin >> N;
	A = new int[N];
	DP = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		DP[i] = A[i];
	}
	for (int i = 0; i < N; i++)
	{
		maxx = 0;
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && DP[j]>maxx)
			{
				maxx = DP[j];
			}
		}
		DP[i] += maxx;
	}
	sort(DP, DP + N);
	cout << DP[N-1];
	return 0;
}