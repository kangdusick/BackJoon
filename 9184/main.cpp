#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<int> sol;
map<int, map<int, map<int, int>>> dp;
map<int, map<int, map<int, bool>>> check;
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (check[a][b][c] == true)
	{
		return dp[a][b][c];
	}
	else if (a > 20 || b > 20 || c > 20)
	{
		if (check[20][20][20] == true)
		{
			check[a][b][c] =true;
			return dp[20][20][20];
		}
		else
		{
			check[a][b][c] = true;
			return dp[a][b][c] = w(20, 20, 20);
		}
	}
	else if (a < b && b < c)
	{
		check[a][b][c] = true;
		return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else
	{
		check[a][b][c] = true;
		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout << 'w' << '(' << a << ", " << b << ", " << c << ')' << " = " << w(a, b, c) << endl;
	}
	return 0;
}