#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int sol = -1;

void setA(int i,int j, int N,int r, int c,int max)
{
	int plus = N * N / 4;
	int halfN = N / 2;
	if (N != 2)
	{
		if (i - halfN < r && j - halfN < c)
		{
			setA(i, j, N / 2, r, c, max);
		}
		else if (i - halfN < r && j - halfN >= c)
		{
			setA(i, j - N / 2, N / 2, r, c, max - plus);
		}
		else if (i - halfN >= r && j - halfN < c)
		{
			setA(i - N / 2, j, N / 2, r, c, max - plus * 2);
		}
		else if (i - halfN >= r && j-halfN >= c)
		{
			setA(i - N / 2, j - N / 2, N / 2, r, c, max - plus * 3);
		}
		
	}
	else
	{
		if (i == r && j == c)
		{
			sol = max;
		}
		if (i == r && j-1 == c)
		{
			sol = max-1;
		}
		if (i-1 == r && j == c)
		{
			sol = max-2;
		}
		if (i-1 == r && j-1 == c)
		{
			sol = max-3;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int NN, r, c, i, j;

	cin >> NN >> r >> c;
	int N = 2<<(NN-1);

	setA(N-1, N-1, N,r,c,N*N-1);
	cout << sol;

	return 0;
}