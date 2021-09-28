#include <list>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	int i = 0;
	int j = 0;
	cin >> n;
	list<char>* passWard = new list<char>[n];
	string* log = new string[n];
	for (i = 0; i < n; i++)
	{
		cin >> log[i];
	}
	for (i = 0; i < n; i++)
	{
		list<char>::iterator iter;
		vector<list<char>::iterator> iterList;
		int logSize = log[i].size();
		int nowCurser = 0;
		int k = 0;
		int iterListIndex = 0;
		for (j = 0; j < logSize; j++)
		{
			switch (log[i][j])
			{
			case '<':
				if(nowCurser>0)
					nowCurser--;
				break;
			case '>':
				if(nowCurser<passWard[i].size())
					nowCurser++;
				break;
			case '-':
				if (passWard[i].size() == 0)
				{
					break;
				}
				nowCurser--;
				iter = passWard[i].begin();
				for (k = 0; k < nowCurser; k++)
				{
					iter++;
				}
				passWard[i].erase(iter);
				break;
			default:
				if (nowCurser == 0)
				{
					iter = passWard[i].begin();
				}
				else
				{
					iter = iterList[nowCurser];
				}
				passWard[i].insert(iter, log[i][j]);
				iterList.push_back(iter);
				nowCurser++;
				break;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		list<char>::iterator iter = passWard[i].begin();
		int size = passWard[i].size();
		for (j = 0; j < size; j++)
		{
			printf("%c", *iter);
			iter++;
		}
		printf("\n");
	}

	return 0;
}