#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N = 0;
	int M = 0;
	int i = 0;
	scanf("%d", &N);
	int* aN = new int[N];
	for (i = 0; i < N; i++)
	{
		scanf("%d", &aN[i]);
	}
	scanf("%d", &M);
	int* aM = new int[M];
	for (i = 0; i < M; i++)
	{
		scanf("%d", &aM[i]);
	}
	sort(aN, aN + N);
	for (i = 0; i < M; i++)
	{
		printf("%d\n", binary_search(aN, aN + N, aM[i]) == true ? 1 : 0);
	}
	
	
	return 0;
}