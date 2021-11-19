#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void calLenghth(vector<int> vec, int k)
{

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie();
	vector<int> plus;
	vector<int> minus;
	bool isPlusBigger = false;
	int N, M,x;
	int solution = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x > 0)
		{
			plus.push_back(x);
		}
		else
		{
			minus.push_back(-x);
		}
	}
	sort(plus.begin(), plus.end(),greater<int>());
	sort(minus.begin(), minus.end(), greater<int>());
	int psize =plus.size();
	int msize =minus.size();
	if (psize == 0 && msize == 0)
	{
	}
	else if (msize == 0)
	{
		for (int i = 0; i < psize; i += M)
		{
			if (i == 0)
			{
				solution += plus[i];
			}
			else
			{
				solution += plus[i] * 2;
			}
		}
	}
	else if (psize == 0)
	{
		for (int i = 0; i < msize; i += M)
		{
			if (i == 0)
			{
				solution += minus[i];
			}
			else
			{
				solution += minus[i] * 2;
			}
		}
	}
	else
	{
		if (plus[0] >= minus[0])
		{
			for (int i = 0; i < msize; i+=M)
			{
				solution += minus[i] * 2;
			}
			for (int i = 0; i < psize; i += M)
			{
				if (i == 0)
				{
					solution += plus[i];
				}
				else
				{
					solution += plus[i]*2;
				}
			}
		}
		else
		{
			for (int i = 0; i < psize; i += M)
			{
				solution += plus[i] * 2;
			}
			for (int i = 0; i < msize; i += M)
			{
				if (i == 0)
				{
					solution += minus[i];
				}
				else
				{
					solution += minus[i] * 2;
				}
			}
		}
	}
	cout << solution;
	return 0;
}