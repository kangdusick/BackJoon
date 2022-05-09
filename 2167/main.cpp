#include <iostream>
using namespace std;
int N, M;
int K;
int** A;
int** B;
int** DP;
int Sol(int x1, int y1, int x2, int y2)
{
	int sol = DP[x2][y2];
	if (x1 == 0 && y1 == 0)
	{
		return sol;
	}
	if (y1 >= 1)
	{
		sol -= DP[x2][y1-1];
	}
	if (x1 >= 1)
	{
		sol -= DP[x1 - 1][y2];
	}
	if (y1>= 1&& x1 >= 1)
	{
		sol += DP[x1 - 1][y1 - 1];
	}
	return sol;
}
void SetDP()
{
	DP[0][0] = A[0][0];
	for (int i = 1; i < N; i++)
	{
		DP[i][0] += DP[i - 1][0]+A[i][0];
	}
	for (int j = 1; j < M; j++)
	{
		DP[0][j] += DP[0][j-1] + A[0][j];
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			DP[i][j] = DP[i][j - 1]+DP[i-1][j]-DP[i-1][j-1]+A[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	A = new int* [N];
	DP = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
		DP[i] = new int[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			DP[i][j] = 0;
		}
	}
	cin >> K;
	B = new int* [K];
	for (int i = 0; i < K; i++)
	{
		B[i] = new int[4];
	}
	for (int i = 0; i < K; i++)
	{
		cin >> B[i][0] >> B[i][1] >> B[i][2] >> B[i][3];
	}
	SetDP();
	for (int i = 0; i < K; i++)
	{
		cout << Sol(B[i][0]-1, B[i][1]-1, B[i][2]-1, B[i][3]-1)<<"\n";
	}
	return 0;
}