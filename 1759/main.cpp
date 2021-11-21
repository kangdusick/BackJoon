#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string consonant;
string vowel;
vector<string> solutions;
int vowelSize;
int consonantSize;
int vowelindex[5];
int consonantindex[22];
int L, C;

void MakeConsonant(int n, int nowindex)
{
	if (nowindex == 0)
	{
		for (int i = 0; i < consonantSize; i++)
		{
			consonantindex[nowindex] = i;
			MakeConsonant(n, nowindex + 1);
		}
	}
	else
	{
		for (int i = consonantindex[nowindex-1] + 1; i < consonantSize; i++)
		{
			consonantindex[nowindex] = i;
			if (nowindex + 1 == n)
			{
				string newSol;
				for (int i = 0; i < L - n; i++)
				{
					newSol.push_back(vowel[vowelindex[i]]);
				}
				for (int i = 0; i < n; i++)
				{
					newSol.push_back(consonant[consonantindex[i]]);
				}
				sort(newSol.begin(), newSol.end());
				solutions.push_back(newSol);
			}
			else
			{
				MakeConsonant(n, nowindex + 1);
			}
		}

	}
}
void Makevowel(int n, int nowindex) //n개의 vowel을 선택하는 world를 만든다.
{
	if (nowindex == 0)
	{
		for (int i = 0; i < vowelSize; i++)
		{
			vowelindex[nowindex] = i;
			if (nowindex + 1 == n)
			{
				MakeConsonant(L - n, 0);
			}
			else
			{
				Makevowel(n, nowindex + 1);

			}
		}
	}
	else
	{
		for (int i = vowelindex[nowindex-1]+1; i < vowelSize; i++)
		{
			vowelindex[nowindex] = i;
			if (nowindex+1 == n)
			{
				MakeConsonant(L-n,0);
			}
			else
			{
				Makevowel(n, nowindex+1);

			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char c;
	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> c;
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			vowel.push_back(c);
		else
		{
			consonant.push_back(c);
		}
	}
	vowelSize = vowel.size();
	consonantSize = consonant.size();
	if (vowelSize < 1 || consonantSize < 2)
	{
		return 0;
	}

	for (int i = 1; i <= vowelSize; i++)
	{
		Makevowel(i, 0);
	}
	sort(solutions.begin(), solutions.end());
	int solsize = solutions.size();
	for (int i = 0; i < solsize; i++)
	{
		cout << solutions[i] << "\n";
	}
	return 0;
}