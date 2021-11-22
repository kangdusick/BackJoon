#include <iostream>
using namespace std;
int C[3];
int B[3];
void Pour(int i)
{
	switch (i)
	{
	case 0:
		C[1] += C[0];
		if (B[1] <= C[1])
		{
			C[0] = C[1] - B[1];
			C[1] = B[1];
		}
		else
		{
			C[0] = 0;
		}
		break;
	case 1:
		C[2] += C[1];
		if (B[2] <= C[2])
		{
			C[1] = C[2] - B[2];
			C[2] = B[2];
		}
		else
		{
			C[1] = 0;
		}
		break;
	case 2:
		C[0] += C[2];
		if (B[0] <= C[0])
		{
			C[2] = C[0] - B[0];
			C[0] = B[0];
		}
		else
		{
			C[2] = 0;
		}
		break;
	default:
		break;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> B[i]>>C[i];
	}
	for (int i = 0; i < 100; i++)
	{
		Pour(count);
		count++;
		if (count == 3)
		{
			count = 0;
		}
	}
	cout << C[0] << "\n" << C[1] << "\n" << C[2];
	return 0;
}