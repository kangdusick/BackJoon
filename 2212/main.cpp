#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,K;
	int sol = 0;
	cin >> N >> K;
	int* datas = new int[N];
	int* space = new int[N - 1];
	for (int i = 0; i < N; i++)
	{
		cin >> datas[i];
	}
	sort(datas, datas + N);
	for (int i = 0; i < N - 1; i++)
	{
		space[i] = datas[i + 1] - datas[i];
	}
	sort(space, space + N - 1, greater<int>());
	for (int i = K - 1; i < N - 1; i++)
	{
		sol += space[i];
	}
	cout << sol;
	return 0;
}