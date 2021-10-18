#include <iostream>
#include <vector>
#include <map>
using namespace std;
int dynamic[1000001];
int setDynamic(int num)
{
	if (num == 0)
	{
		return 0;
	}
	if (dynamic[num] != 0)
	{
		return dynamic[num];
	}
	else
	{
		if (num == 1)
		{
			dynamic[1] = 1;
			return dynamic[1];
		}
		if (num == 2)
		{
			dynamic[2] = 2;
			return 2;
		}
		return dynamic[num] = (setDynamic(num - 1) + setDynamic(num - 2))% 15746;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int divide1000 = N / 1000;
	if (divide1000 >= 1)
	{
		for (int i = 0; i * divide1000 <= N; i++)
		{
			if (1000 * i > 1000000)
			{
				break;
			}
			setDynamic(1000 * i);
		}
	}
	
	cout << setDynamic(N);

	return 0;
}
