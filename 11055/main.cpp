#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A[1000];
int N;
int B[1000];
void FindSum(int num)
{
	vector<int> temp;
	for (int i = num; i < N; i++)
	{
		if (A[i] != A[num]&&A[i]>A[num])
		{
			temp.push_back(B[i]);
		}
	}
	if (temp.size() == 0)
	{
		B[num] = A[num];
		return;
	}
	sort(temp.begin(), temp.end(),greater<int>());
	B[num] = temp[0] + A[num];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	for (int i = N - 1; i >= 0; i--)
	{
		FindSum(i);
	}
	sort(B, B + 1000,greater<int>());
	cout << B[0];
		
	return 0;
}