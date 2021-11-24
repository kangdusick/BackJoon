#include <iostream>
#include <string>
using namespace std;
int** A;
int** B;
int N, M;
int sol = 0;
void SwapA(int x, int y)
{
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			A[i][j] = 1 - A[i][j];
		}
	}
	sol++;
}
bool CheckSame()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[i][j] != B[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
void ShowA()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << A[i][j]<<" ";
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
	B = new int* [N];
	string nums;
	getline(cin, nums);
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
		getline(cin, nums);
		for (int j = 0; j < M; j++)
		{
			A[i][j] = nums[j]-48;
		}
		nums.clear();
	}
	for (int i = 0; i < N; i++)
	{
		B[i] = new int[M];
		getline(cin, nums);
		for (int j = 0; j < M; j++)
		{
			B[i][j] = nums[j] - 48;
		}
		nums.clear();
	}
	for (int i = 0; i <= N - 3; i++)
	{
		for (int j = 0; j <= M - 3; j++)
		{
			if (A[i][j] != B[i][j])
			{
				SwapA(i, j);
				if (CheckSame())
				{
					break;
				}
			}
		}
	}
	if (CheckSame() == false)
	{
		cout << -1;
		return 0;
	}
	
	cout << sol;
	return 0;
}