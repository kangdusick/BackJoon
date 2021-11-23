#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int** A;
int** B; // A의 카피본
int** Origin;
int** RCS;
int Pnums[7];
vector<int> pnumsList[1000];
int pnumsListCount = 0;
int meanVal = 2100000000;
void SetOrigin()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			A[i][j] = Origin[i][j];
			B[i][j] = Origin[i][j];
		}
	}
}
void Rotate(int x1, int y1, int x2, int y2)
{
	int len = x2 - x1+1;
	//윗줄
	A[x1][y1] = B[x1 + 1][y1];
	for (int i = 1 ; i <len;i++ )
	{
		A[x1][y1+i] = B[x1][y1+i-1];
	}
	//오른쪽
	A[x1][y2] = B[x1][y2-1];
	for (int i = 1; i < len; i++)
	{
		A[x1+i][y2] = B[x1+i-1][y2];
	}
	//아래
	A[x2][y2] = B[x2 -1][y2];
	for (int i = 1; i < len; i++)
	{
		A[x2][y2 - i] = B[x2][y2 - i + 1];
	}
	//왼쪽
	A[x2][y1] = B[x2][y1 + 1];
	for (int i = 1; i < len; i++)
	{
		A[x2 - i][y1] = B[x2 - i + 1][y1];
	}
}
void RotateRCS(int i)
{
	int r = RCS[i][0];
	int c = RCS[i][1];
	int s = RCS[i][2];
	int x1 = r - s - 1;
	int y1 = c - s - 1;
	int x2 = r + s - 1;
	int y2 = c + s - 1;
	while (x1 != x2)
	{
		Rotate(x1, y1, x2, y2);
		x1++;
		y1++;
		x2--;
		y2--;
	}
}
void FindMeanVal()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum = 0;
		for (int j = 0; j < M; j++)
		{
			sum += A[i][j];
		}
		if (sum < meanVal)
		{
			meanVal = sum;
		}
	}
}
void MakeAllSets()
{
	vector<int> nums;
	for (int i = 0; i < K; i++)
	{
		nums.push_back(i);
	}
	pnumsList[pnumsListCount] = nums;
	pnumsListCount++;
	while (next_permutation(nums.begin(), nums.end()))
	{
		pnumsList[pnumsListCount] = nums;
		pnumsListCount++;
	}
	
}
void SetB()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			B[i][j] = A[i][j];
		}
	}
}
void DoAllRCS()
{
	for (int i = 0; i < pnumsListCount; i++)
	{
		for (int j = 0; j < K; j++)
		{
			RotateRCS(pnumsList[i][j]);
			SetB();
		}
		FindMeanVal();
		SetOrigin();
	}
}
void ShowA()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout<< A[i][j]<<" ";
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int r, c, s;
	cin >> N >> M >> K;
	A = new int* [N];
	B = new int* [N];
	Origin = new int* [N];
	RCS = new int* [K];
	for (int i = 0; i < N; i++)
	{
		A[i] = new int[M];
		B[i] = new int[M];
		Origin[i] = new int[M];
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			B[i][j] = A[i][j];
			Origin[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		RCS[i] = new int[3];
		cin >> r >> c >> s;
		RCS[i][0] = r;
		RCS[i][1] = c;
		RCS[i][2] = s;
	}
	MakeAllSets();
	DoAllRCS();
	cout << meanVal;
	return 0;
}

/*
5 6 3
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 4 2
4 2 1
3 2 1
*/