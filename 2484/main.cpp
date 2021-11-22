#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, C;
	cin >> N;
	map<int, int> dice; //key: �ֻ��� ����, val: key�� ���� Ƚ��
	map<int, int>::iterator iter;
	vector<int>sol;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> C;
			dice[C]++;
		}
		int diceSize = dice.size();
		switch (diceSize)
		{
		case 1: //4���� �� ����
			sol.push_back(50000+dice.begin()->first*5000);
			break;
		case 2: // 3���� ���ų� 2���� ������ 2���̴�.
			iter = dice.begin();
			while (true)
			{
				if (iter->second == 3)
				{
					sol.push_back(10000 + iter->first * 1000);
					break;
				}
				else if (iter->second == 2)
				{
					int money = 2000 + iter->first * 500;
					iter++;
					money += iter->first * 500;
					sol.push_back(money);
					break;
				}
				iter++;
			}
			break;
		case 3: // 2���� ����
			iter = dice.begin();
			while (true)
			{
				if (iter->second == 2)
				{
					sol.push_back(1000 + iter->first * 100);
					break;
				}
				iter++;
			}
			break;
		case 4: //4���� �� �ٸ�
			iter = dice.end();
			iter--;
			sol.push_back(iter->first * 100);
			break;
		default:
			break;
		}
		dice.clear();
	}
	sort(sol.begin(), sol.end());
	cout << sol[N - 1];
	return 0;
}