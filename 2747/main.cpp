#include <iostream>
using namespace std;

int* datas = new int[46];

int pivo(int n)
{
	if (datas[n] >= 0)
	{
		return datas[n];
	}
	return datas[n] = pivo(n - 1) + pivo(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	for (int i = 0; i < 46; i++)
	{
		datas[i] = -1;
	}
	cin >> N;
	datas[0] = 0;
	datas[1] = 1;
	cout << pivo(N)<<"\n";
	return 0;
}