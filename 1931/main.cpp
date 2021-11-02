#include <iostream>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;
map<int, vector<int>> info;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, S, E;
	int count = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S >> E;
		info[E].push_back(S);
	}
	int infoSize = info.size();
	int beforeNum = 0;
	map<int, vector<int>>::iterator iter = info.begin();
	for (int i = 0; i < infoSize; i++)
	{
		sort(iter->second.begin(), iter->second.end(), greater<int>());
		iter++;
	}

	iter = info.begin();
	for (int i = 0; i < infoSize; i++)
	{
		int jSize = iter->second.size();
		if (jSize == 1)
		{
			if (iter->second[0] >= beforeNum)
			{
				count++;
				beforeNum = iter->first;
			}
		}
		else if (jSize >= 2)
		{
			if (iter->second[0] == iter->first)
			{
				for (int ii = 0; ii < jSize; ii++)
				{
					if (iter->second[ii] == iter->first)
					{
						count++;
					}
					else if (iter->second[ii] >= beforeNum)
					{
						count++;
						break;
					}
					else
					{
						break;
					}

				}
				beforeNum = iter->first;
			}
			else if (iter->second[0] >= beforeNum)
			{
				count++;
				beforeNum = iter->first;
			}
		}

		iter++;
	}
	cout << count;
	return 0;
}

/*
TestCase
2
1 1
0 1
´ä: 2

6
1 1
1 2
2 2
2 3
3 3
4 4
´ä: 6
*/