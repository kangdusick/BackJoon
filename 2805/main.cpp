#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> trees;
int treeSize;
long long int CalHeight(int Cutter)
{
	long long int cal = 0;
	for (int i = 0; i < treeSize; i++)
	{
		long long int a =trees[i] - Cutter;
		if (a > 0)
		{
			cal +=a;
		}
	}
	return cal;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,M;
	int input;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		trees.push_back(input);
	}
	sort(trees.begin(),trees.end());
	treeSize = trees.size();
	int min = 0; 
	int max = trees[treeSize - 1];
	int middle = (min + max) / 2; //Ŀ�ͳ��� ����. ���������� cal�� �۾����� ���������� cal�� Ŀ����. cal�� M���� ũ�ų� ���� middle�� �ִ��� ã�ƾ��Ѵ�.
	while (true)
	{
		if (min > max)
		{
			break;
		}
		long long int cal = CalHeight(middle);
		if (cal < M)
		{
			max = middle-1;
			middle = (min + max) / 2;
		}
		else
		{
			min = middle+1;
			middle = (min + max) / 2;
		}
	}
	cout << middle;
	return 0;
}