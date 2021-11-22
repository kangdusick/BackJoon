#include <iostream>
#include <vector>
using namespace std;
vector<bool> s140;
vector<bool> s100;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, L, K;
	int sub1, sub2;
	cin >> N >> L >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> sub1 >> sub2;
		if (sub2 <= L)
		{
			s140.push_back(true);
		}
		else if(sub1<=L)
		{
			s100.push_back(true);
		}
	}
	int s140size = s140.size();
	int s100size = s100.size();
	if (K -s140size <= 0)
	{
		cout << K * 140;
	}
	else if(K-s140size-s100size<=0)
	{
		cout << s140size * 140 + (K - s140size) * 100;
	}
	else
	{
		cout << s140size * 140 + s100size * 100;
	}
	return 0;
}