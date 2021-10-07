#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	int x;
	int y;
	int i;
	int size;
	int j;
	map<int, vector<int>> xy;
	map<int, vector<int>>::iterator iter;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> x;
		cin >> y;
		xy[x].push_back(y);
	}
	iter = xy.begin();
	size = xy.size();
	int xsize;
	for (i = 0; i < size; i++)
	{
		xsize = (*iter).second.size();
		sort((*iter).second.begin(), (*iter).second.end());
		for (j = 0; j < xsize; j++)
		{
			cout << (*iter).first << " " << (*iter).second[j] << "\n";
		}
		iter++;
	}

	return 0;
}