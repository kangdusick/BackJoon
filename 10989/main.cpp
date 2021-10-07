#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int* datas = new int[10001];
	int i;
	int data;
	for (i = 0; i < 10001; i++)
	{
		datas[i] = 0;
	}

	for (i = 0; i < N; i++)
	{
		cin >> data;
		datas[data]++;
	}

	for (i = 0; i < 10001; i++)
	{
		while (datas[i] > 0)
		{
			cout << i << "\n";
			datas[i]--;
		}
	}
	return 0;
}