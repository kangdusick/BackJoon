#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n;
	int i = 0;
	int j = 0;
	cin >> n;
	stack<char> leftStack;
	stack<char> rightStack;
	string* log = new string[n];
	char** answer = new char*[n];
	int logSize = 0;
	int leftSize = 0;
	int rightSize = 0;
	for (i = 0; i < n; i++)
	{
		cin >> log[i];
	}

	for (i = 0; i < n; i++)
	{
		logSize = log[i].size();
		for (j = 0; j < logSize; j++)
		{
			switch (log[i][j])
			{
			case '<':
				if (leftStack.size() == 0)
				{
					break;
				}
				rightStack.push(leftStack.top());
				leftStack.pop();
				break;
			case '>':
				if (rightStack.size() == 0)
				{
					break;
				}
				leftStack.push(rightStack.top());
				rightStack.pop();
				break;
			case '-':
				if (leftStack.size() == 0)
				{
					break;
				}
				leftStack.pop();
				break;
			default:
				leftStack.push(log[i][j]);
				break;
			}
		}
		rightSize = rightStack.size();
		leftSize = leftStack.size();
		int totalSize = rightSize + leftSize;
		answer[i] = new char[totalSize+1];
		answer[i][totalSize] = '\0';
		for (j = leftSize; j < totalSize; j++)
		{
			answer[i][j] = rightStack.top();
			rightStack.pop();
		}
		for (j = 0; j < leftSize; j++)
		{
			answer[i][leftSize - j - 1] = leftStack.top();
			leftStack.pop();
		}
		
	}
	for (i = 0; i < n; i++)
	{
		printf("%s\n", answer[i]);
	}
	return 0;
}