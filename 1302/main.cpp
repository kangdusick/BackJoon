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
	cin >> N;
	string name;
	int max = 0;
	vector<string> maxs;
	map<string, int> dic;
	for (int i = 0; i < N; i++)
	{
		
		cin >> name;
		dic[name]++;
		if (dic[name] > max)
		{
			maxs.clear();
			maxs.push_back(name);
			max = dic[name];
		}
		else if(dic[name]==max)
		{
			maxs.push_back(name);
		}
	}
	sort(maxs.begin(), maxs.end());
	cout << maxs[0];

	return 0;
}