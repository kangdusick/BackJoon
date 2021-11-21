#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
map<string, string> group1; //key: ¸â¹ö val: ±×·ì
map<string, vector<string>> group0; //key: ±×·ì val: ¸â¹ö


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string group;
		string name;
		int member;
		cin >> group;
		cin >> member;
		for (int j = 0; j < member; j++)
		{
			cin >> name;
			group0[group].push_back(name);
			group1[name] = group;
		}
		sort(group0[group].begin(), group0[group].end());
	}
	string question;
	int queNo;
	for (int i = 0; i < M; i++)
	{
		cin >> question >> queNo;
		if (queNo == 0)
		{
			int size = group0[question].size();
			for (int i = 0; i < size; i++)
			{
				cout << group0[question][i]<<"\n";
			}
		}
		else
		{
			cout << group1[question]<<"\n";
		}
	}
	return 0;
}