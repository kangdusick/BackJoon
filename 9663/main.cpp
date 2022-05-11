#include <iostream>
using namespace std;
int N;
int endNum;
int sol=0;
int** check;
void SetCheck(int x, int n)
{
	//가로
	for (int i = 0; i < N; i++)
	{
		check[x][i]++;
	}
	//세로
	for (int i = 0; i < N; i++)
	{
		check[i][n]++;
	}
	check[x][n]--;
	//대각선1
	for (int i = 1; i < N; i++)
	{
		if (x + i >= 0 && x + i < N && n + i >= 0 && n + i < N)
		{
			check[x + i][n + i] ++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (x - i >= 0 && x - i < N && n - i >= 0 && n - i < N)
		{
			check[x - i][n - i] ++;
		}
		else
		{
			break;
		}
	}
	//대각선2
	for (int i = 1; i < N; i++)
	{
		if (x + i >= 0 && x + i < N && n - i >= 0 && n - i < N)
		{
			check[x + i][n - i] ++;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (x - i >= 0 && x - i < N && n + i >= 0 && n + i < N)
		{
			check[x - i][n + i] ++;
		}
		else
		{
			break;
		}
	}
}
void UnsetCheck(int x, int n)
{
	//가로
	for (int i = 0; i < N; i++)
	{
		check[x][i]--;
	}
	//세로
	for (int i = 0; i < N; i++)
	{
		check[i][n]--;
	}
	check[x][n]++;
	//대각선1
	for (int i = 1; i < N; i++)
	{
		if (x + i >= 0 && x + i < N && n + i >= 0 && n + i < N)
		{
			check[x + i][n + i] --;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (x - i >= 0 && x - i < N && n - i >= 0 && n - i < N)
		{
			check[x - i][n - i] --;
		}
		else
		{
			break;
		}
	}
	//대각선2
	for (int i = 1; i < N; i++)
	{
		if (x + i >= 0 && x + i < N && n - i >= 0 && n - i < N)
		{
			check[x + i][n - i] --;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i < N; i++)
	{
		if (x - i >= 0 && x - i < N && n + i >= 0 && n + i < N)
		{
			check[x - i][n + i] --;
		}
		else
		{
			break;
		}
	}
}
void Nqueen(int x)
{
	if (x == N)
	{
		sol++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (check[x][i] == 0)
		{
			SetCheck(x, i);
			Nqueen(x + 1);
			UnsetCheck(x,i);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	check = new int* [N];
	for (int i = 0; i < N; i++)
	{
		check[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			check[i][j] = 0;
		}
	}
	endNum = N - 1;
	Nqueen(0);
	cout << sol;
	return 0;
}