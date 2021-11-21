#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int* num = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}
	sort(num, num + N);
	cout << num[N - 1] - num[0];
	return 0;
}