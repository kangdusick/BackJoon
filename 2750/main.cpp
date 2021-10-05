#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int i;
	cin >> N;
	int* data = new int[N];
	for (i = 0; i < N; i++)
	{
		cin >> data[i];
	}
	sort(data, data + N);
	for (i = 0; i < N; i++)
	{
		cout << data[i] << "\n";
	}
	return 0;
}