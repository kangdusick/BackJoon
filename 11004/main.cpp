#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	int* x;
	cin >> N >> K;
	x = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> x[i];
	}
	sort(x, x + N);
	cout << x[K - 1];
	return 0;
}
