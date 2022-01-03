#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> gragh[501]; //0: �ǹ����µ� �ɸ��� �ð� 1,2,3... ����ž��ϴ� �ǹ� ��ȣ
bool check[501]; //check�� true�� �������� �� �Ϸ�Ȱ�. �ǹ� �������ִ�.
int Time[501]; //����ǹ� �ð� ����+�ڽ� ���µ� �ɸ��� �ð�
void CalTime(int num)
{
	if (check[num] == true)
	{
		return;
	}
	int graghSize = gragh[num].size();
	if (graghSize == 1)
	{
		check[num] = true;
		Time[num] = gragh[num][0];
	}
	else
	{
		int maxTime = -1;
		for (int i = 1; i < graghSize; i++)
		{
			if (check[gragh[num][i]] == false)
			{
				CalTime(gragh[num][i]);
			}
			if (Time[gragh[num][i]] > maxTime)
			{
				maxTime = Time[gragh[num][i]];
			}
		}
		Time[num] = gragh[num][0] + maxTime;
		check[num] = true;
	}

	
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int input;
	for (int i = 1; i <= N; i++)
	{
		while (true)
		{
			cin >> input;
			if (input == -1)
			{
				break;
			}
			gragh[i].push_back(input);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		CalTime(i);
	}
	for (int i = 1; i <= N; i++)
	{
		cout << Time[i] << "\n";
	}
	cout << "\n";
	return 0;
}