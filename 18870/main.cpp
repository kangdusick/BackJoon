#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> datas;
vector<int> uniqueVec;
vector<int>::iterator beginiter;
vector<int>::iterator enditer;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N,X, count = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X;
		datas.push_back(X);
		uniqueVec.push_back(X);
	}
	sort(uniqueVec.begin(), uniqueVec.end());
	uniqueVec.erase(unique(uniqueVec.begin(), uniqueVec.end()),uniqueVec.end());
	beginiter = uniqueVec.begin();
	enditer = uniqueVec.end();
	for (int i = 0; i < N; i++)
	{
		cout<< lower_bound(beginiter, enditer, datas[i])- beginiter <<" ";
	}
	cout << endl;
	return 0;
}