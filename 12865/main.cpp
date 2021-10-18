#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> W;
vector<int> V;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	int** table = new int* [N+1];
	int max = 0;
	int A, B;
	for (int i = 0; i <= N; i++)
	{
		table[i] = new int[K+1];
	}
	for (int j = 0; j <= K; j++)
	{
		table[0][j] = 0;
	}
	W.push_back(0);
	V.push_back(0);
	for (int i = 1; i <= N; i++)
	{
		cin >> A >> B;
		W.push_back(A);
		V.push_back(B);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			table[i][j] = table[i - 1][j];
		}
		if (table[i - 1][W[i]]< V[i]&&W[i]<=K)
		{
			table[i][W[i]] = V[i];
			if (max < V[i])
				max = V[i];
		}
		int j = W[i]+1; // W[i]: 현재 아이템의 무게.
		int left;  //최대 무게에서 현재 무게 뺀 값.
		for (j; j <= K; j++)
		{
			left = j-W[i];
			if (table[i - 1][j] < table[i-1][left] + V[i] && W[i] <= K)
			{
				table[i][j] = table[i-1][left] + V[i];
				if (max < table[i][j])
					max = table[i][j];
			}
		}
	}
	cout << max;
	return 0;
}

/*
10 999
46 306
60 311
33 724
18 342
57 431
49 288
12 686
89 389
82 889
16 289
답:4655

3 5
4 2
3 4
1 5
답: 9

10 11
1 306
1 311
1 724
1 342
1 431
1 288
1 686
1 389
1 889
1 289
답:4655

4 5
1 2
1 4
1 5
1 2
답: 13

2 1
2 2
2 2
답: 0
*/