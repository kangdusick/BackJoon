#include <iostream>

using namespace std;

int lleft;
int moneycount = 0;

void CountDown(int n)
{
	while (lleft >= n)
	{
		lleft -= n;
		moneycount++;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	lleft = 1000 - N;
	CountDown(500);
	CountDown(100);
	CountDown(50);
	CountDown(10);
	CountDown(5);
	CountDown(1);
	cout << moneycount;
	return 0;
}