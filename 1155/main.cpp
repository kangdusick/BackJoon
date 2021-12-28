#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int N;
vector<int> inputs(6);
stack<int> ABC[3];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int lastDisk = 0;
	long long int moveCount = 0;
	string temp = "";
	for (int i = N; i >= 1; i--)
	{
		ABC[0].push(i);
	}
	for (int i = 0; i < 6; i++)
	{
		cin >> temp;
		if (temp == "AB")
		{
			inputs[i] = 1;
		}
		else if (temp == "BA")
		{
			inputs[i] = 2;
		}
		else if (temp == "CA")
		{
			inputs[i] = 3;
		}
		else if (temp == "BC")
		{
			inputs[i] = 4;
		}
		else if (temp == "CB")
		{
			inputs[i] = 5;
		}
		else if (temp == "AC")
		{
			inputs[i] = 6;
		}
		temp.clear();
	}

	while (true)
	{
		if (ABC[1].size() == N || ABC[2].size() == N)
		{
			break;
		}
		for (int i = 0; i < 6; i++)
		{
			
			switch (inputs[i])
			{
			case 1: //AB
				if (ABC[0].top() != lastDisk&&ABC[0].size()!=0)
				{
					ABC[1].push(ABC[0].top());
					ABC[0].pop();
					lastDisk = ABC[1].top();
					moveCount++;
				}
				break;
			case 2: //BA
				if (ABC[1].top() != lastDisk&&ABC[1].size() != 0)
				{
					ABC[0].push(ABC[1].top());
					ABC[1].pop();
					lastDisk = ABC[0].top();
					moveCount++;
				}
				break;
			case 3://CA
				if (ABC[2].top() != lastDisk&& ABC[2].size() != 0)
				{
					ABC[0].push(ABC[2].top());
					ABC[2].pop();
					lastDisk = ABC[0].top();
					moveCount++;
				}
				break;
			case 4://BC
				if (ABC[1].top() != lastDisk&& ABC[1].size() != 0)
				{
					ABC[2].push(ABC[1].top());
					ABC[1].pop();
					lastDisk = ABC[1].top();
					moveCount++;
				}
				break;
			case 5: //CB
				if (ABC[2].top() != lastDisk&& ABC[2].size() != 0)
				{
					ABC[1].push(ABC[2].top());
					ABC[2].pop();
					lastDisk = ABC[1].top();
					moveCount++;
				}
				break;
			case 6://AC
				if (ABC[0].top() != lastDisk&& ABC[0].size() != 0)
				{
					ABC[2].push(ABC[0].top());
					ABC[0].pop();
					lastDisk = ABC[2].top();
					moveCount++;
				}
				break;
			}
		}
	}
	cout << moveCount<<"\n";
	return 0;
}