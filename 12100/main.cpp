#include <iostream>
#include <queue>
using namespace std;
int** A;
int** Origin;
int N;
int sol = 0;
queue<int> que;
queue<int> FinalQueue;
void MoveRight()
{
	for (int i = 0; i < N; i++)
	{
		int j = N - 1;
		for (j; j>=0; j--)
		{
			if (A[i][j] == 0)
			{
				continue;
			}
			if (que.size()>0 && que.front() == A[i][j])
			{
				que.pop();
				FinalQueue.push(A[i][j] * 2);
			}
			else if(que.size()>0)
			{
				FinalQueue.push(que.front());
				que.pop();
				que.push(A[i][j]);
			}
			else
			{
				que.push(A[i][j]);
			}
			A[i][j] = 0;
		}
		while (que.size()!=0)
		{
			FinalQueue.push(que.front());
			que.pop();
		}
		j = N - 1;
		while (FinalQueue.size() != 0)
		{
			A[i][j] = FinalQueue.front();
			if (sol < A[i][j])
			{
				sol = A[i][j];
			}
			FinalQueue.pop();
			j--;
		}
	}
}
void MoveLeft()
{
	for (int i = 0; i < N; i++)
	{
		int j = 0;
		for (j; j <N; j++)
		{
			if (A[i][j] == 0)
			{
				continue;
			}
			if (que.size() > 0 && que.front() == A[i][j])
			{
				que.pop();
				FinalQueue.push(A[i][j] * 2);
			}
			else if (que.size() > 0)
			{
				FinalQueue.push(que.front());
				que.pop();
				que.push(A[i][j]);
			}
			else
			{
				que.push(A[i][j]);
			}
			A[i][j] = 0;
		}
		while (que.size() != 0)
		{
			FinalQueue.push(que.front());
			que.pop();
		}
		j = 0;
		while (FinalQueue.size() != 0)
		{
			A[i][j] = FinalQueue.front();
			if (sol < A[i][j])
			{
				sol = A[i][j];
			}
			FinalQueue.pop();
			j++;
		}
	}
}
void MoveTop()
{
	for (int j = 0; j < N; j++)
	{
		int i = 0;
		for (i; i < N; i++)
		{
			if (A[i][j] == 0)
			{
				continue;
			}
			if (que.size() > 0 && que.front() == A[i][j])
			{
				que.pop();
				FinalQueue.push(A[i][j] * 2);
			}
			else if (que.size() > 0)
			{
				FinalQueue.push(que.front());
				que.pop();
				que.push(A[i][j]);
			}
			else
			{
				que.push(A[i][j]);
			}
			A[i][j] = 0;
		}
		while (que.size() != 0)
		{
			FinalQueue.push(que.front());
			que.pop();
		}
		i = 0;
		while (FinalQueue.size() != 0)
		{
			A[i][j] = FinalQueue.front();
			if (sol < A[i][j])
			{
				sol = A[i][j];
			}
			FinalQueue.pop();
			i++;
		}
	}
}
void MoveDown()
{
	for (int j = 0; j < N; j++)
	{
		int i = N-1;
		for (i; i >= 0; i--)
		{
			if (A[i][j] == 0)
			{
				continue;
			}
			if (que.size() > 0 && que.front() == A[i][j])
			{
				que.pop();
				FinalQueue.push(A[i][j] * 2);
			}
			else if (que.size() > 0)
			{
				FinalQueue.push(que.front());
				que.pop();
				que.push(A[i][j]);
			}
			else
			{
				que.push(A[i][j]);
			}
			A[i][j] = 0;
		}
		while (que.size() != 0)
		{
			FinalQueue.push(que.front());
			que.pop();
		}
		i = N-1;
		while (FinalQueue.size() != 0)
		{
			A[i][j] = FinalQueue.front();
			if (sol < A[i][j])
			{
				sol = A[i][j];
			}
			FinalQueue.pop();
			i--;
		}
	}
}
void init()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = Origin[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	A = new int*[N];
	Origin = new int* [N];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[N];
		Origin[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
			Origin[i][j] = A[i][j];
		}
	}
	for (int a = 0; a < 4; a++)
	{
		for (int b = 0; b < 4; b++)
		{
			for (int c = 0; c < 4; c++)
			{
				for (int d = 0; d < 4; d++)
				{
					for (int e = 0; e < 4; e++)
					{
						switch (a)
						{
						case 0:
							MoveDown();
							break;
						case 1:
							MoveLeft();
							break;
						case 2:
							MoveRight();
							break;
						case 3:
							MoveTop();
							break;
						}
						switch (b)
						{
						case 0:
							MoveDown();
							break;
						case 1:
							MoveLeft();
							break;
						case 2:
							MoveRight();
							break;
						case 3:
							MoveTop();
							break;
						}
						switch (c)
						{
						case 0:
							MoveDown();
							break;
						case 1:
							MoveLeft();
							break;
						case 2:
							MoveRight();
							break;
						case 3:
							MoveTop();
							break;
						}
						switch (d)
						{
						case 0:
							MoveDown();
							break;
						case 1:
							MoveLeft();
							break;
						case 2:
							MoveRight();
							break;
						case 3:
							MoveTop();
							break;
						}
						switch (e)
						{
						case 0:
							MoveDown();
							break;
						case 1:
							MoveLeft();
							break;
						case 2:
							MoveRight();
							break;
						case 3:
							MoveTop();
							break;
						}
						init();
					}
				}
			}
		}
	}
	cout << sol;
	return 0;
}