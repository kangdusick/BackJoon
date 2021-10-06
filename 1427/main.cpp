#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int data[10] = { 0, };
	while (N>=1)
	{
		int a = N % 10;
		data[a]++;
		N /= 10;
	}
	for (int i = 9; i >= 0; i--)
	{
		while (data[i] > 0)
		{
			cout << i;
			data[i]--;
		} 
	}
	
	
	return 0;
}