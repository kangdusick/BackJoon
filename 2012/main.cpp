#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	long long int satisfy = 0;
	cin >> N;
	int* datas = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> datas[i];
	}
	sort(datas, datas + N);
	for (int i = 0; i < N; i++)
	{
		int a = i + 1 - datas[i];
		a = a > 0 ? a : -a;
		satisfy += a;
	}
	cout << satisfy;
	return 0;
}