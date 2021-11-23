#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int** blocks;
int** BackupS;
int N;
int Sol = 0;

void MoveUp()
{
	queue<int> que;
	for (int j = 0; j < N; j++) //왼쪽에서 오른쪽으로 이동하면서 그 열의 위에서 아래로, 블록 2개씩 비교해 숫자가 같으면 합친다.
	{
		vector<int> exceptZero;
		for (int i = 0; i < N; i++)
		{
			if (blocks[i][j] != 0)
			{
				exceptZero.push_back(blocks[i][j]);
			}
		}
		int vectorSize = exceptZero.size();
		if (vectorSize == 0)
		{
			continue;
		}
		for (int i = 0; i < vectorSize - 1; i++)
		{
			if (exceptZero[i] == exceptZero[i + 1])
			{
				que.push(exceptZero[i] * 2);
				exceptZero[i] = 0;
				exceptZero[i + 1] = 0;
			}
			else if (exceptZero[i] != 0)
			{
				que.push(exceptZero[i]);
			}
		}
		if (exceptZero[vectorSize - 1] != 0)
		{
			que.push(exceptZero[vectorSize - 1]);
		}
		for (int i = 0; i < N; i++)
		{
			if (que.size() != 0)
			{
				blocks[i][j] = que.front();
				if (blocks[i][j] > Sol)
				{
					Sol = blocks[i][j];
				}
				que.pop();
			}
			else
			{
				blocks[i][j] = 0;
			}
		}
	}
}
void MoveDown()
{
	queue<int> que;
	for (int j = 0; j < N; j++) //왼쪽에서 오른쪽으로 이동하면서 그 열의 아래에서 위로, 블록 2개씩 비교해 숫자가 같으면 합친다.
	{
		vector<int> exceptZero;
		for (int i = N - 1; i >= 0; i--)
		{
			if (blocks[i][j] != 0)
			{
				exceptZero.push_back(blocks[i][j]);
			}
		}
		int vectorSize = exceptZero.size();
		if (vectorSize == 0)
		{
			continue;
		}
		for (int i = 0; i < vectorSize - 1; i++)
		{
			if (exceptZero[i] == exceptZero[i + 1])
			{
				que.push(exceptZero[i] * 2);
				exceptZero[i] = 0;
				exceptZero[i + 1] = 0;
			}
			else if (exceptZero[i] != 0)
			{
				que.push(exceptZero[i]);
			}
		}
		if (exceptZero[vectorSize - 1] != 0)
		{
			que.push(exceptZero[vectorSize - 1]);
		}
		for (int i = N - 1; i >= 0; i--)
		{
			if (que.size() != 0)
			{
				blocks[i][j] = que.front();
				if (blocks[i][j] > Sol)
				{
					Sol = blocks[i][j];
				}
				que.pop();
			}
			else
			{
				blocks[i][j] = 0;
			}
		}
	}
}
void MoveLeft()
{
	queue<int> que;
	for (int i = 0; i < N; i++) //위에서 아래로 이동하면서 그 행의 오른쪽에서 왼쪽으로, 블록 2개씩 비교해 숫자가 같으면 합친다.
	{
		vector<int> exceptZero;
		for (int j = 0; j < N; j++)
		{
			if (blocks[i][j] != 0)
			{
				exceptZero.push_back(blocks[i][j]);
			}
		}
		int vectorSize = exceptZero.size();
		if (vectorSize == 0)
		{
			continue;
		}
		for (int j = 0; j < vectorSize - 1; j++)
		{
			if (exceptZero[j] == exceptZero[j + 1])
			{
				que.push(exceptZero[j] * 2);
				exceptZero[j] = 0;
				exceptZero[j + 1] = 0;
			}
			else if (exceptZero[j] != 0)
			{
				que.push(exceptZero[j]);
			}
		}
		if (exceptZero[vectorSize - 1] != 0)
		{
			que.push(exceptZero[vectorSize - 1]);
		}
		for (int j = 0; j < N; j++)
		{
			if (que.size() != 0)
			{
				blocks[i][j] = que.front();
				if (blocks[i][j] > Sol)
				{
					Sol = blocks[i][j];
				}
				que.pop();
			}
			else
			{
				blocks[i][j] = 0;
			}
		}
	}
}
void MoveRight()
{
	queue<int> que;
	for (int i = 0; i < N; i++) //위에서 아래로 이동하면서 그 행의 왼쪽에서 오른쪽으로, 블록 2개씩 비교해 숫자가 같으면 합친다.
	{
		vector<int> exceptZero;
		for (int j = N - 1; j >= 0; j--)
		{
			if (blocks[i][j] != 0)
			{
				exceptZero.push_back(blocks[i][j]);
			}
		}
		int vectorSize = exceptZero.size();
		if (vectorSize == 0)
		{
			continue;
		}
		for (int j = 0; j < vectorSize - 1; j++)
		{
			if (exceptZero[j] == exceptZero[j + 1])
			{
				que.push(exceptZero[j] * 2);
				exceptZero[j] = 0;
				exceptZero[j + 1] = 0;
			}
			else if (exceptZero[j] != 0)
			{
				que.push(exceptZero[j]);
			}
		}
		if (exceptZero[vectorSize - 1] != 0)
		{
			que.push(exceptZero[vectorSize - 1]);
		}
		for (int j = N - 1; j >= 0; j--)
		{
			if (que.size() != 0)
			{
				blocks[i][j] = que.front();
				if (blocks[i][j] > Sol)
				{
					Sol = blocks[i][j];
				}
				que.pop();
			}
			else
			{
				blocks[i][j] = 0;
			}
		}
	}
}
void MoveBlocks(int num)
{
	switch (num) //0:up 1:down 2:
	{
	case 0:
		MoveUp();
		break;
	case 1:
		MoveDown();
		break;
	case 2:
		MoveLeft();
		break;
	case 3:
		MoveRight();
		break;
	default:
		break;
	}
}

void LoadBackup()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			blocks[i][j] = BackupS[i][j];
		}
	}
}
void ShowBlocks()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout<< blocks[i][j]<<" ";
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	blocks = new int* [N];
	BackupS = new int* [N];
	for (int i = 0; i < N; i++)
	{
		blocks[i] = new int[N];
		BackupS[i] = new int[N];
		for (int j = 0; j < N; j++)
		{
			cin >> blocks[i][j];
			BackupS[i][j] = blocks[i][j];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int z = 0; z < 4; z++)
				{
					for (int x = 0; x < 4; x++)
					{
						MoveBlocks(i);
						MoveBlocks(j);
						MoveBlocks(k);
						MoveBlocks(z);
						MoveBlocks(x);
						LoadBackup();
					}
				}
			}
		}
	}
	cout << Sol;
	return 0;
}
