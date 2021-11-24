#include <iostream>
#include <string>
using namespace std;
int N, M;
int** A;
int** CheckA;
int maxlen = 0;
void SetCheckA(int x, int y)
{
	if (A[x][y] == 0|| x <1||y<1)
	{
		return;
	}
	else
	{
		int a, b, c;
		int min = 210000000;
		a = CheckA[x - 1][y];
		min = a < min ? a : min;
		b = CheckA[x][y - 1];
		min = b < min ? b : min;
		c = CheckA[x - 1][y - 1];
		min = c < min ? c : min;
		CheckA[x][y] = min + 1;
		maxlen = CheckA[x][y] > maxlen ? CheckA[x][y] : maxlen;
	}
}
void ShowA()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << CheckA[i][j] << " ";
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	A = new int* [N];
	CheckA = new int* [N];
	string nums;
	getline(cin, nums);
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
		CheckA[i] = new int[M];
		getline(cin, nums);
		for (int j = 0; j < M; j++)
		{
			A[i][j] = nums[j] - 48;
			if (A[i][j] == 0)
			{
				CheckA[i][j] = 0;
			}
			else
			{
				CheckA[i][j] = 1;
				maxlen = 1;
			}
		}
		nums.clear();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			SetCheckA(i,j);
		}
	}
	cout << maxlen * maxlen;
	return 0;
}

/*
4 5
11111
11111
11111
11111

1 1
1
*/