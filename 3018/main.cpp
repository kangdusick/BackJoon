#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,E;
long long int Person[101];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> E;
	int people;
	int songIndex = 0;
	long long int sum=0;
	for (int i = 0; i < E; i++)
	{
		cin >> people;
		vector<int> nums(people);
		for (int j = 0; j < people; j++)
		{
			cin >> nums[j];
		}
		sort(nums.begin(), nums.end());
		if (nums[0] == 1)
		{
			long long int tempSong = 1LL<<songIndex;
			for (int i = 0; i < people; i++)
			{
				Person[nums[i]] = Person[nums[i]] | tempSong;
			}
			songIndex++;
		}
		else
		{
			sum = (1LL<<songIndex)-1LL;
			for (int i = 0; i < people; i++)
			{
				Person[nums[i]] = sum;
			}
		}
	}
	sum = (1LL << songIndex) - 1LL;
	for (int i = 1; i <= N; i++)
	{
		if (Person[i] == sum)
		{
			cout << i<<"\n";
		}
	}
	return 0;
}