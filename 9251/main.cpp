#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str1;
	string str2;
	cin >> str1 >> str2;
	int N = str1.size()+1;
	int N2 = str2.size();
	int** samecount = new int*[2];
	int nowindex = 1;
	int beforeindex = 0;
	for (int i = 0; i < 2; i++)
	{
		samecount[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		samecount[0][i] = 0;
		samecount[1][i] = 0;
	}
	N--;
	for (int i = 0; i < N2; i++)
	{
		nowindex = 1 - nowindex;
		beforeindex = 1 - nowindex;
		for (int j = 0; j < N; j++)
		{
			if (str1[j] == str2[i])
			{
				samecount[nowindex][j + 1] = samecount[beforeindex][j] + 1;
			}
			else
			{
				samecount[nowindex][j + 1] = samecount[beforeindex][j + 1] > samecount[nowindex][j] ? samecount[beforeindex][j + 1] : samecount[nowindex][j];
			}
		}
	}
	cout << samecount[nowindex][N];
	return 0;
}

/*
acaba
aaaff
3
*/