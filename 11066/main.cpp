#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int T;
int K;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	vector<int>* Tcase;
	list<int> buffers;
	list<int>::iterator iter;
	vector<vector<int>> buffer;
	int inputs;
	Tcase = new vector<int>[T];
	bool init = false;
	for (int i = 0; i < T; i++)
	{
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			cin >> inputs;
			Tcase[i].push_back(inputs);
		}
	}
	iter = buffers.begin();
	iter++;
	buffers.erase(iter);
	buffers.insert(iter,5);
	for (int i = 0; i < T; i++)
	{
		if (!init)
		{
			buffer.push_back(Tcase[i]);
			init = true;
		}
		if (buffer.size() == 1 && buffer[0].size()==1)
		{
			init = false;
			continue;
		}
	}
	return 0;
}