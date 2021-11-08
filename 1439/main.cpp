#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string S;
	int zeroCount = 0;
	int oneCount = 0;
	cin >> S;
	int len = S.length();
	char now = S[0];
	int count = 0;
	for (int i = 0; i <= len; i++)
	{
		if (S[i] != now)
		{
			if (now == '0')
			{
				zeroCount++;
			}
			else
			{
				oneCount++;
			}
			now = S[i];
		}
	}
	int sol = zeroCount > oneCount ? oneCount : zeroCount;
	cout << sol;

	return 0;
}