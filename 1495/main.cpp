#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool>* datalist;
map<int, bool>::iterator iter;
map<int, bool>::iterator enditer;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	bool isfalse = false;
	int N, S, M;
	cin >> N >> S >> M;
	int* V = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> V[i];
	}
	datalist = new map<int, bool>;
	(*datalist)[S] = true;
	for (int i = 0; i < N; i++)
	{
		int* Sound = new int[1001];
		map<int, bool>* tempData = new map<int, bool>;
		iter = (*datalist).begin();
		enditer = (*datalist).end();
		while (iter != enditer)
		{
			int a = iter->first;
			if (a - V[i] >= 0)
				(*tempData)[a - V[i]] = true;
			if (a + V[i] <= M)
				(*tempData)[a + V[i]] = true;

			iter++;
		}
		if ((*tempData).size() == 0)
		{
			cout << -1;
			isfalse = true;
			break;
		}
		delete datalist;
		datalist = tempData;
	}
	if (isfalse == false)
	{
		iter = (*datalist).end();
		iter--;
		cout << iter->first;
	}

	return 0;
}
