#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int>* triangle;
vector<int>* roots;
void findRoot(int level)
{
	if (level == n - 2)
	{
		for (int i = 0; i < level + 1; i++)
		{
			int bigger = triangle[level + 1][i] >= triangle[level + 1][i + 1] ? triangle[level + 1][i] : triangle[level + 1][i + 1];
			roots[level].push_back(triangle[level][i] + bigger);
		}

	}
	else
	{
		for (int i = 0; i < level + 1; i++)
		{
			int bigger = roots[level + 1][i] >= roots[level + 1][i + 1] ? roots[level + 1][i] : roots[level + 1][i + 1];
			roots[level].push_back(triangle[level][i] + bigger);
		}

	}
	if (level == 0)
	{
		return;
	}
	findRoot(level - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int d;
	cin >> n;
	triangle = new vector<int>[n];
	roots = new vector<int>[n - 1];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> d;
			triangle[i].push_back(d);
		}
	}
	if (n == 1)
	{
		cout << triangle[0][0];
		return 0;
	}
	findRoot(n - 2);
	cout << roots[0][0];
	return 0;
}