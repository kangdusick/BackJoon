#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int* trophys;
	int i;
	cin >> N;
	trophys = new int[N];
	int maxheight = 0;
	int leftCount = 0;
	int rightCount = 0;
	for (i = 0; i < N; i++)
	{
		cin >> trophys[i];
	}
	for (i = 0; i < N; i++)
	{
		if (trophys[i] > maxheight)
		{
			leftCount++;
			maxheight = trophys[i];
		}
	}
	maxheight = 0;
	for (i = N - 1; i >= 0; i--)
	{
		if (trophys[i] > maxheight)
		{
			rightCount++;
			maxheight = trophys[i];
		}
	}
	cout << leftCount << "\n" << rightCount;
	return 0;
}