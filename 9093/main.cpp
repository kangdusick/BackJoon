#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	vector<string> sentence;
	vector<string> sol;
	string inputs;
	getline(cin, inputs);
	for (int i = 0; i < T; i++)
	{
		getline(cin, inputs);
		sentence.push_back(inputs);
	}
	for (int i = 0; i < T; i++)
	{
		int sSize = sentence[i].size();
		string temp;
		string tempSol;
		for (int j = 0; j < sSize; j++)
		{
			if (sentence[i][j] == ' ')
			{
				int kSize = temp.size();
				for (int k = 0; k < kSize; k++)
				{
					tempSol.push_back(temp[kSize-k-1]);
				}
				tempSol.push_back(' ');
				temp.clear();
			}
			else
			{
				temp.push_back(sentence[i][j]);
			}
		}
		int kSize = temp.size();
		for (int k = 0; k < kSize; k++)
		{
			tempSol.push_back(temp[kSize - k - 1]);
		}
		sol.push_back(tempSol);
	}
	for (int i = 0; i < T; i++)
	{
		cout << sol[i] << "\n";
	}
	return 0;
}