#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	sort(lottos.begin(), lottos.end());
	sort(win_nums.begin(), win_nums.end());
	int zeroCount = 0;
	int sameCount = 0;
	for (int i = 0; i < 6; i++)
	{
		if (lottos[i] == 0)
			zeroCount++;
	}
	for (int i = zeroCount; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (lottos[i] == win_nums[j])
				sameCount++;
		}
	}
	int rank1 = 7-sameCount<6 ? 7 - sameCount:6;
	int rank2 = 7 - (sameCount + zeroCount)<6? 7 - (sameCount + zeroCount): 6;
	answer.push_back(rank2);
	answer.push_back(rank1);
	return answer;
}

int main()
{
	vector<int> lottos = { 0, 0, 0, 0, 0, 0 };
	vector<int> win_nums = { 31, 10, 45, 1, 6, 19 };
	vector<int> sol = solution(lottos, win_nums);
	return 0;
}