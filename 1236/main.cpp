#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N,M,i,j;
	cin >> N>>M;
	char** castle = new char*[N];
	string a;
	for (i = 0; i < N; i++)
	{
		castle[i] = new char[M];
	}
	for (i = 0; i < N; i++)
	{
		cin >> a;
		for (j = 0; j < M; j++)
		{
			castle[i][j] = a[j];
		}
	}
	int RowCount = 0;
	int colCount = 0;
	for (i = 0; i < N; i++)
	{
		bool isRow = false;
		for (j = 0; j < M; j++)
		{
			if (castle[i][j] == 'X')
			{
				isRow = true;
				break;
			}
			
		}
		if(!isRow)
		RowCount++;
	}
	for (j = 0; j < M; j++)
	{
		bool isCol = false;
		for (i = 0; i < N; i++)
		{

			if (castle[i][j] == 'X')
			{
				isCol = true;
				break;
			}
			
		}
		if (!isCol)
		colCount++;
	}
	printf("%d", RowCount > colCount ? RowCount : colCount);
	return 0;
}