#include <iostream>
using namespace std;
int D;

//0:�������а�
//1:�����
//2:�̷���
//3:�žӰ�
//4:�Ѱ�������
//5������
//6�л�ȸ��
//7�������а�
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int* DP;
	long long int* tempDP;
	cin >> D;
	DP = new long long int[8];
	tempDP = new long long int[8];
	for (int i = 0; i < 8; i++)
	{
		DP[i] = 0;
	}
	DP[0] = 1;
	for (int i = 0; i < D; i++)
	{
		for (int i = 0; i < 8; i++)
		{
			tempDP[i] = DP[i];
		}
		for (int i = 0; i < 8; i++)
		{
			DP[i] = 0;
		}
		DP[0] = (tempDP[1] + tempDP[2]) % 1000000007;
		DP[1] = (tempDP[0] + tempDP[2] + tempDP[3]) % 1000000007;
		DP[2] = (tempDP[0] + tempDP[1] + tempDP[3] + tempDP[4]) % 1000000007;
		DP[3] = (tempDP[1] + tempDP[2] + tempDP[4] + tempDP[5]) % 1000000007;
		DP[4] = (tempDP[2] + tempDP[3] + tempDP[5] + tempDP[7]) % 1000000007;
		DP[5] = (tempDP[3] + tempDP[4] + tempDP[6]) % 1000000007;
		DP[6] = (tempDP[5] + tempDP[7]) % 1000000007;
		DP[7] = (tempDP[6] + tempDP[4]) % 1000000007;
	}
	cout << DP[0];
	return 0;
}

