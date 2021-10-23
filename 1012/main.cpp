#include <iostream>
#include <map>
#include <vector>
using namespace std;

class NNode
{
public:
	int X;
	int Y;
};
map<int, map<int, int>> gragh;
//  XÁÂÇ¥    YÁÂÇ¥, network
map<int, vector<NNode*>> netWrok;
//  net,     xÁÂÇ¥ YÁÂÇ¥
void unionNet(int x1, int y1, int x2, int y2)
{
	int net1 = gragh[x1][y1];
	int net2 = gragh[x2][y2];
	int netSize1 = netWrok[net1].size();
	int netSize2 = netWrok[net2].size();
	if (net1 == net2)
	{
		return;
	}
	if (netSize1 >= netSize2)
	{
		for (int i = 0; i < netSize2; i++)
		{
			netWrok[net1].push_back(netWrok[net2][i]);
			gragh[netWrok[net2][i]->X][netWrok[net2][i]->Y] = net1;
		}
		netWrok.erase(net2);
	}
	else
	{
		for (int i = 0; i < netSize1; i++)
		{
			netWrok[net2].push_back(netWrok[net1][i]);
			gragh[netWrok[net1][i]->X][netWrok[net1][i]->Y] = net2;
		}
		netWrok.erase(net1);
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, M, N, K,X,Y,net = 1;
	vector<int> solution;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> M >> N>>K;
		for (int j = 0; j < K; j++)
		{
			cin >> X >> Y;
			if (X >= M || Y >= N || X < 0 || Y < 0)
				continue;
			NNode* num = new NNode;
			num->X = X;
			num->Y = Y;
			gragh[X][Y] = net;
			netWrok[net].push_back(num);
			net++;
			if (gragh[X + 1][Y]!=0)
			{
				unionNet(X, Y, X + 1, Y);
			}
			else
			{
				gragh[X + 1].erase(Y);
				if (gragh[X + 1].size() == 0)
				{
					gragh.erase(X + 1);
				}
			}
			if (gragh[X - 1][Y] != 0)
			{
				unionNet(X, Y, X - 1, Y);
			}
			else
			{
				gragh[X - 1].erase(Y);
				if (gragh[X - 1].size() == 0)
				{
					gragh.erase(X - 1);
				}
			}
			if (gragh[X][Y+1] != 0)
			{
				unionNet(X, Y, X, Y+1);
			}
			else
			{
				gragh[X].erase(Y+1);
				if (gragh[X].size() == 0)
				{
					gragh.erase(X);
				}
			}
			if (gragh[X][Y-1] != 0)
			{
				unionNet(X, Y, X, Y-1);
			}
			else
			{
				gragh[X].erase(Y-1);
				if (gragh[X].size() == 0)
				{
					gragh.erase(X);
				}
			}
		}
		solution.push_back(netWrok.size());
		gragh.clear();
		netWrok.clear();
	}
	int solSize = solution.size();
	for (int i = 0; i < solSize; i++)
	{
		cout << solution[i]<<endl;
	}
	return 0;
}

/*
2
3 2 2
0 1
2 1
3 3 1
0 0
´ä: 2 1

2
2 2 1
0 0
2 2 1
1 1
´ä: 1 1

1
4 4 8
0 0
1 0
2 0
2 1
2 2
2 3
3 2
3 3
´ä: 1

*/