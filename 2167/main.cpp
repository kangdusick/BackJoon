#include <iostream>
using namespace std;
int** Ks;
int** SumA;
int N, M, K;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c, d,num;
	int* sol;
	cin >> N >> M;
	SumA = new int* [N];
	for (int i = 0; i < N; i++)
	{
		SumA[i] = new int[M];
		int tempSum = 0;
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			tempSum += num;
			SumA[i][j] = tempSum;
		}
	}
	cin >> K;
	sol = new int[K];
	for (int i = 0; i < K; i++)
	{
		sol[i] = 0;
		cin >> a >> b >> c >> d;
		for (int ii = a - 1; ii < c; ii++)
		{
			sol[i] += SumA[ii][d - 1];
			if(b-2>=0)
			sol[i] -= SumA[ii][b - 2];
		}

	}
	for (int i = 0; i < K; i++)
	{
		cout << sol[i]<<"\n";
	}
	return 0;
}

/*
2 3
1 2 4
8 16 32
3
2 2 2 2
1 2 1 2
1 3 2 3
*/