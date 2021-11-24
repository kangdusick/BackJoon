#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int NCount = 1;
	int Count = 0;
	cin >> N;
	if (N == 0)
	{
		cout << 1;
		return 0;
	}
	while (N/NCount>=1)
	{
		NCount = NCount * 10 + 1;
		Count++;
	}
	cout << Count;
	return 0;
}