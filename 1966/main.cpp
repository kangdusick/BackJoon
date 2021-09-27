#include <iostream>
#include <queue>


using namespace std;


int main()
{
	int testcase = 0;
	scanf("%d", &testcase);
	int N;
	int M;
	int data;
	int inputdata = 0;
	int i = 0;
	int j = 0;
	int* answer = new int[testcase];
	for (i = 0; i < testcase; i++)
	{
		scanf("%d", &N);
		scanf("%d", &M);
		priority_queue<int> pq;
		for (j = 0; j < N; j++)
		{
			scanf("%d", &data);
			pq.push(data);
		}
		pq.
	}
	
	return 0;
}