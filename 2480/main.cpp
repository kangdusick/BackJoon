#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c[3];
	cin >> c[0] >> c[1] >> c[2];
	sort(c, c + 3);
	if (c[0]==c[2])
	{
		cout << 10000 + c[0] * 1000;
	}
	else if (c[0] != c[1] && c[1] != c[2] && c[2] != c[0])
	{
		cout << c[2] * 100;
	}
	else
	{
		if (c[0] == c[1])
		{

			cout << 1000 + c[0] * 100;
		}
		else if (c[1] == c[2])
		{
			cout << 1000 + c[1] * 100;
		}
		else
		{
			cout << 1000 + c[2] * 100;
		}
	}
	return 0;
}