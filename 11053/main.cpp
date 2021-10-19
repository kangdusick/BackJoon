#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int* A = new int[N];
	int* solutions = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < N; i++)
	{
		solutions[i] = 1;
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (A[i] > A[j])
			{
				if(solutions[i] < solutions[j] + 1)
					solutions[i] = solutions[j] + 1;
			}
		}
	}
	sort(solutions, solutions + N);
	cout << solutions[N - 1];

	return 0;
}

/*
20
7 8 9 10 11 12 13 14 1 2 3 1 2 3 4 2 3 4 5 6
*/