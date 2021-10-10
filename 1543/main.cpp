#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string inputString;
	string findString;
	getline(cin, inputString);
	getline(cin, findString);
	int a;
	int count = 0;
	int findSize;
	int inputSize;
	int init;
	do
	{
		a = inputString.find(findString);
		if (a != std::string::npos)
		{
			string temp;
			findSize = findString.size();
			inputSize = inputString.size();
			init = a + findSize;
			for (init; init < inputSize; init++)
			{
				temp.push_back(inputString[init]);
			}
			count++;
			inputString = temp;
		}
		else
		{
			break;
		}
		
	} while (true);
	cout << count;

	return 0;
}