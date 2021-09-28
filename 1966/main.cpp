#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Data
{
public:
	int num;
	bool checked = false;
};

int PrintNum(list<Data> dataList)
{
	
	int answer = 0;
	while (true)
	{
		list<Data>::iterator begin = dataList.begin();
		list<Data>::iterator end;
		list<Data>::iterator iter = begin;
		list<Data>::iterator maxData = begin;
		int size = dataList.size();
		int i = 0;
		for (i = 0; i < size; i++)
		{
			if (iter->num > maxData->num)
			{
				maxData = iter;
			}
			if (i == size - 1)
			{
				end = iter;
			}
			iter++;
		}
		answer++;
		if (maxData->checked == true)
			return answer;

		while (true)
		{
			begin = dataList.begin();
			if (maxData == begin)
			{
				dataList.erase(maxData);
				break;
			}
			else
			{
				dataList.push_back(*begin);
				dataList.pop_front();
			}
		}
		
	}
}

int main()
{
	int testCase = 0;
	int i = 0;
	int j = 0;
	cin >> testCase;
	int* N = new int[testCase];
	int* M = new int[testCase];
	int inputdata = 0;

	list<Data>* dataList = new list<Data>[testCase];
	for (i = 0; i < testCase; i++)
	{
		cin >> N[i];
		cin >> M[i];
		for (j = 0; j < N[i]; j++)
		{
			cin >> inputdata;
			if (j != M[i])
			{
				Data InputData = { inputdata,false };
				dataList[i].push_back(InputData);
			}
			else
			{
				Data InputData = { inputdata,true };
				dataList[i].push_back(InputData);
			}
		}
	}
	for (i = 0; i < testCase; i++)
	{
		printf("%d\n",PrintNum(dataList[i]));
	}
	

	return 0;
}