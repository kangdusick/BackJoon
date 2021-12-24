#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
int N,Q,a,b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	vector<bitset<2000>> friends(N);
	string nums;
	for (int i = 0; i < N; i++)
	{
		cin >> nums;
		for (int j = 0; j < N; j++)
		{
			if (nums[j] == '0')
			{
				friends[i][j] =  0;
			}
			else
			{
				friends[i][j] = 1;
			}
		}
	}
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		cin >> a >> b;
		cout<< (friends[a - 1] & friends[b - 1]).count()<<"\n";
	}

	return 0;
}