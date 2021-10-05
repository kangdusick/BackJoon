#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int testcase;
	int F;
	int i;
	int j;
	int networkCount1;
	int networkCount2;
	string name1;
	string name2;
	vector<int> answer;
	cin >> testcase;
	for (i = 0; i < testcase; i++)
	{
		map<string, string> network;
		map<string, int> networkCount;
		map< string, vector<string>> netwrokVector;
		cin >> F;
		for (j = 0; j < F; j++)
		{
			cin >> name1;
			cin >> name2;
			networkCount1 = network[name1].size();
			networkCount2 = network[name2].size();

			if (name1 == name2)
			{
				if (networkCount1 == 0)
				{
					network[name1] = name1;
					netwrokVector[name1].push_back(name1);
					networkCount[name1] = 1;
					answer.push_back(1);
				}
				else
				{
					answer.push_back(networkCount[network[name1]]);
				}
				continue;
			}

			if (networkCount1 == 0&&networkCount2 ==0)
			{
				network[name1] = name1;
				network[name2] = name1;
				netwrokVector[name1].push_back(name1);
				netwrokVector[name1].push_back(name2);
				networkCount[name1] = 2;
				answer.push_back(2);
			}
			else if (networkCount1 == 0 && networkCount2 != 0)
			{
				network[name1] = network[name2];
				networkCount[network[name2]]++;
				netwrokVector[network[name2]].push_back(name1);
				answer.push_back(networkCount[network[name2]]);
			}
			else if (networkCount1 != 0 && networkCount2 == 0)
			{
				network[name2] = network[name1];
				networkCount[network[name1]]++;
				netwrokVector[network[name1]].push_back(name2);
				answer.push_back(networkCount[network[name1]]);
			}
			else if (networkCount1 != 0 && networkCount2 != 0 && network[name1]!=network[name2])
			{
				if (networkCount[network[name1]] > networkCount[network[name2]]) //name2를 name1에 합치고 삭제하기.
				{
					string temp = network[name2];
					int ii = netwrokVector[network[name2]].size();
					networkCount[network[name1]] += networkCount[network[name2]];
					for (int jj = 0; jj < ii; jj++)
					{
						network[netwrokVector[temp][jj]] = network[name1];
						netwrokVector[network[name1]].push_back(netwrokVector[temp][jj]);
					}
					networkCount.erase(temp);
					netwrokVector.erase(temp);
					answer.push_back(networkCount[network[name1]]);
				}
				else
				{
					string temp = network[name1];
					int ii = netwrokVector[network[name1]].size();
					networkCount[network[name2]] += networkCount[network[name1]];
					for (int jj = 0; jj < ii; jj++)
					{
						network[netwrokVector[temp][jj]] = network[name2];
						netwrokVector[network[name2]].push_back(netwrokVector[temp][jj]);
					}
					networkCount.erase(temp);
					netwrokVector.erase(temp);
					answer.push_back(networkCount[network[name2]]);
				}
			}
			else
			{
				answer.push_back(networkCount[network[name2]]);
			}
		}
	}
	int kk = answer.size();
	for (i = 0; i < kk; i++)
	{
		printf("%d\n", answer[i]);
	}

	return 0;
}

/*
testcase 
5
3
Fred Barney
Barney Betty
Betty Wilma
3
Fred Barney
Betty Wilma
Barney Betty
5
a b
b c
a d
a e
e a
5
A B
C D
E F
A C
D F
2
A B
C D


1
18
Fred Barney
Barney Betty
Betty Wilma
Fred Barney
Betty Wilma
Barney Betty
a b
b c
a d
a e
e a
A B
C D
E F
A C
D F
A B
C D

1
8
a b
b c
d e
e f
g h
h i
a f
c i


*/