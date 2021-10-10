#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i = 0;
	int count = N;
	int time = 0;
	while (count != 0)
	{
		i++;
		if (count < i)
		{
			i = 0;
			continue;
		}
		time++;
		count -= i;
	}
	cout << time;
	return 0;
}