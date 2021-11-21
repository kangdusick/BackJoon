#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	int* A = new int[N];
	int* B = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}
	A[0] = B[0];
	cout << A[0] << " ";
	for (int i = 1; i < N; i++)
	{
		A[i] = (i + 1) * B[i] - i * B[i - 1];
		cout << A[i] << " ";
	}
	return 0;
}