#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;
map<int,vector<string>> solutions; //key = N, value = N�� �ش��ϴ� ���� ����Ʈ
void makeSolution(int N,string num,int data) 
{
	char n = (char)data;
	if (data == N)
	{
		num.push_back(data);
		stack<int> numStack;
		int size = num.size();
		int temp;
		int i;
		for (i = 0; i < size; i += 2)
		{
			numStack.push(num[i]);
			if (i != 0)
			{
				if (num[i - 1] == ' ')
				{
					numStack.pop();
				}
			}
			if (i + 1 != size)
			{
				if (num[i + 1] == ' ') // ��ĭ�� ���� �� ������ �ֻ�ܿ� �ִ� ���ڸ� ���� 10�� ���ϰ� ���� ���ڸ� ����.
				{
					temp = numStack.top() * 10 + num[i + 2];
					numStack.pop();
					numStack.push(temp);
				}
			}
		}
		int stacksize = numStack.size();
		int* datas = new int[stacksize];
		for (i = stacksize - 1; i >= 0; i--)
		{
			datas[i] = numStack.top();
			numStack.pop();
		}
		int j = 1;
		int sol = datas[0];
		for (i = 1; i < size; i += 2)
		{
			switch (num[i])
			{
			case ' ':
				break;
			case '+':
				sol += datas[j];
				j++;
				break;
			case '-':
				sol -= datas[j];
				j++;
				break;
			default:
				break;
			}
		}
		
		if (sol == 0)
		{
			solutions[N].push_back(num); //���� ���� 0�ϰ�� ���� ����Ʈ�� �߰�.
		}
		return;
	}
	//��� ����� ���� ��������� �˻��Ѵ�.
	int nextn = data + 1;
	string Num1 = num;
	Num1.push_back(n);
	Num1.push_back('+');
	makeSolution(N, Num1,nextn);
	string Num2 = num;
	Num2.push_back(n);
	Num2.push_back('-');
	makeSolution(N, Num2, nextn);
	string Num3 = num;
	Num3.push_back(n);
	Num3.push_back(' ');
	makeSolution(N, Num3, nextn);

	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int Testcase;
	int i;
	int j;
	int* N;
	cin >> Testcase;
	N = new int[Testcase];
	for (i = 0; i < Testcase; i++)
	{
		cin >> N[i];
		if (solutions[N[i]].size() == 0)
		{
			makeSolution(N[i], "", 1);
		}
		
	}
	for (i = 0; i < Testcase; i++)
	{
		sort(solutions[N[i]].begin(), solutions[N[i]].end());
		int solSize = solutions[N[i]].size();
		for (j = 0; j < solSize; j++)
		{
			int size2 = solutions[N[i]][j].size();
			for (int k = 0; k < size2; k += 2)
			{
				printf("%d", solutions[N[i]][j][k]);
				if (k+1 != size2)
				{
					printf("%c", solutions[N[i]][j][k + 1]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	
	return 0;
}
