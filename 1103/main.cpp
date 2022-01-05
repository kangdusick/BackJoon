#include <iostream>
#include <vector>
using namespace std;
int M, N; // M:i, 가로  N:j, 세로
vector<int> board[50];
vector<bool> check[50]; //true면 이전에 방문했던 좌표
vector<int> dp[50];
int Max = 0;
void dfs(int x, int y, int level)
{
	int up = y - board[y][x];
	int down = y + board[y][x];
	int left = x- board[y][x];
	int right = x + board[y][x];

	if (Max < level)
	{
		Max = level;
	}
	if (board[y][x] == 24)
	{
		return;
	}
	//상
	if (up >= 0)
	{
		if (Max == -1)
		{
			return;
		}
		if (check[up][x])
		{
			Max = -1;
			return;
		}
		if (dp[up][x] != 0)
		{
			dp[up][x] = level+dp[up][x]-2;
			if (Max < dp[up][x])
			{
				Max = dp[up][x];
			}
		}
		else
		{
			check[up][x] = true;
			dfs(x, up, level + 1);
			check[up][x] = false;
			dp[up][x] = Max;
		}
	}
	//하
	if (down < N)
	{
		if (Max == -1|| dp[down][x] != 0)
		{
			return;
		}
		if (check[down][x])
		{
			Max = -1;
			return;
		}
		if (dp[down][x] != 0)
		{
			dp[down][x] = level + dp[down][x]-2;
			if (Max < dp[down][x])
			{
				Max = dp[down][x];
			}
		}
		else
		{
			check[down][x] = true;
			dfs(x, down, level + 1);
			check[down][x] = false;
			dp[down][x] = Max;
		}
		
	}
	else
	{
		if (Max < level+1)
		{
			Max = level+1;
		}
	}
	//좌
	if (left >= 0)
	{
		if (Max == -1|| dp[y][left] != 0)
		{
			return;
		}
		if (check[y][left])
		{
			Max = -1;
			return;
		}
		if (dp[y][left] != 0)
		{
			dp[y][left] = level + dp[y][left]-2;
			if (Max < dp[y][left])
			{
				Max = dp[y][left];
			}
		}
		else
		{
			check[y][left] = true;
			dfs(left, y, level + 1);
			check[y][left] = false;
			dp[y][left] = Max;
		}
		
	}
	else
	{
		if (Max == -1)
		{
			return;
		}
		if (Max < level + 1)
		{
			Max = level + 1;
		}
	}
	//우
	if (right <M)
	{
		if (Max == -1|| dp[y][right] !=0)
		{
			return;
		}
		if (check[y][right])
		{
			Max = -1;
			return;
		}
		if (dp[y][right] != 0)
		{
			dp[y][right] = level + dp[y][right]-2;
			if (Max < dp[y][right])
			{
				Max = dp[y][right];
			}
		}
		else
		{
			check[y][right] = true;
			dfs(right, y, level + 1);
			check[y][right] = false;
			dp[y][right] = Max;
		}
		
	}
	else
	{
		if (Max == -1)
		{
			return;
		}
		if (Max < level + 1)
		{
			Max = level + 1;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	string input = "";
	for (int j = 0; j < N; j++)
	{
		cin >> input;
		for (int i = 0; i < M; i++)
		{
			board[j].push_back(input[i]-48);
			check[j].push_back(false);
			dp[j].push_back(0);
		}
	}
	check[0][0] = true;
	dfs(0,0,0);
	cout << Max<<"\n";
	return 0;
}

/*
4 4
3HH2
H1HH
H2H1
2219

답: 8
*/