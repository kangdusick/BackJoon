#include <iostream>
#include <vector>
using namespace std;
int N, S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> S;
	vector<int> nums(N);
	int Sum = 0;
	int before = 0;
	bool allSame = false;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		Sum += nums[i];
	}
	int iter1 = 0;
	int iter2 = N - 1;
	if (Sum < S)
	{
		cout << 0;
		return 0;
	}
	before = Sum;
	while (true)
	{
		if (before >= S && Sum < S || iter1 >= iter2)
		{
			break;
		}
		int sameCount = 0;
		int iter11;
		int iter22;
		while (true)
		{
			if (!allSame)
			{
				iter11 = iter1 + sameCount;
				iter22 = iter2 - sameCount;
				if (nums[iter11] < nums[iter22])
				{
					before = Sum;
					Sum -= nums[iter1];
					iter1++;
					break;
				}
				else if (nums[iter11] > nums[iter22])
				{
					before = Sum;
					Sum -= nums[iter2];
					iter2--;
					break;
				}
				else
				{
					if (iter11 >= iter22)
					{
						allSame = true;
						break;
					}
					sameCount++;
				}
			}
			else
			{
				if (nums[iter1] < nums[iter2])
				{
					before = Sum;
					Sum -= nums[iter1];
					iter1++;
					break;
				}
				else
				{
					before = Sum;
					Sum -= nums[iter2];
					iter2--;
					break;
				}
			}
			
		}
	}
	if (iter2 == iter1)
	{
		cout << 1 << "\n";
	}
	else
	{
		cout << iter2 - iter1 + 2 << "\n";
	}
	return 0;
}
