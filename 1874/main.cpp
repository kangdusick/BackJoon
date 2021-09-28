#include <iostream>
#include <stack>

using namespace std;


int main()
{
	stack<int> data;
	int n = 0;
	int i = 0;
	int num = 1;
	cin >> n;
	int* sol = new int[n];
	char* pm = new char[n*2];
	int pmIndex = 0;
	for (i = 0; i < n; i++)
	{
		cin >> sol[i];
	}
	i = 0;
	while (num<=n)
	{
		data.push(num);
		pm[pmIndex] = '+';
		pmIndex++;
		num++;
		while (data.top() == sol[i])
		{
			data.pop();
			pm[pmIndex] = '-';
			pmIndex++;
			i++;
			if (pmIndex == n * 2||data.size()==0)
				break;
		} 
	}
	if (pmIndex == n * 2)
	{
		for (i = 0; i < pmIndex; i++)
		{
			printf("%c\n", pm[i]);
		}
	}
	else
	{
		printf("NO");
	}
	

	return 0;
}