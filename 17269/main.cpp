#include <iostream>
#include <vector>
using namespace std;
int nums[26] = { 3,	2,	1,	2,	4,	3,	1,	3,	1,	1,	3,	1,	3,	2,	1,	2,	2,	2,	1,	2,	1,	1,	1,	2,	2,	1, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N[2];//N[0] A사이즈 N[1] B사이즈
	string A[2];
	cin >> N[0] >> N[1];
	cin >> A[0] >> A[1];
	vector<int> nameToString[2];
	int minIndex = N[0] > N[1] ? 1 : 0; //두개의 이름중 더 짧은것의 인덱스
	int maxIndex = 1 - minIndex;
	int Size = N[0] + N[1]-2;
	int index = 0;
	int beforindex = 1;
	for (int i = 0; i < N[minIndex]; i++)
	{
		nameToString[1].push_back(nums[A[0][i]-65]);
		nameToString[1].push_back(nums[A[1][i] - 65]);
	}
	for (int i = N[minIndex]; i < N[maxIndex]; i++)
	{
		nameToString[1].push_back(nums[A[maxIndex][i] - 65]);
	}
	for (int i = 0; i < Size; i++)
	{
		int size2 = nameToString[beforindex].size()-1;
		for (int j = 0; j < size2; j++)
		{
			nameToString[index].push_back((nameToString[beforindex][j] + nameToString[beforindex][j + 1])%10);
		}
		nameToString[beforindex].clear();
		index = 1 - index;
		beforindex = 1 - beforindex;
	}
	if (nameToString[beforindex][0] != 0)
	{
		cout<<nameToString[beforindex][0];
	}
	cout<< nameToString[beforindex][1]<<"%";
	return 0;
}